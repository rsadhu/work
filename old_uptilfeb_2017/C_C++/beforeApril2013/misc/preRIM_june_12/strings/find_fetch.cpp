#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

void findAndFetch(char *mainString, char *pivot,char *arr)
{
	char *toFind  = pivot;
	int i=0,j=0;
	while(*mainString++ != '\0')
	{
		while(*mainString == *toFind )
		{
//			printf("\n %c  ==  %c \n",*mainString, *toFind);
			mainString++;
			toFind++;
		}
		
		if(*toFind =='\0')
		{
			if(*mainString!=';')
			{
				arr[i] =  *mainString;
				i++;
				j=1;
			}
			else
			{
				j=0;
			}
			if(j==0 && i!=0)
				break;
		}
		else 
		{
			toFind = pivot;
		}
	}

	if(*toFind == '\0')
		arr[i] ='\0';
}




int
main (void)
{
//	char str[] =    "#e_status=0;e_result=OK;e_server=ankara.ebuddy.com;e_version=2.18.15;e_port=110;";
//	char str[]  =  "#e_status=0;e_result=OK;e_server=colby.ebuddy.com;e_version=2.18.15;e_port=110;";
	char str[] =  "#e_status=0;e_result=OK;e_server=miramar.ebuddy.com;e_version=2.18.15;e_port=110;type=1;e_test=rakeshsadhuismyname.iamfromkashmir.iam29yearsoldman.now working with accenture and living in bangalore#;\
	e_content_type=text/plain/html/image/dhshdjhs#\n";


	char *arr1 = new char[30];
	findAndFetch(str,"e_server=",arr1);
	printf ("\n e_server =  %s", arr1);

	char *arr2 =  new char[30];
	bzero(arr2,0);
	findAndFetch(str,"e_port=",arr2);
	printf ("\n port =  %s\n", arr2);

	char *arr3 =  new char[200];
	findAndFetch(str,"e_test=",arr3);
	printf ("\n e_test  = %s\n", arr3);

	char *arr4= new char[100];
	findAndFetch(str,"e_content_type=",arr4);
	printf("\n contentType = %s\n",arr4);

	return 0;
}
