#include<iostream>
using namespace std;
#define line "========================================="
//===========================//
namespace user{
	void menu(){
		cout<<line<<endl;
		cout<<"  welcome  POS-Dos system"<<endl;
		cout<<"    start(1)      exit(0) "<<endl;
		
	}
	int mod(){
		int a;
		cin>>a;
		return a;
	}
	void UI(){
		cout<<line<<endl<<"1:name  2:name 3:name "<<endl<<"4:name  5:name 6:name"<<endl<<"7:name  8:name 9:name"<<endl;

	}
	void totalFun(int tempTotal,int frist){
		int temp=0,cash;
		if(frist==0){
			fstream totalFile;
        	totalFile.open("total.txt",ios::in);
			totalFile>>temp;
			temp=temp+tempTotal;           
			totalFile.close();
			totalFile.open("total.txt",ios::out);
			totalFile<<temp<<endl;
			totalFile.close();
		}
		
		cout<<line<<endl;
		cout<<"total: "<<tempTotal<<endl;
		cout<<"cash:";
		cin>>cash;
		if(cash>=tempTotal){
			cout<<"change: "<<cash-tempTotal<<endl;
		}else{
			return totalFun(tempTotal-cash,1);
		}
		
	}
	int discount(int num,int *ptr){
		if(num>3){
			cout<<"have cup"<<endl;
			cout<<" yes(1) no(0)"<<endl;
			int cup;
			cin>>cup;
			if(cup==1){
				*ptr+=1;
				return -5;
			}
			return 0;
		}
		return 0;
	}
	
}

//=======================================================//
namespace setting{
	void menu(){
		cout<<line<<endl;
		cout<<"welcome to setting "<<endl;
		cout<<"start(1) view(2) exit(0)"<<endl;
	}
}