#include<iostream>
#include<fstream>
#include"data.h"
#include"function.h"
using namespace std;

fstream productFile;
product meal[9];
//===============================//

int main(){  
    productFile.open("data.txt",ios::in|ios::binary);
    for(int i=0;i<9;i++){
        productFile.read(reinterpret_cast<char * >(&meal[i]),sizeof(product));
        meal[i].show();
    }
    productFile.close();
    menu();
    int choice=mod();
    int total=0;
    while(choice==1){
        UI();
        int input;
        cout<<"input number:";
        cin>>input;
        if(input==0){ 
            totalFun(total);
            total=0;
        }else if(input==999){
            break;
        } 
        total=total+meal[input-1].getPrice();
        meal[input-1].changCount();    
    }
    
    system("pause");
    return 0;
}


//=============================//
 