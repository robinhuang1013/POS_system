#include<iostream>
#include<fstream>
#include"data.h"
#include"function.h"
using namespace std;
using namespace setting;

int main(){
    product meal[9];
    ifstream Idata;
    ofstream Odata;
    menu();
    int a;
    cin>>a;
    if(a==2){
        Idata.open("data.txt",ios::binary);
        for(int i=0;i<9;i++){
            Idata.read(reinterpret_cast<char * >(&meal[i]),sizeof(product));
            meal[i].show();  
        }  
        Idata.close();
        return main();
    }else if(a==1){
        cout<<"Please do not end the program midway!!!!!"<<endl;
        Odata.open("data.txt",ios::binary);
        for(int i=0;i<9;i++){
            int a;
            cout<<"number:"<<i+1<<" price:";
            cin>>a;
            cout<<endl;
            meal[i].setNumber_andPrice(i+1,a);
            Odata.write( reinterpret_cast<char * > (&meal[i]),sizeof(product));
        }
        Odata.close();
        system("pause");
        Idata.open("data.txt",ios::binary);
        for(int i=0;i<9;i++){
            Idata.read(reinterpret_cast<char * >(&meal[i]),sizeof(product));
            meal[i].show();  
        }  
        Idata.close();
        return main();
    } 
    system("pause");
    return 0;
}
