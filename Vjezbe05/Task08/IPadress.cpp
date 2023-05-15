#include "IPadress.h"

IPadress::IPadress(int a, int b, int c, int d)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}

char IPadress::which()
{
	if (a <= 127) return 'A';
	else if (a <= 191) return 'B';
	else if (a <= 223) return 'C';
	else if (a <= 239) return 'D';
	else if (a <= 255) return 'E';
	else return '?';
}
