#include <iostream>
#include <cmath>
#include "Vektor.h"
#include "RitkaVektor.h"
using namespace std;
int main()
{
	int elso[3] = { 1,2,3 };
	int masodik[3] = { 4,0,6 };
	Vektor<int> uj1(elso, 3), uj2(masodik,3);
	RitkaVektor<int>uj3(elso, 3), uj4(masodik, 3);
	double s;
	try
	{
		(uj1 + uj2).kiir();
		uj1 = uj1 - uj2;
		(uj1 - uj2).kiir();
		s = uj1 % uj2;
		cout << "tavolsag : "<<s << endl;
		s = ~uj1;
		cout << "norma:" << s << endl;
		cout << "egy elem:" << uj1[1] << endl;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		(uj3 + uj4).kiir();
		uj3 = uj3 - uj4;
		uj3.kiir();
		s = uj3 % uj4;
		cout << "tavolsag : " << s << endl;
		s = ~uj3;
		cout << "norma:" << s << endl;
		cout << "egy elem:" << uj3[0] << endl;
	}
	catch (const char* x)
	{
		cout << x << endl;
	}
}