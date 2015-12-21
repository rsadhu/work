#include <QCoreApplication>
#include<vector>
#include<QDebug>
#include"graphs.h"
#include<iostream>
#include<dirent.h>

using namespace std;

void readDir(char *path)
{
        DIR *d =  opendir(path);
        struct dirent *dir;
        if(d)
        {
            while((dir=readdir(d))!=NULL)
            {
                 cout<<dir->d_name<<endl;

                 if(dir->d_type==DT_DIR)
                 {
                     if(0==strcmp(dir->d_name,".") || 0==strcmp(dir->d_name,".."))
                         continue;
                     else
                        readDir(dir->d_name);
                 }
            }
            closedir(d);
        }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    readDir(".");

    return a.exec();
}



