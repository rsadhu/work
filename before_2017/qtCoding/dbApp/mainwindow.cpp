#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>


User::User(const User &rhs)
{
 this->mEmail  = rhs.mEmail;
 this->mName = rhs.mName;
 this->mAddress =  rhs.mAddress;
 this->mMobile = rhs.mMobile;
 this->mAge = rhs.mAge;
}

User & User::operator=(const User &rhs)
{
    if(this!= &rhs)
    {
        this->mEmail  =   rhs.mEmail;
        this->mName =     rhs.mName;
        this->mAddress =  rhs.mAddress;
        this->mMobile =   rhs.mMobile;
        this->mAge =      rhs.mAge;
    }
 return *this;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->addB,SIGNAL(clicked(bool)), this,SLOT(addUser()));
    connect(ui->deleteB,SIGNAL(clicked(bool)), this,SLOT(deleteUser()));
    connect(ui->getAllUsersB,SIGNAL(clicked(bool)), this,SLOT(getAllUsers()));

    try{
    m_FilePointer =  fopen("db.txt","w+");
    if(!m_FilePointer)
        throw -1;
    else
    {
        char name[100],email[100],address[100];
        int age=0,mob=0;
        while(fscanf(m_FilePointer,"%s%s%s%d%d",name,email,address,age,mob)!=EOF)
        {
            User u;
            string n(name);
            u.setName(n);
            string e(email);
            u.setEmail(e);
            string a(address);
            u.setAddress(a);
            u.setAge(age);
            u.setMobile(mob);
            m_allUsers.push_back(u);
        }
    }
    }catch(int ex)
    {
        qDebug()<<"Error Occured while opening File Handle"<<ex<<"\n";
    }
}

MainWindow::~MainWindow()
{
    fclose(m_FilePointer);
    delete ui;
}



void MainWindow::addUser()
{    
    string name (ui->nameEdit->text().toLatin1().data());
    string email(ui->emailEdit->text().toLatin1().data());
    string address(ui->addressEdit->text().toLatin1().data());
    int age = ui->ageEdit->text().toInt();
    int mob = ui->mobEdit->text().toInt();

    int length=name.size()+email.size()+address.size()+30;
    char *inp =  new char[length];

    sprintf(inp,"%s%s%s%d%d",name.c_str(),email.c_str(),address.c_str(),age,mob);
    fwrite(inp,1,length,m_FilePointer);
    User u;
    u.setName(name);
    u.setEmail(email);
    u.setAddress(address);
    u.setAge(age);
    u.setMobile(mob);
    m_allUsers.push_back(u);
}

void MainWindow::deleteUser()
{

}

void MainWindow :: getAllUsers()
{

    //for(vector<User>::iterator it= m_allUsers;it!=m_allUsers.end();it++)
    for(int i=0;i<m_allUsers.size();i++)
    {
     User *it = &(m_allUsers[i]);
     QListWidgetItem *item = new QListWidgetItem;
     item->setText(QString(it->getName().c_str()));
     ui->listWidget->addItem(item);

     QListWidgetItem *item1 = new QListWidgetItem;
     item->setText(QString(it->getEmail().c_str()));
     ui->listWidget->addItem(item1);

     QListWidgetItem *item2 = new QListWidgetItem;
     item->setText(QString(it->getAddress().c_str()));
     ui->listWidget->addItem(item2);

     QListWidgetItem *item3 = new QListWidgetItem;
     item->setText(QString(it->getAge()));
     ui->listWidget->addItem(item3);

     QListWidgetItem *item4 = new QListWidgetItem;
     item->setText(QString(it->getMobile()));
     ui->listWidget->addItem(item4);

    }
}
