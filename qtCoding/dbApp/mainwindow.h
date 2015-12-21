#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<vector>
#include <QMainWindow>
#include<string>
#include<iostream>
#include<stdio.h>

using namespace std;

namespace Ui {
class MainWindow;
}


class User
{
public:

    User (){}
    User(const User &rhs);
    User & operator=(const User &rhs);

    User(string &name,string &address, string email,int age,int mobile)
    {
        mName =  name;
        mAddress = address;
        mEmail = email;
        mAge = age;
        mMobile =  mobile;
    }

    /*   getters */
    string & getName(){ return mName;}
    string & getAddress(){ return mAddress;}
    string & getEmail(){ return mEmail;}
    int getAge(){ return mAge;}
    int  getMobile(){ return mMobile;}

    /* setters */

    void setName(string &name){ mName= name;}
    void setAddress(string &address){ mAddress= address;}
    void setEmail(string &email){ mEmail = email;}
    void setAge(int age){ mAge= age;}
    void setMobile(int mob){ mMobile =  mob;}



private:
    string mName;
    string mAddress;
    string mEmail;
    int mAge;
    int mMobile;

};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void addUser();
    void deleteUser();
    void getAllUsers();
private:
    Ui::MainWindow *ui;
    FILE *m_FilePointer;
    vector<User> m_allUsers;

};

#endif // MAINWINDOW_H
