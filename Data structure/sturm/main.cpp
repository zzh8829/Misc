#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
#define	 	MAX_ORDER  		101	
#define	  	RELERROR	  		1.0e-12
#define	  	MAXPOW	    	101		
#define	  	MAXIT	     	10000		
#define	  	SMALL_ENOUGH		1.0e-5

typedef  	struct	p {
		     int	ord;
		     double	coef[MAX_ORDER];
} poly;

int modrf(int ord, double* coef, double a,double b,double* val);
void sbisect(int np,poly *sseq,double min,double max,int atmin, int atmax,double *roots);
int numroots(int np, poly* sseq, int* atneg, int* atpos);
int numchanges(int np,poly *sseq,double a);
int buildsturm(int ord, poly* sseq);
double evalpoly (int ord,double *coef,double x);
int modp(poly *u, poly* v, poly* r);

poly	sseq[MAX_ORDER];

int main()
{	
	double 	min, max, roots[MAX_ORDER];
	int		i, j, order, nroots, nchanges, np, atmin, atmax;

	/*
	 * get the details...
	 */
	order = 0;
	int input;
	scanf("%d", &input);
	double coe;
	int pow;
	for (i = 0; i !=input; i++) {
			cin >> coe >> pow;
			sseq[0].coef[pow] = coe;
			if(!order)
			order = pow;
	}
	for(i = 0;i != order+1;i++) {
		if(!sseq[0].coef[i])
			sseq[0].coef[i]=0.0;
	}
	/*
	 * build the Sturm sequence
	 */
	np = buildsturm(order, sseq);
	/* 
	 * get the number of real roots
	 */
	nroots = numroots(np, sseq, &atmin, &atmax);

	if (nroots == 0) {
			printf("NO REAL ROOTS\n");
			system("pause");
			exit(0);
	}

	/*
	 * calculate the bracket that the roots live in
	 */
	min = -1.0;
	nchanges = numchanges(np, sseq, min);
	for (i = 0; nchanges != atmin && i != MAXPOW; i++) { 
			min *= 10.0;
			nchanges = numchanges(np, sseq, min);
	}

	if (nchanges != atmin) {
			printf("solve: unable to bracket all negative roots\n");
			atmin = nchanges;
	}

	max = 1.0;
	nchanges = numchanges(np, sseq, max);
	for (i = 0; nchanges != atmax && i != MAXPOW; i++) { 
			max *= 10.0;
			nchanges = numchanges(np, sseq, max);
	}

	if (nchanges != atmax) {
			printf("solve: unable to bracket all positive roots\n");
			atmax = nchanges;
	}

	nroots = atmin - atmax;

	/*
	 * perform the bisection.
	 */
	sbisect(np, sseq, min, max, atmin, atmax, roots);


	/*
	 * write out the roots...
	 */
	for (i = 0; i != nroots; i++)
		cout << roots[i] << endl;
	system("pause");
	return 0;
}

int modp(poly *u, poly*v, poly*r)
{
	int		k, j;
	double	*nr, *end, *uc;

	nr = r->coef;
	end = &u->coef[u->ord];

	uc = u->coef;
	while (uc <= end)
			*nr++ = *uc++;

	if (v->coef[v->ord] < 0.0) {


			for (k = u->ord - v->ord - 1; k >= 0; k -= 2)
				r->coef[k] = -r->coef[k];

			for (k = u->ord - v->ord; k >= 0; k--)
				for (j = v->ord + k - 1; j >= k; j--)
					r->coef[j] = -r->coef[j] - r->coef[v->ord + k]
					* v->coef[j - k];
	} else {
			for (k = u->ord - v->ord; k >= 0; k--)
				for (j = v->ord + k - 1; j >= k; j--)
				r->coef[j] -= r->coef[v->ord + k] * v->coef[j - k];
	}

	k = v->ord - 1;
	while (k >= 0 && fabs(r->coef[k]) < SMALL_ENOUGH) {
		r->coef[k] = 0.0;
		k--;
	}

	r->ord = (k < 0) ? 0 : k;

	return(r->ord);
}

/*
 * buildsturm
 *
 *	build up a sturm sequence for a polynomial in smat, returning
 * the number of polynomials in the sequence
 */
int buildsturm(int ord, poly* sseq)
{
	int		i;
	double	f, *fp, *fc;
	poly	*sp;

	sseq[0].ord = ord;
	sseq[1].ord = ord - 1;


	/*
	 * calculate the derivative and normalise the leading
	 * coefficient.
	 */
	f = fabs(sseq[0].coef[ord] * ord);
	fp = sseq[1].coef;
	fc = sseq[0].coef + 1;
	for (i = 1; i <= ord; i++)
			*fp++ = *fc++ * i / f;

	/*
	 * construct the rest of the Sturm sequence
	 */
	for (sp = sseq + 2; modp(sp - 2, sp - 1, sp); sp++) {

		/*
		 * reverse the sign and normalise
		 */
		f = -fabs(sp->coef[sp->ord]);
		for (fp = &sp->coef[sp->ord]; fp >= sp->coef; fp--)
				*fp /= f;
	}

	sp->coef[0] = -sp->coef[0];	/* reverse the sign */

	return(sp - sseq);
}

int numroots(int np, poly* sseq, int* atneg, int* atpos)
{
		int		atposinf, atneginf;
		poly	*s;
		double	f, lf;

		atposinf = atneginf = 0;


	/*
	 * changes at positive infinity
	 */
	lf = sseq[0].coef[sseq[0].ord];

	for (s = sseq + 1; s <= sseq + np; s++) {
			f = s->coef[s->ord];
			if (lf == 0.0 || lf * f < 0)
				atposinf++;
		lf = f;
	}

	/*
	 * changes at negative infinity
	 */
	if (sseq[0].ord & 1)
			lf = -sseq[0].coef[sseq[0].ord];
	else
			lf = sseq[0].coef[sseq[0].ord];

	for (s = sseq + 1; s <= sseq + np; s++) {
			if (s->ord & 1)
				f = -s->coef[s->ord];
			else
				f = s->coef[s->ord];
			if (lf == 0.0 || lf * f < 0)
				atneginf++;
			lf = f;
	}

	*atneg = atneginf;
	*atpos = atposinf;

	return(atneginf - atposinf);
}

/*
 * numchanges
 *
 *	return the number of sign changes in the Sturm sequence in
 * sseq at the value a.
 */
int numchanges(int np,poly *sseq,double a)
{
	int		changes;
	double	f, lf;
	poly	*s;

	changes = 0;

	lf = evalpoly(sseq[0].ord, sseq[0].coef, a);

	for (s = sseq + 1; s <= sseq + np; s++) {
			f = evalpoly(s->ord, s->coef, a);
			if (lf == 0.0 || lf * f < 0)
				changes++;
			lf = f;
	}

	return(changes);
}

/*
 * sbisect
 *
 *	uses a bisection based on the sturm sequence for the polynomial
 * described in sseq to isolate intervals in which roots occur,
 * the roots are returned in the roots array in order of magnitude.
 */
void sbisect(int np,poly *sseq,double min,double max,int atmin,int atmax,double *roots)
{
	double	mid;
	int		n1 = 0, n2 = 0, its, atmid, nroot;

	if ((nroot = atmin - atmax) == 1) {

		/*
		 * first try a less expensive technique.
		 */
		if (modrf(sseq->ord, sseq->coef, min, max, &roots[0]))
			return;


		/*
		 * if we get here we have to evaluate the root the hard
		 * way by using the Sturm sequence.
		 */
		for (its = 0; its < MAXIT; its++) {
				mid = (min + max) / 2;

				atmid = numchanges(np, sseq, mid);

				if (fabs(mid) > RELERROR) {
					if (fabs((max - min) / mid) < RELERROR) {
						roots[0] = mid;
						return;
					}
				} else if (fabs(max - min) < RELERROR) {
					roots[0] = mid;
					return;
				}

				if ((atmin - atmid) == 0)
					min = mid;
				else
					max = mid;
			}

		if (its == MAXIT) {
				fprintf(stderr, "sbisect: overflow min %f max %f\
					diff %e nroot %d n1 %d n2 %d\n",
					min, max, max - min, nroot, n1, n2);
			roots[0] = mid;
		}

		return;
	}

	/*
	 * more than one root in the interval, we have to bisect...
	 */
	for (its = 0; its < MAXIT; its++) {

			mid = (min + max) / 2;

			atmid = numchanges(np, sseq, mid);

			n1 = atmin - atmid;
			n2 = atmid - atmax;


			if (n1 != 0 && n2 != 0) {
				sbisect(np, sseq, min, mid, atmin, atmid, roots);
				sbisect(np, sseq, mid, max, atmid, atmax, &roots[n1]);
				break;
			}

			if (n1 == 0)
				min = mid;
			else
				max = mid;
	}

	if (its == MAXIT) {
			fprintf(stderr, "sbisect: roots too close together\n");
			fprintf(stderr, "sbisect: overflow min %f max %f diff %e\
				nroot %d n1 %d n2 %d\n",
				min, max, max - min, nroot, n1, n2);
			for (n1 = atmax; n1 < atmin; n1++)
			roots[n1 - atmax] = mid;
	}
}

double evalpoly (int ord,double *coef,double x)
{
	double	*fp, f;

	fp = &coef[ord];
	f = *fp;

	for (fp--; fp >= coef; fp--)
	f = x * f + *fp;

	return(f);
}


/*
 * modrf
 *
 *	uses the modified regula-falsi method to evaluate the root
 * in interval [a,b] of the polynomial described in coef. The
 * root is returned is returned in *val. The routine returns zero
 * if it can't converge.
 */
int modrf(int ord, double* coef, double a,double b,double* val)
{
	int		its;
	double	fa, fb, x, fx, lfx;
	double	*fp, *scoef, *ecoef;

	scoef = coef;
	ecoef = &coef[ord];

	fb = fa = *ecoef;
	for (fp = ecoef - 1; fp >= scoef; fp--) {
		fa = a * fa + *fp;
		fb = b * fb + *fp;
	}

	/*
	 * if there is no sign difference the method won't work
	 */
	if (fa * fb > 0.0)
		return(0);

	if (fabs(fa) < RELERROR) {
		*val = a;
		return(1);
	}

	if (fabs(fb) < RELERROR) {
		*val = b;
		return(1);
	}

	lfx = fa;


	for (its = 0; its < MAXIT; its++) {

		x = (fb * a - fa * b) / (fb - fa);

		fx = *ecoef;
		for (fp = ecoef - 1; fp >= scoef; fp--)
				fx = x * fx + *fp;

		if (fabs(x) > RELERROR) {
				if (fabs(fx / x) < RELERROR) {
					*val = x;
					return(1);
				}
		} else if (fabs(fx) < RELERROR) {
				*val = x;
				return(1);
		}

		if ((fa * fx) < 0) {
				b = x;
				fb = fx;
				if ((lfx * fx) > 0)
					fa /= 2;
		} else {
				a = x;
				fa = fx;
				if ((lfx * fx) > 0)
					fb /= 2;
		}

		lfx = fx;
	}

	fprintf(stderr, "modrf overflow %f %f %f\n", a, b, fx);

	return(0);
}
	


