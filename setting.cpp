#include<iostream>
#include<fstream>
#include"data.h"
//#include"function.h"
using namespace std;
int main(int argc, char const *argv[])
{
    product meal[4];
    ifstream Idata;
    ofstream Odata;
    
    Odata.open("data.txt",ios::binary);
    for(int i=0;i<4;i++){
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
    product temp[4];
    for(int i=0;i<4;i++){
        
        Idata.read(reinterpret_cast<char * >(&temp[i]),sizeof(product));
        temp[i].show();
    }
    
    
    Idata.close();
    system("pause");
    return 0;
}
