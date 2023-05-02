#include<iostream>
using namespace std;
//=========================================//

class product
{

private:
    int number;
    int price;
    
public:
    void show();
    void setNumber_andPrice(int,int);
    int getPrice();
    int getNumber();
    product();
};

product::product(){
        number=0;
        price=0;
    }


void product::show(){
    cout<<"number:"<<number<<", price"<<price<<endl;
}
void product::setNumber_andPrice(int a,int b){
     number=a; 
     price=b;
  
}
int product::getNumber(){
    return number;
}
int product::getPrice(){
    return price;
}

