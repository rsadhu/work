#include "stdafx.h"
#include "ArrayManipulations.h"

ArrayManipulations::ArrayManipulations(void)
{
}

ArrayManipulations::~ArrayManipulations(void)
{
}

void ArrayManipulations::fillData(int &m, int &n, int &pM, int &pN)
{
	cin >> m >> n;

	arr = new int *[m];
	for (int i = 0; i < m; i++)
		arr[i] = new int[n];

	for (int i = 0; i < m; i++)
	{
		string row;
		cin >> row;
		int j = 0;
		char *s = const_cast<char *>(row.c_str());

		while (*(s + j) != '\0')
		{
			arr[i][j] = *(s + j) - '0';
			cout << arr[i][j];
			j++;
		}
		cout << endl;
	}

	cin >> pM >> pN;

	pattern = new int *[pM];
	for (int i = 0; i < pM; i++)
		pattern[i] = new int[pN];

	for (int i = 0; i < pM; i++)
	{
		string row;
		cin >> row;
		int j = 0;
		char *s = const_cast<char *>(row.c_str());

		while (*(s + j) != '\0')
		{
			pattern[i][j] = *(s + j) - '0';
			cout << pattern[i][j];
			j++;
		}

		cout << endl;
	}
}

bool ArrayManipulations::isSubArray()
{
	bool ret(false);
	int T = 0;
	cin >> T;
	while (T)
	{

		int m, n, pM, pN;
		m = n = pM = pN = 0;

		fillData(m, n, pM, pN);

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int k, l;
				k = l = 0;
				while (k < pM && l < pN && (arr[i + k][j + l] == pattern[k][l]))
				{
					l++;
					if (l == pM)
					{
						if (k < pM - 1)
							l = 0;
						k++;
					}
				}

				if (k >= pM && l >= pN)
				{
					cout << "found...\n";
					return ret;
				}
			}
		}
		cout << "not found..\n";
		T--;
	}

	return ret;
}

void ArrayManipulations::isArrayHalfBalanced()
{
	int T;
	cin >> T;

	while (T)
	{
		T--;
		int sum = 0, f = 0;
		int n;
		cin >> n;
		if (n < 3)
		{
			int d1, d2;

			if (n == 1)
			{
				cout << "YES" << endl;
				cin >> d1;
			}
			if (n == 2)
			{
				cin >> d1;
				cin >> d2;
				cout << "NO" << endl;
			}

			continue;
		}

		int *arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			sum += arr[i];
		}

		int sum1 = arr[0];
		for (int i = 1; i < n; i++)
		{
			sum1 += arr[i];
			// if(sum1 -arr[i] == (sum-(sum1-arr[i])))
			if ((sum1 - arr[i]) == (sum - sum1))
			{
				cout << "YES" << endl;
				f = 1;
				break;
			}
			// f=1;
		}
		if (0 == f)
			cout << "NO" << endl;

		delete[] arr;
	}
}

void test()
{
	int sum = 0;
	int n = 5;
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				sum = sum + n;
			}
		}
	}
	cout << sum << endl;
}

void ArrayManipulations::subMatrixSum(int m, int n)
{
	test();
}
