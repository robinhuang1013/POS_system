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
