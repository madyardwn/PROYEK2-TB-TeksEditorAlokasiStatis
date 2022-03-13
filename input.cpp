#ifndef edit_H
#define edit_H

#include <string>
using namespace std;

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>

void edit(){
    string teks="";
    string namafile;
    cout<<"Nama file:";
    cin >> namafile;
    cout << endl <<"Input teks ke dalam file :"<< endl;
    ofstream myfile;
    myfile.open((namafile+".txt").c_str(),ios::app);
    string line;
    cin.ignore();
    while (getline(cin, line)){
        if(line.size()>=3){
            if(line.substr(line.size()-3)== "END"){
                teks+= line.substr(0, line.size()-3);
                break;
            }else{
                teks+=line+"\n";
            }
        }else{
            teks+=line+"\n";
        }
    }
    myfile<<teks;
    myfile.close();
}

#endif
