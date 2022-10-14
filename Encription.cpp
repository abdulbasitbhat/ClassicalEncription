#include<iostream>
#include<fstream>
#include<istream>
using namespace std;


int main(){
    string line;
    fstream file;
    file.open("Text.txt",ios::out);
    while(file){       //execute while file opened successfully
        getline(cin,line);
        if(line=="-1"){
            break;
        }
        file<<line<<endl;
    }
    file.close();


    //Encription
    ifstream fil;
    fil.open("Text.txt",ios::in);
    string data;
    fil.clear();
    fil.seekg(0);
        getline(fil,data);
    cout<<data<<endl;
    ofstream cipher;
    cipher.open("Cipher.txt",ios::out);
    int i=0; 
    int c;
    while(data[i]!='/'){ 
           if(data[i]==' '){
            //if space
            cipher<<' ';
            i++;
           }
           else{
           int l;
           int t=int(data[i]);
           l=(t+5)%127;
           cipher<<char(l);
           i++;
           }
        }
        cipher<<'1';
    fil.close();
    cipher.close();

    //Decription
    ifstream de;
    de.open("Cipher.txt",ios::in);
    string data2;
    de.clear();
    de.seekg(0);
        getline(de,data2);
    cout<<data2;
    ofstream dec;
    dec.open("Decr.txt",ios::out);
    i=0;
    while(data2[i]!='1'){
        if(data2[i]==' '){
            dec<<' ';
            i++;
        }
        else{
         int l;
         int t;
         l=int(data2[i]);     //cipher to ascii
         t=(l-5)%127;
         dec<<char(t);
         i++;
    }
    } 
    de.close();
    dec.close();
}
