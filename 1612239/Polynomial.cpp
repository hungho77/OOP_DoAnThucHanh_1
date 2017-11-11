#include "Polynomial.h"



Polynomial::Polynomial()
{

}

Polynomial::Polynomial(Monomial * a, int n)
{
	//sap xep mang don thuc theo so mu giam dan
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].getN() < a[j].getN())
				swap(a[i], a[j]);
		}
	//gan cac gia tri mang don thuc cho da thuc
	for (int i = 0; i < n; i++)
		this->m_fx.push_back(a[i]);
}

Polynomial::Polynomial(string strFx)
{
	//tao 1 don thuc
	Monomial x;
	//lay vi tri cua chuoi con x^ dau tien
	int i;
	i = strFx.find("x^");
	//chuoi tam de luu cac ki tu truoc x^
	string temp;
	//bat dau chuyen gan vao cho da thuc fx
	while (!strFx.empty())
	{
		//so mu
		int N = 0;
		//co so
		double a = 0;
		//gan chuoi con truoc  x^ dau tien trong chuoi tham so cho temp
		//tuc la gan phan chuoi co so cho temp
		temp.assign(strFx, 0, i);
		//chuyen chuoi ki tu temp thanh so gan cho a
		////////////////////////////////
		int pointPos = temp.find('.');
		if (pointPos == -1)
		{
			for (int j = 1; j < i; j++)
			{
				a = a * 10 + temp[j] - 48;
			}
		}
		else
		{
			for (int j = 1; j < pointPos; j++)
			{
				a = a * 10 + temp[j] - 48;
			}
			for (int k = pointPos + 1; k < i; k++)
			{
				a = a + (temp[k] - 48) / pow(10, k - pointPos);
			}
		}
		if (temp[0] == '-')
			a = -a;
		////////////////////////////////
		//xoa chuoi con tu dau den x^ trong chuoi strFX
		strFx.erase(0, i + 2);
		//chuyen phan so mu sau x^ thanh so gan cho N
		//////////////////////////////////////////////////////
		while (int(strFx[0]) > 47 && int(strFx[0]) < 58)
		{
			N = N * 10 + int(strFx[0]) - 48;
			strFx.erase(0, 1);
		}
		/////////////////////////////////////////////////////
		//tim toi vi tri chuoi x^ tiep theo trong chuoi strFx
		i = strFx.find("x^");
		//gan co so va so mu cho don thuc x
		x.setA(a);
		x.setN(N);
		//them don thuc x vao dau da thuc 
		this->m_fx.push_back(x);
		//lam trong chuoi tam
		temp.clear();
	}
}

Polynomial::Polynomial(const Polynomial & f)
{
	this->m_fx = f.m_fx;
}

void Polynomial::output(ostream & os)
{
	int check = 0;
	int i;
	//if (this->m_fx.empty())
	//	os << 0;
	for (i = 0; i < this->m_fx.size(); i++)
	{
		if (this->m_fx[i].getA() > 0)
			os << "+";
		else if (this->m_fx[i].getA() == 0)
		{
			check++;
			continue;
		}		
		os << this->m_fx[i].getA() << "x^" << this->m_fx[i].getN();
	}
	if (check == i)
		os << 0;
	os << endl;
}

Monomial& Polynomial::getMonomial(int i)
{
	return this->m_fx[i];
}

Monomial& Polynomial::getMonomial(int i) const
{
	return this->m_fx[i];
}

void Polynomial::operator=(const Polynomial & f)
{
	this->m_fx = f.m_fx;
}

Polynomial Polynomial::operator+(const Polynomial & f)
{
	//y tuong tuong tu nhu thao tac merge trong mergesort 
	Polynomial fxResult;
	//lay 2 vi tri dau tien trong 2 da thuc
	int i = 0, j = 0;
	//neu chay toi cuoi 1 trong 2 da thuc thi thoat
	while (i < this->m_fx.size() && j < f.m_fx.size())
	{
		//neu bac cua don thuc i trong da thuc thu 1 lon hon trong da thuc thu 2
		if (this->getMonomial(i).getN() > f.getMonomial(j).getN())
		{
			//them don thuc co bac lon hon vao da thuc ket qua
			fxResult.m_fx.push_back(this->getMonomial(i));
			i++;
		}
		//neu bac cua don thuc i trong da thuc thu 1 be hon trong da thuc thu 2
		else if (this->getMonomial(i).getN() < f.getMonomial(j).getN())
		{
			//them don thuc co bac lon hon vao da thuc ket qua
			fxResult.m_fx.push_back(f.getMonomial(j));
			j++;
		}
		//neu bac cua 2 don thuc bang nhau 
		else
		{
			//don thuc tong cua 2 don thuc
			Monomial result;
			//cong 2 don thuc 
			result.setN(this->getMonomial(i).getN());
			result.setA(this->getMonomial(i).getA() + f.getMonomial(j).getA());
			//them don thuc tong vao da thuc ket qua
			fxResult.m_fx.push_back(result);
			i++; j++;
		}
	}
	//neu da thuc thu 1 con don thuc chua duoc them vao tong
	for (i; i < this->m_fx.size(); i++)
		fxResult.m_fx.push_back(this->getMonomial(i));
	//neu da thuc thu 2 con don thuc chua duoc them vao tong
	for (j; j < f.m_fx.size(); j++)
		fxResult.m_fx.push_back(f.getMonomial(j));
	return fxResult;
}

Polynomial Polynomial::operator-(const Polynomial & f)
{
	//y tuong tuong tu nhu thao tac merge trong mergesort 
	Polynomial fxResult;
	//lay 2 vi tri dau tien trong 2 da thuc
	int i = 0, j = 0;
	//neu chay toi cuoi 1 trong 2 da thuc thi thoat
	while (i < this->m_fx.size() && j < f.m_fx.size())
	{
		//neu bac cua don thuc i trong da thuc thu 1 lon hon trong da thuc thu 2
		if (this->getMonomial(i).getN() > f.getMonomial(j).getN())
		{
			//them don thuc co bac lon hon vao da thuc ket qua
			fxResult.m_fx.push_back(this->getMonomial(i));
			i++;
		}
		//neu bac cua don thuc i trong da thuc thu 1 be hon trong da thuc thu 2
		else if (this->getMonomial(i).getN() < f.getMonomial(j).getN())
		{
			//them don thuc co bac lon hon vao da thuc ket qua
			Monomial x(-f.getMonomial(j).getA(), f.getMonomial(j).getN());
			fxResult.m_fx.push_back(x);
			j++;
		}
		//neu bac cua 2 don thuc bang nhau 
		else
		{
			//don thuc hieu cua 2 don thuc
			Monomial result;
			//tru  don thuc trong da thuc 1 cho don thuc trong da thuc 2
			result.setN(this->getMonomial(i).getN());
			result.setA(this->getMonomial(i).getA() - f.getMonomial(j).getA());
			//them don thuc hieu vao da thuc ket qua
			fxResult.m_fx.push_back(result);
			i++; j++;
		}
	}
	//neu da thuc thu 1 con don thuc chua duoc them vao hieu
	for (i; i < this->m_fx.size(); i++)
		fxResult.m_fx.push_back(this->getMonomial(i));
	//neu da thuc thu 2 con don thuc chua duoc them vao hieu
	for (j; j < f.m_fx.size(); j++)
	{
		Monomial x(-f.getMonomial(j).getA(), f.getMonomial(j).getN());
		fxResult.m_fx.push_back(x);
		j++;
	}
	return fxResult;
}

Polynomial Polynomial::operator*(const Polynomial & f)
{
	Polynomial fxResult;
	//cho moi don thuc trong da thuc 1 nhan voi moi don thuc trong da thuc 2
	for (int i = 0; i < this->m_fx.size(); i++)
	{
		//da thuc tam luu gia tri moi lan nhan don thuc i trong da thuc 1 voi da thuc 2
		Polynomial temp;
		//nhan moi don thuc trong da thuc 2 voi don thuc thu i trong da thuc 1
		for (int j = 0; j < f.m_fx.size(); j++)
		{
			//
			temp.m_fx.push_back(this->getMonomial(i)*f.getMonomial(j));

		}
		//tinh tong moi lan nhan voi nhau
		fxResult = fxResult + temp;
	}
	return fxResult;
}

Polynomial Polynomial::operator/(const Polynomial & f)
{
	//da thuc ket qua
	Polynomial fxResult;
	//da thuc du
	Polynomial ftemp(*this);
	int i = 0, j = 0;
	//neu bac cua da thuc du be hon bac cua da thuc bi chia hoac da thuc du con trong
	while (!ftemp.m_fx.empty() && (ftemp.getMonomial(0).getN() >= f.getMonomial(0).getN()))
	{
		//da thuc tam giu thuong cua moi lan chia
		Polynomial tmp;
		//chia don thuc co bac cao nhat cua da thuc chia cho don thuc co bac cao nhat cua da thuc bi chia
		tmp.m_fx.push_back(ftemp.getMonomial(0) / f.getMonomial(0));
		//them thuong vao da thuc ket qua
		fxResult.m_fx.push_back(tmp.getMonomial(0));
		//lay phan du con lai
		////////////////////////////////////////////
		ftemp = ftemp - tmp * f;
		while (!ftemp.m_fx.empty() && ftemp.getMonomial(0).getA() == 0)
		{
			ftemp.m_fx.pop_front();
		}
		//////////////////////////////////////////
		//tiep tuc lay phan du chia tiep cho da thuc chia
	}
	return fxResult;
}

Polynomial Polynomial::operator%(const Polynomial & f)
{
	//tuong tu nhu phep chia nhung ta lay ket qua la phan da thuc du
	Polynomial fxResult;
	Polynomial ftemp(*this);
	int i = 0, j = 0;
	while (!ftemp.m_fx.empty() && (ftemp.getMonomial(0).getN() >= f.getMonomial(0).getN()))
	{
		Polynomial tmp;
		tmp.m_fx.push_back(ftemp.getMonomial(0) / f.getMonomial(0));
		fxResult.m_fx.push_back(tmp.getMonomial(0));
		ftemp = ftemp - tmp * f;
		while (!ftemp.m_fx.empty() && ftemp.getMonomial(0).getA() == 0)
		{
			ftemp.m_fx.pop_front();
		}
	}
	return ftemp;
}

Polynomial::~Polynomial()
{
}
