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
	cout << "Введите тарифный план " << N << "-х таксистов: " << endl;
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
				cout << "Сотруднику под номером - " << i + 1 << " нужно сесть в такси под номером: " << D[j] + 1 << endl;
	}
	cout << endl;
	int num = s;
	if (num % 10 == 1 && num % 100 != 11)
		cout << "Компании неообходимо заплатить - " << s << " рубль.";
	else if (num % 10 >= 2 && num % 10 <= 4 && (num % 100 < 10 || num % 100 >= 20))
		cout << "Компании неообходимо заплатить - " <<s << " рубля.";
	else
		cout << "Компании неообходимо заплатить - " << s << " рублей.";
	cout << endl << "Итог: ";

	string ed[] = { "", "один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять", "десять", "одиннадцать", "двенадцать", "тринадцать", "четырнадцать", "пятнадцать", "шестнадцать", "семнадцать", "восемнадцать", "девятнадцать" };
	string des[] = { "","", "двадцать", "тридцать", "сорок", "пятьдесят", "шестьдесят", "семьдесят", "восемьдесят", "девяносто" };
	string sot[] = { "","сто", "двести", "тристо", "четыресто", "пятьсот", "шестьсот", "семьсот", "восемьсот", "девятьсот" };
	string r1 = "тысяча";
	string r2 = "тысяч";
	string r3 = "тысячи", pr;
	string z = "рубль";
	string x = "рубля";
	string c = "рублей", zxc;
	 int digitcount = 0;
	int k = num;
	while (k > 0)
	{
		k /= 10;
		digitcount++;
	}
	if (num > 0 && num < 100000)
	{
		if (num < 20)
			cout << ed[num];
		else if (digitcount == 2)
			cout << des[num / 10] + " " + ed[num % 10];
		else if (digitcount == 3)
			cout << sot[num / 100] + " " + des[(num / 10) % 10] + " " + ed[num % 10];
		else if (digitcount == 4)
		{
			pr = r2;
			if ((num / 1000) == 1)
				cout << "одна тысяча" << " " + sot[(num / 100) % 10] + " " + des[(num / 10) % 10] + " " + ed[num % 10];
			else if ((num / 1000) == 2)
				cout << "две тысячи" << " " + sot[(num / 100) % 10] + " " + des[(num / 10) % 10] + " " + ed[num % 10];
			else
			{
				if ((num / 1000) == 3 || (num / 1000) == 4)
					pr = r2;
				cout << ed[num / 1000] + " " + pr + sot[(num / 100) % 10] + " " + des[(num / 10) % 10] + " " + ed[num % 10];
			}
		}
		else if (digitcount == 5)
		{
			pr = r2;
			if ((num / 1000) < 20)
				cout << ed[num / 1000] + " " + pr + " " + sot[(num / 100) % 10] + " " + des[(num / 10) % 10] + " " + ed[num % 10];
			else
			{
				if (num / 1000 % 10 == 1)
					pr = r1;
				if (num / 1000 % 10 == 2 || num / 1000 % 10 == 3)
					pr = r3;
				cout << des[num / 10000] + " " + ed[num / 1000 % 10] + " " + pr + " " + sot[(num / 100) % 10] + " " + des[(num / 10) % 10] + " " + ed[num % 10];
			}
		}
		else if (digitcount == 5)
			cout << "Сто тысяч";
	}
	if (num % 10 == 1 && num % 100 != 11)
		cout << " рубль";
	else if (num % 10 >= 2 && num % 10 <= 4 && (num % 100 < 10 || num % 100 >= 20))
		cout << " рубля";
	else
		cout << " рублей";
	cout << "." << endl;
}
