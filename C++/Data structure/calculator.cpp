/****************************************
* A normal console calculator program. *
* Use recursion downward design(LL1). *
*--------------------------------------*
* E ---> TE  *
* E  ---> +TE  | -TE  | 0 *
* T ---> FT  *
* T  ---> *FT  | /FT  | 0 *
* F ---> (E) | NUM *
* *************************************/

#include <stdio.h>
#include <string.h>

#define N 30 /* Allocation space for express */
#define PLUS 0
#define SUBT 1
#define MULT 2
#define DIVI 3
#define NUM 4
#define LBRK 5
#define RBRK 6
#define END 7
#define OTHER 8

int err;
int pCur;
int TOKEN;
char Get str[N]; /* save express */
double T value;

int parser(void); /* A function for syntax analysis */
void Match(void); /* read token */
double E(void); /* figure plus and sub */
double E_(void); /* sub faction of E */
double T(void); /* figure mult and divi */
double T_(void); /* sub faction of T */
double F(void); /* read value and analyse resursion */

int main(int argc, char *argv[]) /* contain command mode */
{
	if (argc == 2) {
		strcpy(Get str, argv[1]);
		Match(); /* initialize value */
		printf("The result is: %lf\n\n", E());
	}
	else {
		printf("Enter a express:\n");
		whilE_(!err) { /* iterate condition */
			scanf("%s", Get str);
			Match(); /* initialize value */
			printf("%s%lf%s\n",
			"The result is: ", E(),
			"\n Input express continue, "
			"and input any letter Exit.\n");
			T value = pCur = 0; /* initialisation */
		}
		printf("ERROR: Contain undefinition charactor - bye!\n\n");
	}

	getchar();

	return 0;
}

//Read a token

void Match(void)
{
	TOKEN = parser();
}

//analyse express

int parser(void)
{
	int cnt = 0;
	char Tmp[N];

	whilE_(Get str[pCur] == ' ')
	pCur++;
	whilE_(Get str[pCur] >= '0' && Get str[pCur] <= '9' || Get str[pCur] == '.')
	Tmp[cnt++] = Get str[pCur++];
	if (cnt) {
		sscanf(Tmp, "%lf", &T value);
		return NUM;
	}
	switch (Get str[pCur++]) {
	case '+' : return PLUS;
	case '-' : return SUBT;
	case '*' : return MULT;
	case '/' : return DIVI;
	case '(' : return LBRK;
	case ')' : return RBRK;
	case '\0' : return END;
		default : return OTHER;
	}
}

//E-->TE'

double E(void)
{
	switch (TOKEN) {
	case LBRK :
	case NUM :
		return T() + E_();
	case END : return F();
		default : err = 1; return -1;
	}
}

//E-->+TE' | -TE' | empty

double E_(void)
{
	switch(TOKEN) {
	case PLUS :
		Match();
		return T() + E_();
	case SUBT :
		Match();
		return -(T() - E_());
	case RBRK :
	case END :
		return 0;
		default : err = 1; return -1;
	}
}

//T-->TE'

double T(void)
{
	switch(TOKEN) {
	case LBRK :
	case NUM :
		return F() * T_();
		default : err = 1; return -1;
	}
}

//T'-->*FT' | /FT' | empty

double T_(void)
{
	switch(TOKEN) {
	case MULT :
		Match();
		return F() * T_();
	case DIVI :
		Match();
		return 1 / (F() / T_());
	case PLUS :
	case SUBT :
	case RBRK :
	case END:
		return 1;
		default : err = 1; return -1;
	}
}

//E-->E | value

double F(void)
{
	double Tmp;

	switch(TOKEN) {
	case LBRK :
		Match();
		Tmp = E();
		Match();
		return Tmp;
	case NUM :
		Tmp = T value;
		Match();
		return Tmp;
		default : err = 1; return -1;
	}
}