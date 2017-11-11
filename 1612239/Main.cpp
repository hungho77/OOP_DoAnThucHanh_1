#include<iostream>
#include<fstream>
#include<string>
#include"CustomArray.h"
#include"Monomial.h"
#include"Polynomial.h"
using namespace std;

void main(int argc, char *argv[])
{
	argc = 3;
	//tao doi tuong thuoc lop ifstream
	ifstream inputFile;
	//mo file de doc du lieu
	inputFile.open(argv[1]);
	//tao doi tuong thuoc lop ofstream
	ofstream outputFile;
	//mo file de ghi du lieu
	outputFile.open(argv[2]);
	if (inputFile.is_open() && outputFile.is_open())
	{
		//neu cuoi file input thi dung
		while (!inputFile.eof())
		{
			string choose;
			getline(inputFile, choose, '(');
			string strf1, strf2;
			getline(inputFile, strf1, ',');
			getline(inputFile, strf2, ')');
			Polynomial f1(strf1);
			Polynomial f2(strf2);
			if (choose == "add")
			{
				Polynomial f3 = f1 + f2;
				f3.output(outputFile);
			}
			if (choose == "sub")
			{
				Polynomial f3 = f1 - f2;
				f3.output(outputFile);
			}
			if (choose == "mul")
			{
				Polynomial f3 = f1 * f2;
				f3.output(outputFile);
			}
			if (choose == "div")
			{
				if (f2.getMonomial(0).getA() == 0 && f2.getMonomial(0).getN() == 1)
				{
					outputFile << "Math Error" << endl;
					inputFile.ignore();
					continue;
				}
				Polynomial f3 = f1 / f2;
				f3.output(outputFile);
			}
			if (choose == "mod")
			{
				if (f2.getMonomial(0).getA() == 0 && f2.getMonomial(0).getN() == 1)
				{
					outputFile << "Math Error" << endl;
					inputFile.ignore();
					continue;
				}
				Polynomial f3 = f1 % f2;
				f3.output(outputFile);
			}
			inputFile.ignore();
		}
	}
}