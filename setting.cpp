#include<iostream>
#include<fstream>
#include"data.h"
#include"function.h"
using namespace std;
using namespace setting;

int main(){
    menu();
    int input;
    cout<<"input number:";
    cin>>input;
    cout<<line<<endl;
    if(input==2){
        view();
        return main();
    }else if(input==1){
        setPrice();
        view();
        return main();
    } 
    system("pause");
    return 0;
}
