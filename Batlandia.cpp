#include <iostream>
#include <ctime>

using namespace std;

class Attraction
{
private:

	int n, m, k;
	static int count;

public:

	Attraction();
	Attraction(int n, int m);

	void ArrCreatInit();
	void Swap();
	void Screen();

	int** arr = new int*[n];
};

int Attraction::count = 0;

Attraction::Attraction()
{
	n = 0;
	m = 0;
	k = 0;
}

Attraction::Attraction(int n, int m)
{
	if (n<1 || n>250)
	{
		cout << "Ошибка\n";
		system("pause");
		exit(0);
	}
	if (m<1 || m>250)
	{
		cout << "Ошибка\n";
		system("pause");
		exit(0);
	}
	this->n = n;
	this->m = m;
}

void Attraction::ArrCreatInit()
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
	}

	cout << "Номера кресел:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = (i - 1)*m*j;
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

void Attraction::Swap()
{
	k = rand() % 1000 + 1;
	bool t = rand() % 2;
	int mRand = 0;
	int mRand1 = 0;
	int nRand = 0;
	int nRand1 = 0;
	int* arrTemp = new int;

	for (int p = 0; p < k; p++) 
	{
		count++;

		if (t)
		{
			for (int i = 0; i < m; i++)
			{
				mRand = rand() % m;
				mRand1 = rand() % m;
				arrTemp[i] = arr[mRand][i];
				arr[mRand][i] = arr[mRand1][i];
				arr[mRand1][i] = arrTemp[i];
			}
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				nRand = rand() % n;
				nRand1 = rand() % n;
				arrTemp[i] = arr[i][nRand];
				arr[i][nRand] = arr[i][nRand1];
				arr[i][nRand1] = arrTemp[i];
			}
		}
	}
}

void Attraction::Screen()
{
	cout << "Номера кресел после " << k << " замен:\n";
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < m; k++)
		{
			arr[i][k] = (i - 1)*m*k;
			cout << arr[i][k] << " ";
		}
		cout << "\n";
	}
	cout << "Для перестановки кресел понадобится " << count << " действий\n";
}

int main() 
{
	setlocale(LC_ALL, "rus");
	srand(time(0));

	Attraction attract(7, 7);

	attract.ArrCreatInit();
	attract.Swap();
	attract.Screen();

	system("pause");
	return 0;
}