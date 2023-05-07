#include<iostream>
#include<fstream>
#include"data.h"
using namespace std;
int main(){
    product meal[9];
    int temp;
    fstream totalFile,productFile;
    int check;
    cout<<"are you sure to reset file and data?"<<endl;
    cout<<" yes(1)  no(0)"<<endl;
    cin>>check;
    if(check==0){
        return 0;
    }
    totalFile.open("total.txt",ios::out);
    temp=0;
    cout<<"total.txt="<<temp<<endl;
    cout<<"============================================="<<endl;
    totalFile<<temp;
    totalFile.close();
    cout<<"the daily file is reset"<<endl;
    productFile.open("data.txt",ios::in|ios::binary);
    for(int i=0;i<9;i++){
        productFile.read(reinterpret_cast<char *>(&meal[i]),sizeof(product));
        meal[i].show();
    }
    productFile.close();
    cout<<"============================================="<<endl;
    productFile.open("data.txt",ios::out|ios::binary);
    for (int i = 0; i < 9; i++)
    {
        meal[i].resetCount();
        productFile.write(reinterpret_cast<char* >(&meal[i]),sizeof(product));
        meal[i].show();
    }
    productFile.close();
    system("pause");

    
    return 0;
}