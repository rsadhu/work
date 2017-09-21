
#include<iostream>
#include<algorithm>
#include<stack>
#include<string>
#include <ctime>
#include<bitset>
#include<vector>
#include"MyGraph.h"
#include"MyMatrix.h"

using namespace std;

void candles_bday()
{
	//int n;
	//std::cin >> n;

	int x = 0, y;
	int n = 1;
	int bigg = 1;

	std::cin >> y;

	for (int i = 1; i < n; i++)
	{
		std::cin >> x;
		if (x >= y)
		{
			n++;
		}
		else
		{
			if (n > bigg)
				bigg = n;
			n = 1;
		}
		y = x;
	}

	if (n > bigg)
		bigg = n;

	std::cout << bigg;

}


void birthday_bar_question()
{

	int n;
	cin >> n;
	int *arr = new int[n]();

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int sum = 0, cl = 0;
	cin >> sum >> cl;

	int s = 0;
	int cnt = 0;

	if ((n == 1) && sum == arr[0])
		cnt = 1;
	else
	{

		for (int i = 0; i <= (n - cl); i++)
		{
			s = 0;
			for (int j = i; j < (i + cl); j++)
			{
				s += arr[j];
			}

			if (sum == s)
			{
				cnt++;
			}
		}
	}

	cout << cnt;
}

void closest_numbers()
{
	int n;
	cin >> n;
	//	int *arr = new int[n]();
	int arr[10000] = { 0 };
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	std::sort(arr, arr + n);
	long int min = 10000000;
	int tracker[10000][2] = { 0 }, k = 0;
	int f = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int tmp = arr[i + 1] - arr[i];

		if (tmp == min)
		{
			if (f == 1)
			{
				k++;
				f = 0;
			}

			min = tmp;
			tracker[k][0] = i;
			tracker[k][1] = i + 1;
			k++;
		}
		else if (tmp < min)
		{
			if (k > 0)
			{
				k--;
				f = 1;
			}

			min = tmp;
			tracker[k][0] = i;
			tracker[k][1] = i + 1;
		}
		else
		{

		}
	}

	for (int i = 0; i < k; i++)
		std::cout << arr[tracker[i][0]] << " " << arr[tracker[i][1]] << " ";
	delete[]arr;
}


int rem = 0;

typedef
struct _mydata
{
	int max;
	int self;
}data;
typedef struct st
{
	char first[10];
	char second[10];
}set;



void arrmanipulation()
{
	int m, n;
	cin >> m >> n;

	int  *arr = new int[m]{0};
	int  max = 0;

	for (int i = 0; i < n; i++)
	{
		int a, b, k;
		cin >> a >> b >> k;

		for (int i = a - 1; i <= (b - 1); i++)
		{
			arr[i] = arr[i] + k;
			if (arr[i] > max)
			{
				max = arr[i];
			}
		}
	}


	cout << max;

}


int count8(int n)
{
	if (n == 0)
		return 0;
	if (n % 10 == 8)
	{
		rem++;
		if (rem > 1)
			return 2 + count8(n / 10);
		else
			return 1 + count8(n / 10);
	}
	else
	{
		rem = 0;
		return count8(n / 10);
	}
}

void stackoper()
{
	stack<data>st;
	int t;
	cin >> t;
	int maxval = 0;

	while (t-- > 0)
	{
		int q;
		cin >> q;

		if (q == 1)
		{
			int n;
			cin >> n;
			data d;
			if (n >= maxval)
			{
				d.max = maxval;
				maxval = n;
			}
			else
			{
				d.max = 0;
			}
			d.self = n;
			st.push(d);
		}
		else
			if (q == 2)
			{
				data d1 = st.top();
				if (d1.self == maxval)
				{
					maxval = d1.max;
				}

				st.pop();
			}
			else if (q == 3)
			{
				cout << maxval;
			}
	}

}


void  tolower(string &str)
{

}


void small_digit()
{

}

int firstDuplicate(std::vector<int> a)
{
	//int *arr = new int[a.size()]();
	//{
	//int *arr = new int[a.size()]();//8, 4, 6, 2, 6, 4, 7, 9, 5, 8 
	int arr[5] = { 0 };
	int i = 0;
	for (auto ele : a)
	{
		i++;
		if (arr[ele - 1] == 0)
		{
			arr[ele - 1] = 1;
		}
		else
		{
			arr[ele - 1] = i;
		}	
	}

	int min = INT_MAX, index = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if ((arr[i] > 1) && (arr[i] < min))
		{		
			min = arr[i];
			index = i + 1;
		}
	}

	delete[]arr;
	if (min == INT_MAX)
		return -1;
	return index;
}
