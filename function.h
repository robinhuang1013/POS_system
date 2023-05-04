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
		cout<<line<<endl;
		cout<<"one:name  two:name"<<endl;
		cout<<"three:name  four:name"<<endl;

	}
	void totalFun(int to){
		cout<<line<<endl;
		cout<<"total: "<<to<<endl;
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