#include"phonebook.h"

static FILE *fp;
static unsigned int uid;
ContactList *_head;

void init(void)
{
	 fp = fopen("pb.txt","a+");
	 
	 if(!fp)
	  {
	   printf("\n File Creation/opening failing :: Exiting\n");
	   exit(1);
	  }
	  fillList();
	  displayList();
}

Contact *makeContact(char *buff)
{
 Contact *c = (Contact*)malloc(sizeof(Contact));
 int cnt=0;
 char tmp[30];
 int i=0;
 
 while(*buff!='\0')
 {
  tmp[i++] = *buff++;
     
  if(*buff==' '  || *buff == '\n')
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

void fillList()
{
 fseek(fp,0,SEEK_SET); 
 char buff[100];
 while(fgets(buff,100,fp)!=NULL)
 {
   addtolist(makeContact(buff));
 } 
}

void addtolist(Contact*obj)
{
ContactList * tmp =  (ContactList*)malloc(sizeof(ContactList));
tmp->data = obj;
tmp->next = NULL;
 if(!_head)
 {
  _head =  tmp; 
 }
 else
 {
  ContactList *tra;
  for(tra =_head;tra->next!=NULL;tra=tra->next);
  tra->next = tmp;  
 }
}


void displayList()
{
 ContactList *t =  _head;
 Contact *tmp ;
 while(t)
 {
  tmp = t->data;
  printf("\n%s \n %s \n%s\n%s\n",tmp->firstName,tmp->secondName,tmp->firstNumber,tmp->secondNumber);
  t =  t->next;  
 }
}



void close()
{
	if(fp)
	fclose(fp);
	ContactList *tra;
	displayList();
	
	while(_head)
	{
		tra =  _head;
		if(tra->data!=NULL)
		 free(tra->data);		

		 _head =  _head->next;	
		free(tra);
		
	}
}

void writeAgain(ContactList *head)
{
if(head){
 fclose(fp);fp=NULL;
 fp = fopen("pb.txt","w");
 
 fclose(fp);fp=NULL;
 fp = fopen("pb.txt","a+");
 Contact *obj;
 while(head)
 {
	obj =  head->data;   
	fprintf(fp,"%s %s %s %s%s",obj->firstNumber,obj->secondNumber,obj->firstName,obj->secondName,"\n");
	head = head->next;
 } 
 }
}

void write( char *fname, char *lname,char *mob, char *tele)
{  
   fprintf(fp,"%s %s %s %s%s",mob,tele,fname,lname,"\n");
   Contact *tmp = (Contact *)malloc(sizeof(Contact));
   tmp->firstName =  strdup(fname);
   tmp->secondName =  strdup(lname);
   tmp->firstNumber =  strdup(mob);
   tmp->secondNumber =  strdup(tele);
   addtolist(tmp);
   displayList();
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
  
  
  printf("\n Enter the Second Name :: if not then press N\n");
  scanf("%s",lname);
  if(strcmp(lname,"N")==0)
  strcpy(lname, "$");
  
  
  printf("\n Enter the Mobile Number :: if not then press N\n");
  scanf("%s",mob);
  if(strcmp(mob,"N")==0)
  {
	printf("\n Mob number is important , Try again ,Exitting Now\n");
	exit(1);
  }
  
  
  printf("\n Enter the TelePhone Number :: if not then press N\n");
  scanf("%s",tele);
  if(strcmp(tele,"N")==0)
  strcpy(tele, "$");
  
  write(fname, lname, mob,tele);  
}

void updateContact(char * mob, Contact *new)
{
  ContactList *tra = _head;
  Contact *obj=NULL;  
  if(strcmp(tra->data->firstNumber,mob)==0)
  {
    //_head =  _head->next;
	strcpy(tra->data->firstName,new->firstName);
	strcpy(tra->data->secondName,new->secondName);
	strcpy(tra->data->firstNumber,new->firstNumber);
	strcpy(tra->data->secondNumber,new->secondNumber);
  }
  else
  {
    ContactList *prev =_head;	
	tra =  prev->next;	
	while(tra)
	{	    
		obj = tra->data;
		if(strcmp(mob,obj->firstNumber)==0)
		{		 
		strcpy(obj->firstName,new->firstName);
		strcpy(obj->secondName,new->secondName);
		strcpy(obj->firstNumber,new->firstNumber);
		strcpy(obj->secondNumber,new->secondNumber);
		 break;
		}
		tra= tra->next;
		prev = prev->next;
	}	
  }
  writeAgain(_head);

}

int deleteContact( char *mob)
{
  ContactList *tra = _head;
  Contact *obj=NULL;  
  if(strcmp(tra->data->firstNumber,mob)==0)
  {
    _head =  _head->next;
  }
  else
  {
    ContactList *prev =_head;	
	tra =  prev->next;	
	while(tra)
	{	    
		obj = tra->data;
		if(strcmp(mob,obj->firstNumber)==0)
		{
		 prev->next = tra->next;
		 free(tra);
		 break;
		}
		tra= tra->next;
		prev = prev->next;
	}	
  }
  writeAgain(_head);
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



Contact *findContact(char *mob)
{
 displayList();
  ContactList *tra = _head;
  Contact *obj =NULL;
  while(tra)
  {
	obj = tra->data;
	if(strcmp(mob,obj->firstNumber))
	return obj;
	tra= tra->next;	
  } 
}


