#include "Monomial.h"



Monomial::Monomial()
{
	this->m_a = 0;
	this->m_n = 0;
}

Monomial::Monomial(double a, int n)
{
	this->m_a = a;
	this->m_n = n;
}

Monomial::Monomial(const Monomial & fx)
{
	this->m_a = fx.m_a;
	this->m_n = fx.m_n;
}

void Monomial::operator=(const Monomial & fx)
{
	this->m_a = fx.m_a;
	this->m_n = fx.m_n;
}

Monomial Monomial::operator*(const Monomial & fx)
{
	Monomial result(*this);
	result.m_a *= fx.m_a;
	result.m_n += fx.m_n;
	return result;
}

Monomial Monomial::operator/(const Monomial & fx)
{
	Monomial result(*this);
	result.m_a /= fx.m_a;
	result.m_n -= fx.m_n;
	return result;
}

void Monomial::setA(double a)
{
	this->m_a = a;
}

void Monomial::setN(int n)
{
	this->m_n = n;
}

double Monomial::getA()
{
	return this->m_a;
}

int Monomial::getN()
{
	return this->m_n;
}


Monomial::~Monomial()
{
}

istream & operator >> (istream & is, Monomial & fx)
{
	cout << "Nhap he so: ";
	is >> fx.m_a;
	cout << "Nhap so mu: ";
	is >> fx.m_n;
	return is;
}

ostream & operator<<(ostream & os, const Monomial & fx)
{
	os << fx.m_a << "x^" << fx.m_n;
	return os;
}
