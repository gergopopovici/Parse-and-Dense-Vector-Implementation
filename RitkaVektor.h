#pragma once
#include "Vektor.h"
#include "cmath"
using namespace std;
template < class T >
struct nonZero
{
	T elem;
	int index;
};
template<class T>
class RitkaVektor
{
public:

	operator Vektor<T>();
	RitkaVektor() {}
	RitkaVektor(int dim);
	RitkaVektor(T* t, int dim);
	RitkaVektor(const RitkaVektor&);
	~RitkaVektor();

	RitkaVektor operator+(const RitkaVektor&);
	RitkaVektor operator-(const RitkaVektor&);
	RitkaVektor& operator=(const RitkaVektor&);
	double operator*(const RitkaVektor&);
	double operator~();
	double operator%(const RitkaVektor&);
	T      operator[](int) const;
	void kiir() const;


private:


	nonZero <T>* vektor;
	int nZeroDim;
	int dim;
};

template <class T>
RitkaVektor<T> ::RitkaVektor(int dim)
{
	this->dim = dim;
	vektor = new nonZero<T>[dim];
	vektor[0].elem = 1;
	vektor[0].index = 0;
	nZeroDim = 1;
}

template <class T>

RitkaVektor<T> ::RitkaVektor(T* t, int dim)
{
	this->dim = dim;
	nZeroDim = 0;
	int j = 0;
	vektor = new nonZero<T>[dim];
	for (int i = 0; i < dim; ++i)
	{
		if(t[i]!=0)
		{
			vektor[j].elem = t[i];
			vektor[j].index = i;
			++j;
			nZeroDim++;
		}
	}
}
template <class T>
RitkaVektor<T>::RitkaVektor(const RitkaVektor<T>& x)
{
	nZeroDim = x.nZeroDim;
	dim = x.dim;
	vektor = new nonZero<T>[dim];
	for (int i = 0; i < nZeroDim; ++i)
	{
		vektor[i].elem = x.vektor[i].elem;
		vektor[i].index = x.vektor[i].index;
	}
}
template <class T>
RitkaVektor<T>::~RitkaVektor()
{
	nZeroDim = 0;
	dim = 0;
	delete[] vektor;
}

template <class T>
void RitkaVektor<T>::kiir()const
{
	for (int i = 0; i < nZeroDim; ++i)
	{
		cout << vektor[i].elem << " " << vektor[i].index << " ";
	}
	cout << endl;
}

template <class T>
RitkaVektor<T>& RitkaVektor<T> :: operator=(const RitkaVektor<T>& a)
{
	if (dim != a.dim)
	{
		throw "A dimenziok nem egyeznek";
	}
	else
	{
		nZeroDim = a.nZeroDim;
		for (int i = 0; i < nZeroDim; ++i)
		{
			vektor[i].elem = a.vektor[i].elem;
			vektor[i].index = a.vektor[i].index;
		}
		return *this;
	}
}

template <class T>
RitkaVektor<T> RitkaVektor<T>:: operator+(const RitkaVektor<T>&a)
{
	if (dim != a.dim)
	{
		throw "A dimenziok nem egyeznek";
	}
	else
	{
		RitkaVektor<T>seged(dim);
		int i = 0, j = 0, k = 0;
		while (i < nZeroDim && j < a.nZeroDim)
		{
			if (vektor[i].index < a.vektor[j].index)
			{
				seged.vektor[k].index = vektor[i].index;
				seged.vektor[k].elem = vektor[i].elem;
				++k;
				++i;

			}
			else if(vektor[i].index > a.vektor[j].index)
			{
				seged.vektor[k].index = a.vektor[j].index;
				seged.vektor[k].elem = a.vektor[j].elem;
				++k;
				++j;
			}
			else
			{
				T aux = 0;
				aux = vektor[i].elem + a.vektor[j].elem;
				seged.vektor[k].elem = aux;
				seged.vektor[k].index = vektor[i].index;
				++k;
				++i;
				++j;
			}
		}
		seged.nZeroDim = k;
		return seged;
	}
}
template <class T>
RitkaVektor<T> RitkaVektor<T> :: operator-(const RitkaVektor<T>& a)
{
	if (dim != a.dim)
	{
		throw "A dimenziok nem egyeznek";
	}
	else
	{
		RitkaVektor<T>seged(dim);
		int i = 0, j = 0, k = 0;
		while (i < nZeroDim && j < a.nZeroDim)
		{
			if (vektor[i].index < a.vektor[j].index)
			{
				seged.vektor[k].index = vektor[i].index;
				seged.vektor[k].elem = vektor[i].elem;
				++k;
				++i;

			}
			else if (vektor[i].index > a.vektor[j].index)
			{
				seged.vektor[k].index = a.vektor[j].index;
				seged.vektor[k].elem = -a.vektor[j].elem;
				++k;
				++j;
			}
			else
			{
				T aux = 0;
				aux = vektor[i].elem - a.vektor[j].elem;
				seged.vektor[k].elem = aux;
				seged.vektor[k].index = vektor[i].index;
				++k;
				++i;
				++j;
			}
		}
		seged.nZeroDim = k;
		return seged;
	}
}

template <class T>
T RitkaVektor<T>::operator[](int i) const
{
	if (i >= dim)
	{
		throw "Nincs ilyen indexu elem";
	}
	else
	{
		if (i >= nZeroDim)
		{
			return 0;
		}
		else
		{
			return vektor[i].elem;
		}
	}
}

template <class T>
double RitkaVektor<T>::operator*(const RitkaVektor&a)
{
	if (dim != a.dim)
	{
		throw "A dimenziok nem egyeznek";
	}
	else
	{
		int i = 0, j = 0;
		double szorzat = 0;
		while (i < nZeroDim && j < a.nZeroDim)
		{
			if (vektor[i].index < a.vektor[j].index)
			{
				++i;
			}
			else if (vektor[i].index > a.vektor[j].index)
			{
				++j;
			}
			else
			{
				szorzat += vektor[i].elem * a.vektor[j].elem;
				++i;
				++j;

			}
		}
		return szorzat;
	}
}
template <class T>
double RitkaVektor<T> :: operator~()
{
	double norma = 0;
	for (int i = 0; i <nZeroDim; ++i)
	{
		norma = norma + (vektor[i].elem * vektor[i].elem);
	}
	return sqrt(norma);
}

template <class T>
double RitkaVektor<T>::operator%(const RitkaVektor& a)
{
	if (dim != a.dim)
	{
		throw "A dimenziok nem egyeznek";
	}
	else
	{
		int i = 0, j = 0;
		double tavolsag = 0;
		while (i < nZeroDim && j < a.nZeroDim)
		{
			if (vektor[i].index < a.vektor[j].index)
			{
				++i;
			}
			else if (vektor[i].index > a.vektor[j].index)
			{
				++j;
			}
			else
			{
				double kivonas = vektor[i].elem - a.vektor[j].elem;
				tavolsag += kivonas * kivonas;
				++i;
				++j;

			}
		}
		return sqrt(tavolsag);
	}
}
template <class T>
RitkaVektor<T>::operator Vektor<T>()
{
	T* seged = new T[dim];
	for (int i = 0; i < dim; ++i)
	{
		seged[i] = 0;
	}
	for (int i = 0; i < nZeroDim; ++i)
	{
		seged[vektor[i].index] = vektor[i].elem;
	}
	Vektor<int>t(seged, dim);
	delete[]seged;
	return t;
}