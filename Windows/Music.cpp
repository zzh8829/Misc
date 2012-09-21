#include <windows.h>

enum yinfu
{
	d1 = 262,
	d1_ = 277,
	d2 = 294,
	d2_ = 311,
	d3 = 330,
	d4 = 349,
	d5 = 392,
	d5_ = 415,
	d6 = 440,
	d6_ = 466,
	d7 = 494,
	z1 = 523,
	z1_ = 554,
	z2 = 578,
	z2_ = 622,
	z3 = 659,
	z4 = 698,
	z4_ = 740,
	z5 = 784,
	z5_ = 831,
	z6 = 880,
	z6_ = 932,
	z7 = 988,
	g1 = 1046,
	g1_ = 1109,
	g2 = 1175,
	g2_ = 1245,
	g3 = 1318,
	g4 = 1397,
	g4_ = 1480,
	g5 = 1568,
	g5_ = 1661,
	g6 = 1760,
	g6_ = 1865,
	g7 = 1976,
	tz = 0
};

struct yinyue
{
	enum yinfu s;
	int t;
};

int main()
{
	int n = 0;
	yinyue a[1000] = 
	{
		{z3, 500}, {z3, 500}, {z4, 500}, {z5, 500},
		{z5, 500}, {z4, 500}, {z3, 500}, {z2, 500},
		{z1, 500}, {z1, 500}, {z2, 500}, {z3, 500},
		{z3, 750}, {z2, 250}, {z2, 1000},
		{z3, 500}, {z3, 500}, {z4, 500}, {z5, 500},
		{z5, 500}, {z4, 500}, {z3, 500}, {z2, 500},
		{z1, 500}, {z1, 500}, {z2, 500}, {z3, 500},
		{z2, 750}, {z1, 250}, {z1, 1000},
		{z2, 500}, {z2, 500}, {z3, 500}, {z1, 500},
		{z2, 500}, {z3, 250}, {z4, 250}, {z3, 500}, {z1, 500},
		{z2, 500}, {z3, 250}, {z4, 250}, {z3, 500}, {z2, 500},
		{z1, 500}, {z2, 500}, {d5, 1000},
		{z3, 500}, {z3, 500}, {z4, 500}, {z5, 500},
		{z5, 500}, {z4, 500}, {z3, 500}, {z2, 500},
		{z1, 500}, {z1, 500}, {z2, 500}, {z3, 500},
		{z2, 750}, {z1, 250}, {z1, 1000}
	};
	yinyue *atop = a;
	n = 70;
	while (n--)
	{
		Beep(atop->s, atop->t);
		atop++;
	}
	return 0;
}
