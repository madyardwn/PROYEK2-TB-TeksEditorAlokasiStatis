#include<iostream>
#include<dirent.h>
#include"del_rename.h"

using namespace std;
int ListFile()
{
    struct dirent *d;
    DIR *dr;
    dr = opendir("RecentFile");
    if(dr!=NULL)
    {
        cout<<"Daftar File : " <<endl;
        for(d=readdir(dr); d!=NULL; d=readdir(dr))
        {
            cout<<d->d_name<<endl;
        }
        closedir(dr);
    }
    else
        cout<<"\nERROR: Folder tidak ditemukan!";
    cout<<endl;
    return 0;
}
