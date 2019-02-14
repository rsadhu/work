#include "stdafx.h"
#include"AlgoHeader.h"


void palindromeCreatiion()
{
	int n;
	int k;
	cin >> n >> k;
	string number;
	cin >> number;
	char *tmp = (char*)number.c_str();
	int i = 0, len = number.size();
	while (i<len)
	{
		if (*(tmp + i) == *(tmp + len - 1 - i))
		{
			i++;
			continue;
		}
		else
		{
			if (*(tmp + len - 1 - i) > *(tmp + i))
				*(tmp + len - 1 - i) = *(tmp + i);
			else
				*(tmp + i) = *(tmp + len - 1 - i);
			i++;
			k--;
			if (k <= 0)
				break;
		}
	}

	if (i == len - 1 && k >= 0)
		cout << tmp;
	else
		cout << "-1";

}




bool ransom_note(vector<string> magazine, vector<string> ransom)
{

	map<string, int> hashTable;
	for (int i = 0; i < magazine.size(); i++)
		hashTable[magazine.at(i)] += 1;

	for (int i = 0; i<ransom.size(); i++)
	{
		if (hashTable[ransom.at(i)] >= 0)
		{
			hashTable[ransom.at(i)] -= 1;
		}
		else
		{
			return false;
		}
	}

	return true;
}


void subString()
{

	int m;
	int n;
	cin >> m >> n;
	vector<string> magazine(m);
	for (int magazine_i = 0; magazine_i < m; magazine_i++){
		cin >> magazine[magazine_i];
	}
	vector<string> ransom(n);
	for (int ransom_i = 0; ransom_i < n; ransom_i++){
		cin >> ransom[ransom_i];
	}
	if (ransom_note(magazine, ransom))
		cout << "Yes\n";
	else
		cout << "No\n";

}


int compare(const void * a, const void * b)
{
	return (*(char*)a - *(char*)b);
}



int number_needed(string a, string b)
{
	char *src = const_cast<char*>(a.c_str());
	char *dst = const_cast<char*>(b.c_str());

	qsort((void*)src, a.size(), sizeof(char), compare);
	qsort((void*)dst, b.size(), sizeof(char), compare);

	char *tra, *tra1;
	if (*src > *dst)
	{
		tra = src;
		tra1 = dst;
	}
	else{
		tra = src;
		tra1 
			= dst;
	}	

	return 0;
}

void HR2()
{
	string a;
	cin >> a;
	string b;
	cin >> b;
	cout << number_needed(a, b) << endl;
}

void HR_Median()
{
	int n;
	cin >> n;
	vector<float> a(n);
	for (int a_i = 0; a_i < n; a_i++)
	{
		cin >> a[a_i];		
	}

	for (int a_i = 1; a_i <= n; a_i++)
	{
		std::sort(a.begin(), a.begin()+a_i);
		float res = 0.0;

		int mid = (a_i ) / 2 ;		

		if (a_i % 2 == 0)
		{
			res = (a[mid-1] + a[mid ]) / 2;
		}
		else
		{
			res = a[mid];
		}

		printf("%.*f\n",1, res);
	}
}