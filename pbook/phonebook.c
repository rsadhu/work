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

void write( char *fname, char *lname,char *mob, char *tele)
{  
   fprintf(fp,"%s %s %s %s%s",mob,tele,fname,lname,"\n");
}
void addContact()
{
  uid++;
  char fname[50];  
  char lname[50];  
  char mob[150];  
  char tele[50];  

  printf("\n Enter the First Name:: if not then press N\n");
  scanf("%s",fname);
  if(strcmp(fname,"N")==0){
   printf("\nN pressed\n");
   strcpy(fname, "$");
  }
  //fprintf(fp,"%d:%s ",uid,str);    
  
  printf("\n Enter the Second Name :: if not then press N\n");
  scanf("%s",lname);
  if(strcmp(lname,"N")==0)
  strcpy(lname, "$");
  //fprintf(fp,"%s ",str);
  
  printf("\n Enter the Mobile Number :: if not then press N\n");
  scanf("%s",mob);
  if(strcmp(mob,"N")==0)
  {
	printf("\n Mob number is important , Try again ,Exitting Now\n");
	exit(1);
  }
  //fprintf(fp,"%s ",str);    
  
  printf("\n Enter the TelePhone Number :: if not then press N\n");
  scanf("%s",tele);
  if(strcmp(tele,"N")==0)
  strcpy(tele, "$");
  //fprintf(fp,"%s #%s",str,"\n");     
  write(fname, lname, mob,tele);  
}

void updateContact()
{

}

int deleteContact()
{

}

Contact* findContact(Contact *f)
{
 char fname[100],lname[100];
 int mob, tele;
 fseek(fp,0,SEEK_SET); 
 char buff[100];
 while(fgets(buff,100,fp)!=NULL)
 {
  printf("%s\n",buff);
 }
}


