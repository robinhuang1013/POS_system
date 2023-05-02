#include<iostream>
#include<fstream>
#include"data.h"
#include"function.h"
using namespace std;

fstream productFile,totalFile;
product meal[4];
//===============================//

int main(){  
    productFile.open("data.txt",ios::in|ios::binary);
    for(int i=0;i<4;i++){
        productFile.read(reinterpret_cast<char * >(&meal[i]),sizeof(product));
    }
    menu();
    int choice=mod();
    while(choice==1){
        UI();
        int input;
        cout<<"input number:";
        cin>>input;
        meal[input-1].show();
        
        

    }
    productFile.close();
    system("pause");
    return 0;
}


//===============================//

