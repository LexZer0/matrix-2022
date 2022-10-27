#include <iostream>
#include <ctime>
using namespace std;

const int MAX_N = 100;

void writeArray(int a[], int n);
void printArray(int a[], int n);
void reserve(int a[], int b[], int n);
void writeReserve(int b[], int n);

void MinMaxArray(int a[], int n);
void SwapMinMax(int a[], int n);
void difference(int b[], int n);
void sumNechet(int a[], int n);
void sumMinus(int a[], int n);
void removeDig(int b[], int n);

int main()
{
	int n;
	int a[MAX_N];
	int b[MAX_N];
	srand(time(0));
	cout << "n = ";
	cin >> n;
	writeArray(a, n);
	reserve(a, b, n);
	printArray(a, n);
	MinMaxArray(a, n);
	SwapMinMax(a, n);
	difference(b, n);
	sumNechet(a, n);
	sumMinus(a, n);
	reserve(a, b, n);
	removeDig(b, n);
	writeReserve(b, n);
	return 0;
}

void writeArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10 - 5;
	}
}

void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n\n";
}

void reserve(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
}

void writeReserve(int b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << " ";
	}
}

void MinMaxArray(int a[], int n)
{
	int max=-1000, min=1000;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	cout << "Max = " << max << endl;
	cout << "Min = " << min << "\n\n";
}

void SwapMinMax(int a[], int n)
{
	int max = -1000, min = 1000;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	swap(max, min);
	cout << "Max = " << max << endl;
	cout << "Min = " << min << "\n\n";
}

void difference(int b[], int n)
{
	int k, p = 0;
	for (int i = 0; i < n; i++)
	{
		k = 1;
		for (int t = i; t < n; t++)
		{
			if (b[i] == b[t+1])
			{
				b[t+1] = 1000;
				k++;
			}
		}
		if (b[i] != 1000)
		{
			p++;
			cout << "a[i] = " << b[i];
			cout << "\t" << "k = " << k << endl;
		}
	}
	cout << "p = " << p << "\n\n";
}

void sumNechet(int a[], int n)
{
	int nch, sumN = 0;
	for (int i = 0; i < n; i++)
	{
		nch = a[i] % 2;
		if (1 == nch)
		{
			sumN += a[i];
		}
	}
	cout << "Sum of nechetnih=" << sumN << "\n\n";
}

void sumMinus(int a[], int n)
{
	int first = 0, last = 0, i = 0, sumPool = 0;
	if (a[0] < 0)
	{
		first = 0;
	}
	while(a[i]>0 && a[i]!=0)
	{
		first = i + 1;
		i++;
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			last = i;
		}
	}
	for (first=first + 1; first < last; first++)
	{
		sumPool += a[first];
	}
	cout << "SumPool=" << sumPool << "\n\n";
}

void removeDig (int b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (abs(b[i]) <= 1)
		{
			b[i] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - (i + 1); j++)
		{
			if (b[j] == 0)
			{
				swap(b[j], b[j + 1]);
			}
		}
	}
}