#include"stdafx.h"
#include<iostream>
using namespace std;

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
				*str =  ch>'z'?  'a'+drft -1 : ch;
			}
			else if(*str>='A' && *str<='Z')
			{				
				*str =  ch>'Z'? 'A'+drft-1 : ch;
			}
			else
			{
			}		
	
		str++;
	}
	cout<<tmp<<endl;


}