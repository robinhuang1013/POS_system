#include<iostream>
#include<fstream>
#include"data.h"
#include"function.h"
using namespace std;

//===============================//


int main(){
    product p[4];
    fstream test;
    test.open("data.txt",ios::in|ios::binary);
    for(int i=0;i<4;i++){
        test.read(reinterpret_cast<char *>(&p[i]),sizeof(product));
        p[i].show();
    }
    test.close();
    
    system("pause");
    return 0;
}


//===============================//




