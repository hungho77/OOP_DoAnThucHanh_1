#pragma once
#include"CustomArray.h"
#include"Monomial.h"
#include<iostream>
using namespace std;

class Polynomial
{
	CustomArray<Monomial> m_fx;
public:
	//khoi tao mac dinh
	Polynomial();
	//khoi tao voi mang don thuc
	Polynomial(Monomial *a, int n);
	//khoi tao voi chuoi da thuc
	Polynomial(string strFx);
	//tao lap sao chep
	Polynomial(const Polynomial	&f);
	//phuong thuc xuat
	void output(ostream &os);
	//lay 1 don thuc tai vi tri i
	Monomial getMonomial(int i);
	Monomial getMonomial(int i) const;
	//toan tu gan
	void operator = (const Polynomial &f);
	//toan tu + - * / %
	//-----------------------------------------//
	Polynomial operator +(const Polynomial &f);
	Polynomial operator -(const Polynomial &f);
	Polynomial operator *(const Polynomial &f);
	Polynomial operator /(const Polynomial &f);
	Polynomial operator %(const Polynomial &f);
	//-----------------------------------------//
	~Polynomial();
};

