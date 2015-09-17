#include"stdafx.h"
#include<string>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using namespace std;
#define __HR__  1
#ifdef __HR__


void mcqs()
{

	/*int x=10,y=15;
	x=x++;
	y=++y;
	cout<<x<<" "<<y;
	int z;
	x=y=z=0;
	cout<<x<<y<<z;*/

	int val = 1;
	cout<<~val;


}

 void  twoStrings() {

	int T;
    cin>>T;
    char *alphabets="abcdefghijklmnopqrstuvwxyz";
	int  cSet[120]={0};
    while(T)
    {
        string s1,s2;
        cin>>s1>>s2;
        char *tmp1 =  (char *)s1.c_str();
		char *tmp2 =  (char *)s2.c_str();

        int f=0;
		while(*tmp1!='\0')
		{
			if(cSet[*tmp1]!=1)
				cSet[(int)*tmp1]=1;
			tmp1++;
		}
		while(*tmp2!='\0')
		{
			cSet[(int)*tmp2]+=1;
			tmp2++;
		}

		for(int i=0;i<120;i++)
		{
			if(cSet[i]>=2)
				cout<<"YES"<<endl;
			else 
				cout<<"NO"<<endl;        				
		}       
				
        T--;       
	}
        
}


void  anagram() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin>>T;
    while(T)
        {
        string s;
        cin>>s;
        char *tmp =  (char *)s.c_str();
        int cnt=0;
        if(s.size()%2!=0)
           cnt=-1;
        else{
			
            int mid = (s.size())/2-1;            
            for(int i=0;i<=mid;i++)
            {
				int f=0;
                for(int j=mid+1;j<s.size();j++)    
                    {
                    if(tmp[i]==tmp[j])
                        {
                           tmp[j]='0';                        
						   f=1;
						   break;
					}                    
                }
				if(f==0)
					cnt++;
            }            
        }
        T--;
        cout<<cnt<<endl;
    }    
    
}


























int getSmallest(int *arr,int size)
{
    int MIN=0;
	int j=0;
	while(j<=size)
	{
		if(arr[j]>0){
			MIN = arr[j];
			break;
		}
		j++;
	}

    //size--;
	int i = 0;
    while(i<=size)
    {
        if(arr[i]>0 && arr[i]<MIN)
            MIN=arr[i];
        i++;        
    }
    return MIN;    
}

int hackerRank_stick() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */       
	int T;
	cin>>T;
	while(T)
	{
    int n;
    cin>>n;
    int *arr=new int[n]();
    for(int i=0;i<n;i++){
        cin>>arr[i];
       // cout<<arr[i]<<" ";
    }
    
    while(1){
        
        int min = getSmallest(arr,n-1);
        int cnt=0,i=0;
        while(i<n){
            if(arr[i]>0)
            {
                cnt++;            
                arr[i]-=min;
            }            
            i++;
        }
        if(cnt==0)
            break;
        cout<<cnt<<endl;     
        
    }
    T--;
	}
    
    return 0;
}

void caeserString()
{
	int T;
	cin>>T;
	while(T)
	{
	int n;
	cin>>n;

	char *str = new char[n]();
	cin>>str;

	int drft;
	cin>>drft;

	cout<<str<<endl;
	char *tmp=str;

	while(*str!='\0')
	{		
			drft =  drft%26;		
			char ch =  *str+ drft;
			
			
			if(*str>='a' && *str<='z')
			{				
				*str =  ch>'z'?  'a'+drft -1 -('z'-*str) : ch;
			}
			else if(*str>='A' && *str<='Z')
			{				
				*str =  ch>'Z'? 'A'+drft-1-('Z'-*str) : ch;
			}
			else
			{
			}		
	
		str++;
	}
	cout<<tmp<<endl;
	T--;
	}

}

void cavityMap()
{
	int n;
	cin>>n;
	string *s =  new string [n];
		char **arr =  new char *[n];
	for(int i=0;i<n;i++)
		arr[i] = new char[n];

	for(int k=0;k<n;k++)
	{
		cin>>s[k];
		string tmp = s[k];
		for(int j=0;j<n;j++)
		{
			arr[k][j]=(int)tmp[j];
		}
	}
	

	int MAX=0;
	for(int i=1;i<n-1;i++)
	{
		int ii=0,jj=0,f=0;
		for(int j=1;j<n-1;j++)
		{	
		    if(arr[i][j]>=MAX)
			{
				ii = i,
			    jj = j;
				MAX=arr[i][j];
			}
			else
				f=1;
		}
		if(f==1)
		arr[ii][jj]='X';
	}


	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<arr[i][j];
		}
		cout<<endl;
	}
}

void matrixMan()
{
	int arr1[][3]={ {1,2,3},{ 4,5,6},{7,8,9}};
	int arr2[][3]={ {1,2,3},{ 4,5,6},{7,8,9}};
	//int arr3[][3]={ {1,2,3},{ 4,5,6},{7,8,9},{1,2,3},{ 4,5,6},{7,8,9}};
	int arr3[][3]={{0,0,0},{0,0,0},{0,0,0}};

	for(int i=0;i<3;i++)
	{		
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				arr3[i][j]+=arr1[i][k]*arr2[k][j];						
			}
		}
	}
	
			

	for(int i=0;i<3;i++)
	{
		for(int k=0;k<3;k++)
		{
			cout<<arr3[i][k]<<" ";
		}
		cout<<endl;	
	}

}




#endif

