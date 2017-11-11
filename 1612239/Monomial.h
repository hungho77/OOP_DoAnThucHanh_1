#pragma once
#include<iostream>
#include"CustomArray.h"
using namespace std;

class Monomial
{
	//he so
	double m_a;
	//so mu n >= 0
	int m_n;
public:
	Monomial();
	Monomial(double a, int n);
	Monomial(const Monomial &fx);
	void operator = (const Monomial &fx);
	Monomial operator * (const Monomial &fx);
	Monomial operator /(const Monomial &fx);
	void setA(double a);
	void setN(int n);
	double getA();
	int getN();
	friend istream &operator >> (istream &is, Monomial &fx);
	friend ostream &operator << (ostream &os, const Monomial &fx);
	~Monomial();
};

