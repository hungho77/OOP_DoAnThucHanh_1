#pragma once
#include<iostream>
#include"Monomial.h"
using namespace std;
template <class T>
class CustomArray
{
	int m_n;
	T *m_pLowerBound;
	T *m_pBegin;
	T *m_pEnd;
	T *m_pUpperBound;
	//lay kich thuoc that su cua mang
	int realSize();
	int realSize() const;
	// lay kich thuoc phan du tru ben trai
	int leftReserveSize();
	int leftReserveSize() const;
	//lay kich thuoc phan du tru ben phai
	int rightReserveSize();
	int rightReserveSize() const;
	//can chinh lai phan luu tru ra giua tra ve khoang cach da dich chuyen
	int adjust();
public:
	CustomArray();
	CustomArray(int n);
	CustomArray(const CustomArray &a);
	CustomArray(int n, T val);
	//lay kich thuoc phan luu tru 
	int size();
	int size() const;
	//toan tu gan
	void operator = (const CustomArray &a);
	//---------------------//
	//toan tu lay gia tri 1 phan tu
	T& operator [] (int n);
	T& operator [] (int n) const;
	//lay con tro begin
	T* begin();
	//lay con tro en
	T* end();
	//xoa mang
	void clear();
	//kiem tra mang co trong hay khong
	bool empty();
	bool empty() const;
	//thay doi kich thuoc mang
	void resize(int n);
	//---------------------//
	//them 1 phan tu o cuoi
	void push_back(T val);
	//them 1 phan tu o dau
	void push_front(T val);
	//lay ra 1 phan tu o cuoi va xoa phan tu do
	T pop_back();
	//lay ra 1 phan tu o dau va xoa phan tu do
	T pop_front();
	//chen phan tu phia sau con tro p dang tro toi
	void insert(T val, T *p);
	//xoa 1 phan tu tai vi tri con tro p dang tro toi
	void erase(T *p);
	//phuong thuc nhap
	void input(istream &is);
	//phuong thuc xuat
	void output(ostream &os);
	~CustomArray();
};

