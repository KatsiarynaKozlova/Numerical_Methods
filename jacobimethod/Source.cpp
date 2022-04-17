#include <iostream>
#include<windows.h>
#include<math.h>
#include<iomanip>
using namespace std;


void OutArray(long double** ar, int str, int st) {
	for (int i = 0; i < str; i++)
	{cout << "\n";
		for (int k = 0; k < st; k++)
		{
			cout <<setw(15) << ar[i][k];
		}
	} 
}

void Diagonal(long double** ar, int str, int st) {
	int count = 0;
	for (int i = 0; i < str; i++)
	{
		int sum = 0;
		for (int k = 0; k < st-1; k++)
		{
			if (i != k) sum += ar[i][k];
		}

		if (ar[i][i] - sum < 0) {
			cout << "Условие преобладания не выполняется"; 
		}
	}
}

void first_step( long double**ar2,long double** ar, int str, int st) {

	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < st-1; j++)
		{
			if (i == j) {
				ar2[i][j] = 0;
			}
			else {
				ar2[i][j] = -(ar[i][j] / ar[i][i]);
			}
		}
	}
	for (int i = 0; i < str; i++)
	{
		ar2[i][st - 1] = ar[i][st - 1] / ar[i][i];
	}
}

double znach(int str, int st, long double**ar, long double*x) {
	double sol = 0;
	for (int i = 0; i < st-1; i++)
	{
		sol = sol + ar[str][i] * x[i];
	}
	sol = sol + ar[str][st - 1];
	return sol;
}

void my(double es, long double**ar2, long double*xtemp, long double*x, int str, int st) {
	int count = 0;
	long double norma=0;
	do {
		norma =0;
		for (int i = 0; i < str; i++)
		{
			xtemp[i] = znach(i, st, ar2, x);
		//	cout <<  " znach " << xtemp[i];
		}
		long double temp;
		for (int i = 0; i < str; i++)
		{
			temp = fabs(xtemp[i] - x[i]);
			if (temp > norma) norma = temp;
		}
		for (int i = 0; i < str; i++)
		{
			x[i] = xtemp[i];
		}
		count++;
	} while (norma > es);

	cout << "  Численный и приближенный метод решения СЛАУ\n";
	for (int i = 0; i < str; i++)
	{
		cout << " x" << i + 1 << " ===> "<< x[i]<<endl;
	}
	cout << "\n Результат получен за " << count << " операций\n\n";
}

void Norma(long double** ar2, int str, int st) {
	long double* max = new long double[str];
	for (int i = 0; i < str; i++)
	{	
		int sum = 0;
		for (int k = 0; k < st-1; k++) {
			sum += ar2[i][k];
		}
		max[i] = sum;
	}
	int maxim = 0;
	for (int i = 0; i < st-1; i++)
	{
		if (max[i] > maxim)
			max[i] = maxim;
	}
	if (maxim > 1) {
		cout << "Достаточное условие сходимости не выполняется"; 
	}
}

double x_1(long double** ar2, long double* x, long double* xtemp, int str, int st) {
	double sum = 0;
	//первая сумма

		for (int j = 0; j < str; j++)
		{
			sum = sum + ar2[str][j] * xtemp[j];
		}

	//вторая сумма
		for (int j = str; j < st-1; j++)
		{
			sum = sum + ar2[str][j] * x[j];
		}

	//остаточный член
		sum=sum + ar2[str][st - 1];

	return sum;
}

void mz(long double** ar2, long double* x, long double* xtemp, int str, int st, int es) {
    int count = 0;
	long double norma=0;
	do {
		norma = 0;
		for (int i = 0; i <str; i++)
		{
			xtemp[i] = x_1(ar2, x, xtemp, i, st);
		}
		

		long double temp;

		for (int i = 0; i < str; i++)
		{
			temp = fabs(xtemp[i] - x[i]);
			if (temp > norma) norma = temp;
		}

		for (int i = 0; i < str; i++)
		{
			x[i] = xtemp[i];
		}

		count++;
	} while (norma > es);

	cout << "  Численный и приближенный метод решения СЛАУ\n";
	for (int i = 0; i < str; i++)
	{
		cout << " x" << i + 1 << " ===> " << x[i] << endl;
	}
	cout << "\n Результат получен за " << count << " операций\n\n";
}

int main() {
	SetConsoleOutputCP(1251);
	double es = 0.001;
	
	int size_l=3;
	int size_c=4;	
	long double** array = new long double* [size_l];
	for (int i = 0; i < size_l; i++)
	{
		array[i] = new long double[size_c];
	}
	for (int i = 0; i < size_l; i++)
	{
		for (int k = 0; k < size_c; k++)
		{
			cout << " Элемент " << i+1 << k+1<<" ===> ";
			cin >> array[i][k];
		}
	}
	long double** array2 = new long double* [size_l];
	for (int i = 0; i < size_l; i++)
	{
		array2[i] = new long double[size_c];
	}

	
		cout << " -------------------- Метод Якоби ---------------" << endl;
		Diagonal(array, size_l, size_c);
		first_step(array2, array, size_l, size_c);
		OutArray(array2, size_l, size_c);

		long double* array_X0 = new long double[size_l];

		cout << "\n Задайте начальные приближения x\n";
		for (int i = 0; i < size_l; i++)
		{
			cout << " x " << i + 1 << " ===> ";
			cin >> array_X0[i];
		}
		long double* array_X1 = new long double[size_l];

		my(es, array2, array_X1, array_X0, size_l, size_c);

		cout << " -------------------- Метод Зейделя ---------------" << endl;
		Norma(array2, size_l, size_c);
		cout << "\n Задайте начальные приближения x\n";
		for (int i = 0; i < size_l; i++)
		{
			cout << " x " << i + 1 << " ===> ";
			cin >> array_X0[i];
			array_X1[i] = 0;
		}

		mz(array2, array_X0, array_X1, size_l, size_c, es);

	
	

	system("pause");
	return 0;
}