#include<iostream>
#include<fstream>
#include"data.h"
#include"function.h"
using namespace std;
using namespace user;
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
            fstream totalFile;
            totalFile.open("total.txt",ios::in);
            int temp;
            totalFile>>temp;
            temp=temp+total;
            totalFile.close();
            totalFile.open("total.txt",ios::out);
            totalFile<<temp<<endl;
            totalFile.close(); 
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
 
