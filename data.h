#include<iostream>
using namespace std;
//=========================================//

class product
{

private:
    int number;
    int price;
    int count;

    
public:
    void show();
    void setNumber_andPrice(int,int);
    void resetCount();
    void changCount();
    int getPrice();
    int getNumber();
    int getCount();
    product();
    
};

product::product(){
        number=0;
        price=0;
        count=0;
}

void product::show(){
    cout<<" number:"<<number<<", price:"<<price<<" ,count:"<<count<<endl;
}
void product::setNumber_andPrice(int a,int b){
    number=a; 
    price=b;
    
}

void product::resetCount()
{
    count=0;
}
void product::changCount(){
    count=count+1;
}
int product::getNumber(){
    return number;
}
int product::getPrice(){
    return price;
}
int product::getCount(){
    return count;
}
/*
number:1, price:15 ,count:0
number:2, price:45 ,count:0
number:3, price:59 ,count:0
number:4, price:30 ,count:0 c
number:5, price:45 ,count:0 c
number:6, price:70 ,count:0 c
number:7, price:79 ,count:0 c
number:8, price:85 ,count:0 c
number:9, price:99 ,count:0 c
*/