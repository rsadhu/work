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

int stringRecognizer(char *str,char *mob)
{
 while(*mob!='\0')
 {
  if(*mob != *str)
  return 0;
  mob++;
  str++; 
 }
 
 if(*mob == '\0')
 return 1; 
}

Contact *makeContact(char *buff)
{
 
 Contact *c = (Contact*)malloc(sizeof(Contact));
 int cnt=0;
 //char *tmp =(char *)malloc(sizeof(char )*30);
 char tmp[30];
 int i=0;
 if(tmp == NULL)
 printf("\n tmp failing\n");
 else
 {
  strcpy(tmp,"hello");
  printf("\n %s\n", tmp);
 }
 memset(tmp,0,30);
 char ch;
 while(*buff!='\0')
 {
  tmp[i++] = *buff++;
     
  if(*buff==' ' )
  { 
   cnt++;
    buff++;
	tmp[i] ='\0';
	i=0;
	switch(cnt)
	{
	 case 1:
		c->firstNumber =  strdup(tmp);
		
		break;
	 case 2:
		c->secondNumber = strdup(tmp);
		
		break;
	case 3:
		c->firstName = strdup(tmp);
		
		break;
	case 4:
		c->secondName = strdup(tmp);
		
		break;	 
	}	 
  }     
 }
 return c;
}

Contact *findContact(char *mob)
{
 char fname[100],lname[100]; 
 fseek(fp,0,SEEK_SET); 
 char buff[100];
 while(fgets(buff,100,fp)!=NULL)
 {
  printf("%s\n",buff);
  if(stringRecognizer(buff,mob))
  return makeContact(buff);   
 }
 return NULL;   
}


