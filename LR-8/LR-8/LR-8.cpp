#include<Windows.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N,s=0;
	cout << "Введите кол-во сотрудников компании: " << endl;
	cin >> N;
	
	int* A = new int[N];
	int* B = new int[N];
	int* C = new int[N];
	int* D = new int[N];
	cout << "Введите расстояние от работы до домов каждого из сотрудников: " << endl;
	for (int i = 0;i < N;i++)
	{
		cin >> A[i];
		C[i] = i;
		D[i] = i;
	}
	cout << "Введите тарифлый план " << N << "-х таксистов: " << endl;
	for (int i = 0;i < N;i++)
		cin >> B[i];
	for (int i = 0; i < N - 1; i++)
		for (int j = i + 1; j < N; j++)
		{
			if (A[i]>A[j])
			{
				swap(A[i], A[j]);
				swap(C[i], C[j]);
			}
			if (B[i]<B[j])
			{
				swap(B[i], B[j]);
				swap(D[i], D[j]);
			}
		}
	for (int i = 0;i < N;i++)
	{
		s += (A[i] * B[i]);
		for (int j = 0;j < N;j++)
			if (C[j] == i)
				cout << "Таксисту под номером - " << i + 1 << " нужно сесть в такси под номером: " << D[j] + 1 << endl;
	}
	cout << endl;
	int num = s, digitcount = 0;
	int k = num;
	if (num % 10 == 1 && num % 100 != 11)
		cout << "Компании неообходимо заплатить - " << s << " рубль.";
	else if (num % 10 >= 2 && num % 10 <= 4 && (num % 100 < 10 || num % 100 >= 20))
		cout << "Компании неообходимо заплатить - " <<s << " рубля.";
	else
		cout << "Компании неообходимо заплатить - " << s << " рублей.";
}
