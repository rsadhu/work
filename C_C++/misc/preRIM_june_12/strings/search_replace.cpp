#include<stdio.h>

int stringLength(char *s)
{
	char *t=s;
	while(*s!='\0')
		++s;
	return s-t;
}


void replaceEqual(char *str,char *toFind,char *replaceTo,int l)
{
	char *tmp = toFind;
	int startIndex=0,i=0;
	while(*(str+i)!='\0')
	{
		while(*(str+i) == *toFind)
		{
			if(startIndex==0)
				startIndex = i;
		        i++;
			toFind++;
		}

		if(*toFind=='\0')
		{
			while(l-- >0)
			{
				*(str+startIndex) =  *replaceTo++;
				startIndex++;				
			}
		}
		else
		{
			startIndex = 0;
			toFind = tmp;
		}
		i++;
	}
}

void replaceGreater(char *str, char *toFind, char *replaceTo)
{
	int m_l =  stringLength(str);
	int d = stringLength(toFind)- stringLength(replaceTo);
	
	while( *str!='\0')
	{

	}

}

void replaceSmaller(char *str, char *toFind , char *replaceTo)
{

}

void search_replace(char *str,char *toFind, char *replaceTo)
{
	int l1 = stringLength(toFind);
	int l2 = stringLength(replaceTo);
	if(l1 == 0)
		return ;
		if(l1==l2)
		replaceEqual(str, toFind,replaceTo,l1);
		else if(l1 > l2)
			replaceGreater(str,toFind,replaceTo);
		else
			replaceSmaller(str,toFind,replaceTo);
}


int main(void)
{
	char arr[]=" this is my december;e_name=rakesh;e_country=india;e_age=29;e_place=bangalore ; e_bplace=kashmir;";
	
	//printf("\n string --- %s\n ",arr);
	
	//search_replace(arr,const_cast<char *>("kashmir;"),const_cast<char *>("tangmarg;"));
	//printf("\n string --- %s\n ",arr);

	search_replace(arr,const_cast<char *>("rakesh"),const_cast<char *>("rsadhu"));
	printf("\n string --- %s\n ",arr);
	
	search_replace(arr,const_cast<char *>("december"),const_cast<char *>("november"));
	printf("\n string --- %s\n ",arr);
	
	search_replace(arr,const_cast<char *>("kashmir"),const_cast<char *>("kasheer"));
	printf("\n string --- %s\n ",arr);
	
	search_replace(arr,const_cast<char *>("bangalore "),const_cast<char *>("california"));
	printf("\n string --- %s\n ",arr);
		
	return 0;
}
