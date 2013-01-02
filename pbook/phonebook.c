#include"phonebook.h"

static FILE *fp;
static unsigned int uid;
void init(void)
{
	 fp = fopen("pb.txt","a+");
	 if(!fp)
	  {
	   printf("\n File Creation/opening failing :: Exiting\n");
	   exit(1);
	  }
}

void close()
{
	if(fp)
	fclose(fp);
}

void addContact()
{
  uid++;
  char str[50];  

  printf("\n Enter the First Name:: if not then press N\n");
  scanf("%s",str);
  if(strcmp(str,"N")==0){
   printf("\nN pressed\n");
   strcpy(str, "$");
  }
  fprintf(fp,"%d:%s ",uid,str);    
  
  printf("\n Enter the Second Name :: if not then press N\n");
  scanf("%s",str);
  if(strcmp(str,"N")==0)
  strcpy(str, "$");
  fprintf(fp,"%s ",str);
  
  printf("\n Enter the Mobile Number :: if not then press N\n");
  scanf("%s",str);
  if(strcmp(str,"N")==0)
  strcpy(str, "$");
  fprintf(fp,"%s ",str);    
  
  printf("\n Enter the TelePhone Number :: if not then press N\n");
  scanf("%s",str);
  if(strcmp(str,"N")==0)
  strcpy(str, "$");
  fprintf(fp,"%s#%s",str,"\n");      
}

void updateContact()
{

}

int deleteContact()
{

}

Contact* findContact(Contact *f)
{

}


