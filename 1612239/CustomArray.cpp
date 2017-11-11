#include "CustomArray.h"

template<class T>
int CustomArray<T>::rightReserveSize()
{
	return this->m_pUpperBound - this->m_pEnd;
}

template<class T>
int CustomArray<T>::rightReserveSize() const
{
	return this->m_pUpperBound - this->m_pEnd;
}

template<class T>
CustomArray<T>::CustomArray()
{
	this->m_n = 0;
	this->m_pLowerBound = NULL;
	this->m_pBegin = NULL;
	this->m_pEnd = NULL;
	this->m_pUpperBound = NULL;
}

template<class T>
CustomArray<T>::CustomArray(int n)
{
	this->m_n = n;
	this->m_pLowerBound = new T[3 * this->m_n];
	this->m_pBegin = m_pLowerBound + this->m_n;
	this->m_pEnd = m_pLowerBound + 2 * this->m_n;
	this->m_pUpperBound = m_pLowerBound + (3 * this->m_n - 1);
}

template<class T>
CustomArray<T>::CustomArray(const CustomArray & a)
{
	this->m_n = a.m_n;
	this->m_pLowerBound = new T[a.realSize()];
	this->m_pBegin = this->m_pLowerBound + a.leftReserveSize();
	this->m_pEnd = this->m_pBegin + this->m_n;
	this->m_pUpperBound = this->m_pLowerBound + a.realSize();
	T *pBegin = m_pBegin;
	T *qBegin = a.m_pBegin;
	for (; pBegin != m_pEnd; pBegin++, qBegin++)
	{
		*pBegin = *qBegin;
	}
}

template<class T>
CustomArray<T>::CustomArray(int n, T val)
{
	this->m_n = n;
	this->m_pLowerBound = new T[3 * this->m_n];
	this->m_pBegin = this->m_pLowerBound + this->m_n;
	this->m_pEnd = m_pLowerBound + 2 * this->m_n;
	this->m_pUpperBound = this->m_pLowerBound + (3 * this->m_n - 1);
	T *pBegin = this->m_pBegin;
	for (; pBegin != this->m_pEnd; pBegin++)
		*pBegin = val;
}

template<class T>
int CustomArray<T>::size()
{
	return (this->m_pEnd - this->m_pBegin);
}

template<class T>
int CustomArray<T>::size() const
{
	return (this->m_pEnd - this->m_pBegin);
}

template<class T>
void CustomArray<T>::operator=(const CustomArray & a)
{
	if (a.empty())
		return;
	this->m_n = a.m_n;
	//neu mang ban dau khac NULL
	if (this->m_pLowerBound != NULL)
		delete[] m_pLowerBound;
	//cap phat lai mang voi kich thuoc that cua mang duoc gan
	this->m_pLowerBound = new T[a.realSize()];
	this->m_pBegin = this->m_pLowerBound + a.leftReserveSize();
	this->m_pEnd = this->m_pBegin + a.m_n;
	this->m_pUpperBound = this->m_pLowerBound + a.realSize();
	T *pBegin = this->m_pBegin;
	T *aBegin = a.m_pBegin;
	for (; pBegin != this->m_pEnd; pBegin++, aBegin++)
		*pBegin = *aBegin;
}

template<class T>
T& CustomArray<T>::operator[](int n)
{
	return *(this->m_pBegin + n);
}

template<class T>
T& CustomArray<T>::operator[](int n) const
{
	return *(this->m_pBegin + n);
}

template<class T>
T * CustomArray<T>::begin()
{
	return this->m_pBegin;
}

template<class T>
T * CustomArray<T>::end()
{
	return this->m_pEnd;
}

template<class T>
void CustomArray<T>::clear()
{
	this->m_pBegin = NULL;
	this->m_pEnd = NULL;
	this->m_pUpperBound = NULL;
	this->m_n = 0;
	if (this->m_pLowerBound != NULL)
		delete[] this->m_pLowerBound;
	m_pLowerBound = NULL;
}

template<class T>
bool CustomArray<T>::empty()
{
	return this->m_pLowerBound == NULL;
}

template<class T>
bool CustomArray<T>::empty() const
{
	return this->m_pLowerBound == NULL;
}

template<class T>
void CustomArray<T>::resize(int n)
{
	//tao 1 mang tam luu gia tri
	T *arrTemp = new T[this->m_n];
	//gan gia tri cua mang ra mot mang tam
	int i;
	T *pBegin = this->m_pBegin;
	for (i = 0; pBegin != this->m_pEnd; pBegin++, i++)
		*(arrTemp + i) = *pBegin;
	//xoa vung nho cu
	if (this->m_pLowerBound != NULL)
		delete[] this->m_pLowerBound;
	//cap phat lai kich thuoc moi
	this->m_n = n;
	this->m_pLowerBound = new T[3 * this->m_n];
	this->m_pBegin = m_pLowerBound + n;
	this->m_pEnd = m_pLowerBound + 2 * n;
	this->m_pUpperBound = m_pLowerBound + (3 * n - 1);
	//gan tri tu mang tam tro lai
	///////////////////////////////////////////////////////////
	pBegin = this->m_pBegin;
	//neu kich thuoc moi nho nhon kich thuoc ban dau
	if (n < i)//i la kich thuoc mang tam
	{
		for (i = 0; pBegin != this->m_pEnd; pBegin++, i++)
		{
			*pBegin = *(arrTemp + i);
		}
	}
	else
	{
		for (int k = 0; k < i; k++, pBegin++)
			*pBegin = *(arrTemp + k);
	}
	///////////////////////////////////////////////////////////////
	//hoan tat gan gia tri tu mang tam
	//xoa mang tam
	delete[] arrTemp;
}

template<class T>
int CustomArray<T>::adjust()
{
	int distance;
	//kich thuoc phan du tru ben phai het
	if (rightReserveSize() == 0)
	{
		//lay khoang cach can dich
		distance = leftReserveSize() / 2 + 1;
		//vi tri moi cua con tro begin va end
		distance = -distance;
		this->m_pBegin += distance;
		this->m_pEnd += distance;
		//tien hanh dich chuyen
		T *pBegin = this->m_pBegin;
		for (; pBegin != this->m_pEnd; pBegin++)
		{
			*pBegin = *(pBegin - distance);
		}
		//hoan tat dich chuyen
	}
	//kich thuoc phan du tru ben trai het
	else if (leftReserveSize() == 0)
	{
		//lay khoang cach can dich
		distance = rightReserveSize() / 2 + 1;
		//vi tri moi cua con tro begin va end
		this->m_pBegin += distance;
		this->m_pEnd += distance;
		//lay vi tri cua phan tu cuoi cung
		T *pPreEnd = this->m_pEnd;
		//tien hanh dich chuyen
		for (; pPreEnd != this->m_pBegin - 1; pPreEnd--)
		{
			*pPreEnd = *(pPreEnd - distance);

		}
		//hoan tat dich chuyen
	}
	return distance;
}

template<class T>
void CustomArray<T>::push_back(T val)
{
	//neu mang NULL
	if (this->m_pLowerBound == NULL)
	{
		resize(1);
		*this->m_pBegin = val;
		return;
	}
	//neu phan du tru ben phai con trong
	if (rightReserveSize() != 0)
	{
		*this->m_pEnd = val;
		this->m_pEnd++;
	}
	//phan du trai ben phai het
	else
	{
		//phan du tru ben trai con
		if (leftReserveSize() != 0)
		{
			//tien hanh can chinh
			adjust();
			//them val vao cuoi
			*this->m_pEnd = val;
			this->m_pEnd++;
		}
		//phan du tru ben trai va phai deu het
		else
		{
			//cap phat lai vung nho moi
			resize(size());
			*this->m_pEnd = val;
			this->m_pEnd++;
		}
	}
	this->m_n++;
}

template<class T>
void CustomArray<T>::push_front(T val)
{
	//neu mang NULL
	if (this->m_pLowerBound == NULL)
	{
		resize(1);
		*this->m_pBegin = val;
		return;
	}
	//neu phan du tru ben trai con trong
	if (leftReserveSize() != 0)
	{
		this->m_pBegin--;
		*this->m_pBegin = val;
	}
	//phan du trai ben trai het
	else
	{
		//phan du tru ben phai con
		if (rightReserveSize() != 0)
		{
			//tien hanh can chinh
			adjust();
			//them val vao cuoi
			this->m_pBegin--;
			*this->m_pBegin = val;
		}
		//phan du tru ben trai va phai deu het
		{
			//tang kich thuoc cua mang
			resize(size());
			this->m_pBegin--;
			*this->m_pBegin = val;
		}
	}
	this->m_n++;
}

template<class T>
T CustomArray<T>::pop_back()
{
	
	T val = *(this->m_pEnd - 1);
	this->m_pEnd--;
	this->m_n--;
	if (this->m_n == 0)
	{
		this->clear();
		return val;
	}
	return val;
}

template<class T>
T CustomArray<T>::pop_front()
{
	this->m_n--;
	if (this->m_n == 0)
	{
		T pop = *this->m_pBegin;
		this->clear();
		return pop;
	}
	return *(this->m_pBegin++);
}

template<class T>
void CustomArray<T>::insert(T val, T *p)
{
	//neu mang bang NULL thi khong lam gia ca
	if (this->m_pLowerBound == NULL)
		return;
	//lay vi tri giua
	int mid = this->m_n / 2;
	//con tro giu tri cua pos
	int pos = p - this->m_pBegin;
	//vi tri o phia ben phai cua mid
	if (pos > mid)
	{
		//phan du tru ben phai con
		if (rightReserveSize() != 0)
		{
			//tien hanh chen vao phia sau
			///////////////////////////////////////////
			//doi phan tu phia sau p sang phai 1 vi tri
			T *pEnd = this->m_pEnd;
			for (; pEnd != p; pEnd--)
				*(pEnd + 1) = *pEnd;
			//gan gia tri vao sau p
			*(p + 1) = val;
			//doi con tro end sang phai 1 vi tri
			this->m_pEnd++;
			///////////////////////////////////////////
		}
		//phan du tru ben phai het
		else
		{
			//phan du tru ben trai con
			if (leftReserveSize() != 0)
			{
				//can chinh phan luu tru va con tro p ve giua 
				p += adjust();
				//tien hanh chen vao phia sau
				///////////////////////////////////////////
				//doi phan tu phia sau p sang phai 1 vi tri
				T *pEnd = this->m_pEnd;
				for (; pEnd != p; pEnd--)
					*(pEnd + 1) = *pEnd;
				//gan gia tri vao sau p
				*(p + 1) = val;
				//doi con tro end sang phai 1 vi tri
				this->m_pEnd++;
				///////////////////////////////////////////
			}
			//phan du tru ben trai het
			{
				//cap phat lai vung nho moi
				resize(size());
				//cho con tro p tro toi vung nho moi
				p = this->m_pBegin + pos;
				//tien hanh chen vao phia sau
				///////////////////////////////////////////
				//doi phan tu phia sau p sang phai 1 vi tri
				T *pEnd = this->m_pEnd;
				for (; pEnd != p; pEnd--)
					*(pEnd + 1) = *pEnd;
				//gan gia tri vao sau p
				*(p + 1) = val;
				//doi con tro end sang phai 1 vi tri
				this->m_pEnd++;
				///////////////////////////////////////////
			}
		}
	}
	//vi tri can chen o phia truoc hoac bang mid
	else
	{
		//phan du tru ben trai con
		if (leftReserveSize() != 0)
		{
			//tien hanh chen vao ngay tai vi tri p
			///////////////////////////////////////////
			//doi phan tu tu p tro ve truoc sang trai 1 vi tri
			T *pBegin = this->m_pBegin - 1;
			for (; pBegin != p; pBegin++)
				*(pBegin) = *(pBegin + 1);
			//gan gia tri vao sau p
			*p = val;
			//doi con tro begin sang trai 1 vi tri
			this->m_pBegin--;
			///////////////////////////////////////////
		}
		//phan du tru ben trai het
		else
		{
			//phan du tru ben phai con
			if (rightReserveSize() != 0)
			{
				//can chinh phan luu tru ve giua 
				p += adjust();
				//tien hanh chen vao ngay tai vi tri p
				///////////////////////////////////////////
				//doi phan tu tu p tro ve truoc sang trai 1 vi tri
				T *pBegin = this->m_pBegin - 1;
				for (; pBegin != p; pBegin++)
					*(pBegin) = *(pBegin + 1);
				//gan gia tri vao  p
				*p = val;
				//doi con tro begin sang trai 1 vi tri
				this->m_pBegin--;
				///////////////////////////////////////////
			}
			//phan du tru ben phai het
			else
			{
				//cap phat lai vung nho moi
				resize(size());
				//cho con tro p tro toi vung nho moi
				p = this->m_pBegin + pos;
				//tien hanh chen vao ngay tai vi tri p
				///////////////////////////////////////////
				//doi phan tu phia tu p tro ve truoc sang trai 1 vi tri
				T *pBegin = this->m_pBegin - 1;
				for (; pBegin != p; pBegin++)
					*(pBegin) = *(pBegin + 1);
				//gan gia tri vao p
				*p = val;
				//doi con tro begin sang trai 1 vi tri
				this->m_pBegin--;
				///////////////////////////////////////////
			}
		}
	}
	this->m_n++;
}

template<class T>
int CustomArray<T>::realSize()
{
	return (this->m_pUpperBound - this->m_pLowerBound);
}

template<class T>
int CustomArray<T>::realSize() const
{
	return (this->m_pUpperBound - this->m_pLowerBound);
}

template<class T>
int CustomArray<T>::leftReserveSize()
{
	return this->m_pBegin - this->m_pLowerBound;
}

template<class T>
int CustomArray<T>::leftReserveSize() const
{
	return this->m_pBegin - this->m_pLowerBound;
}

template<class T>
void CustomArray<T>::erase(T *p)
{
	//neu mang chi con 1 phan tu
	if (this->m_n == 1)
		this->clear();
	//p nam ngoai phan luu tru thi khong lam gi ca
	if (p < this->m_pBegin || p >= this->m_pEnd)
		return;
	//lay vi tri giua
	int mid = this->m_n / 2;
	//lay vi tri cua p
	int pos = p - this->m_pBegin;
	//p o nua sau phan luu tru
	if (mid < pos)
	{
		//tien hanh doi cac phan tu sau p sang trai 1 vi tri
		T *pBegin = p;
		for (; pBegin != this->m_pEnd - 1; pBegin++)
		{
			*pBegin = *(pBegin + 1);
		}
		//hoan tat doi
		this->m_pEnd--;
	}
	//p o nua truoc phan luu tru
	else
	{
		//tien hanh doi cac phan tu truoc p sang phai 1 vi tri
		T *pEnd = p;
		for (; pEnd != this->m_pBegin; pEnd--)
		{
			*pEnd = *(pEnd - 1);
		}
		//hoan tat doi
		this->m_pBegin++;
	}
	this->m_n--;
}

template<class T>
void CustomArray<T>::input(istream &is)
{
	if (this->m_n == 0)
	{
		cout << "Nhap so phan tu: ";
		is >> this->m_n;
		this->m_pLowerBound = new T[3 * this->m_n];
		this->m_pBegin = m_pLowerBound + this->m_n;
		this->m_pEnd = m_pLowerBound + 2 * this->m_n;
		this->m_pUpperBound = m_pLowerBound + (3 * this->m_n - 1);
	}
	T *pBegin = this->m_pBegin;
	for (; pBegin != this->m_pEnd; pBegin++)
	{
		is >> *pBegin;
	}
}

template<class T>
void CustomArray<T>::output(ostream &os)
{
	for (T *p = this->m_pBegin; p != this->m_pEnd; p++)
	{
		os << *p << " ";
	}
	os << endl;
}

template<class T>
CustomArray<T>::~CustomArray()
{
	this->m_pBegin = NULL;
	this->m_pEnd = NULL;
	this->m_pUpperBound = NULL;
	this->m_n = 0;
	if (this->m_pLowerBound != NULL)
		delete[] this->m_pLowerBound;
	this->m_pLowerBound = NULL;
}
template class CustomArray <int>;
template class CustomArray <Monomial>;