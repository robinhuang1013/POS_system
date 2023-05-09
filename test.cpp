#include<iostream>
#include<fstream>
#include"data.h"
#include"function.h"
using namespace std;
using namespace user;


//===============================//

int main(){
    fstream productFile; 
    product meal[Max];
    productFile.open("data.txt",ios::in|ios::binary);
    for(int i=0;i<Max;i++){
        productFile.read(reinterpret_cast<char * >(&meal[i]),sizeof(product));
        meal[i].show();
    }
    productFile.close();
    menu();
    int choice=mod();
    int total=0;
    int tempCount[Max]={0};
    int * disptr=new int(0);
    while(choice==1){
        UI();
        int input;
        cout<<"input number:";
        cin>>input;
        cout<<line<<endl;
        if(input==0){           
            for(int i=0;i<Max;i++){
                if(tempCount[i]!=0){
                    cout<<"meal "<<i+1<<" have "<<tempCount[i]<<endl;
                }
                tempCount[i]=0;
                
            }
            cout<<"cup discount: "<<*disptr<<endl;
            totalFun(total);
             
            total=0;
            *disptr=0;
        }else if(input==999){
            break;
        }else if(input>0&&input<10){
            total=total+meal[input-1].getPrice();
            meal[input-1].changCount();
            productFile.open("data.txt",ios::out|ios::binary);
            for (int i = 0; i < 9; i++){
                productFile.write(reinterpret_cast<char*>(&meal[i]),sizeof(product));
            }
            tempCount[input-1]+=1;
		    productFile.close();
            total+=discount(input, disptr);
        }else{
            cout<<"1~9"<<endl;
        }
        
    }
    delete disptr;  
    system("pause");
    return 0;
}


//=============================//
 
