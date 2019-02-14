
#include<iostream>
#include<algorithm>
#include<stack>
#include<string>
#include <ctime>
#include<bitset>
#include<vector>

using namespace std;

//void candles_bday()
//{
//	int N;
//	std::cin >> N;
//
//	int x = 0, y;
//	int n = 1;
//	int bigg = 1;
//
//	std::cin >> y;
//
//	for (int i = 1; i<N; i++)
//	{
//		std::cin >> x;
//		if (x >= y)
//		{
//			n++;
//		}
//		else
//		{
//			if (n>bigg)
//				bigg = n;
//			n = 1;
//		}
//		y = x;
//	}
//
//	if (n>bigg)
//		bigg = n;
//
//	std::cout << bigg;
//
//}
//
//
//void birthDay_bar_question()
//{
//
//	int N;
//	cin >> N;
//	int *arr = new int[N]();
//
//	for (int i = 0; i<N; i++)
//		cin >> arr[i];
//
//	int sum = 0, cL = 0;
//	cin >> sum >> cL;
//
//	int s = 0;
//	int cnt = 0;
//
//	if ((N == 1) && sum == arr[0])
//		cnt = 1;
//	else
//	{
//
//		for (int i = 0; i <= (N - cL); i++)
//		{
//			s = 0;
//			for (int j = i; j < (i + cL); j++)
//			{
//				s += arr[j];
//			}
//
//			if (sum == s)
//			{
//				cnt++;
//			}
//		}
//	}
//
//	cout << cnt;
//}
//
//void closest_numbers()
//{
//	int N;
//	cin >> N;
//	int *arr = new int[N]();
//	//int arr[10000] = { 0 };
//	for (int i = 0; i<N; i++)
//		cin >> arr[i];
//
//	std::sort(arr, arr + N);
//	long int min = 10000000;
//	int tracker[10000][2] = { 0 }, k = 0;
//	int f = 0;
//	for (int i = 0; i<N - 1; i++)
//	{
//		int tmp = arr[i + 1] - arr[i];
//
//		if (tmp == min)
//		{
//			if (f == 1)
//			{
//				k++;
//				f = 0;
//			}
//
//			min = tmp;
//			tracker[k][0] = i;
//			tracker[k][1] = i + 1;
//			k++;
//		}
//		else if (tmp<min)
//		{
//			if (k > 0)
//			{
//				k--;
//				f = 1;
//			}
//
//			min = tmp;
//			tracker[k][0] = i;
//			tracker[k][1] = i + 1;
//		}
//		else
//		{
//
//		}
//	}
//
//	for (int i = 0; i<k; i++)
//		std::cout << arr[tracker[i][0]] << " " << arr[tracker[i][1]] << " ";
//	delete[]arr;
//}
//
//
//int rem = 0;
//
//typedef
//struct _myData
//{
//	int Max;
//	int self;
//}Data;
//typedef struct st
//{
//	char first[10];
//	char second[10];
//}set;
//
//set myset[10000];
//int cnt = 0;
//
//
//void arrmanipulation()
//{
//	int M, N;
//	cin >> M >> N;
//
//	int  *arr = new int[M]{0};
//	int  Max = 0;
//
//	for (int i = 0; i < N; i++)
//	{
//		int a, b, k;
//		cin >> a >> b >> k;
//
//		for (int i = a - 1; i <= (b - 1); i++)
//		{
//			arr[i] = arr[i] + k;
//			if (arr[i] > Max)
//			{
//				Max = arr[i];
//			}
//		}
//	}
//
//
//	cout << Max;
//
//}
//
//
//int count8(int n)
//{
//	if (n == 0)
//		return 0;
//	if (n % 10 == 8)
//	{
//		rem++;
//		if (rem > 1)
//			return 2 + count8(n / 10);
//		else
//			return 1 + count8(n / 10);
//	}
//	else
//	{
//		rem = 0;
//		return count8(n / 10);
//	}
//}
//
//void stackOper()
//{
//	stack<Data>st;
//	int T;
//	cin >> T;
//	int maxVal = 0;
//
//	while (T-- > 0)
//	{
//		int q;
//		cin >> q;
//
//		if (q == 1)
//		{
//			int n;
//			cin >> n;
//			Data d;
//			if (n >= maxVal)
//			{
//				d.Max = maxVal;
//				maxVal = n;
//			}
//			else
//			{
//				d.Max = 0;
//			}
//			d.self = n;
//			st.push(d);
//		}
//		else
//			if (q == 2)
//			{
//				Data d1 = st.top();
//				if (d1.self == maxVal)
//				{
//					maxVal = d1.Max;
//				}
//
//				st.pop();
//			}
//			else if (q == 3)
//			{
//				cout << maxVal;
//			}
//	}
//
//}
//
////
////void  toLower(string &str)
////{
////	if (str.length() != 0)
////	{
////		str[0] = str[0] + 'z' - 'Z';
////		string s = str.substr(1);
////		toLower(s);
////		str[str.length - 1] = s[s.length - 1];
////	}
////}

//8, 4, 6, 2, 6, 4, 7, 9, 5, 8 
//int firstDuplicate(std::vector<int> a)
//{
//	//int *arr = new int[a.size()]();
//	int arr[10] = { 0 };
//
//	int i = 0;
//	for (auto ele : a)
//	{
//		i++;
//		if (arr[ele - 1] == 0)
//		{
//			arr[ele - 1] = 1;
//		}
//		else
//		{
//			arr[ele - 1] = i;
//		}
//
//	}
//
//	int min = INT_MAX;
//	for (int i = 0; i<a.size(); i++)
//	{
//		if (arr[i] > 1)
//		{
//			if (i<min)
//				min = arr[i] - 1;
//		}
//	}
//
//	delete[]arr;
//	if (min == INT_MAX)
//		return -1;
//	return a[min];
//}
//
//
