#include<iostream>
using namespace std;
#define line "========================================="
#define Max 10
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
		cout << "+---+------------------+-----------+" << endl;
		cout << "| # |      Name        |   price   |" << endl;
		cout << "+---+------------------+-----------|" << endl;
		cout << "| 1 | Ice              |     15    |" << endl;
		cout << "| 2 | Pancake          |     45    |" << endl;
		cout << "| 3 | Pancake_Icecream |     59    |" << endl;
		cout << "| 4 | MilkTea          |     45    |" << endl;
		cout << "| 5 | Tea              |     30    |" << endl;
		cout << "| 6 | Combo_ice_MilkTea|     99    |" << endl;
		cout << "| 7 | Combo_ice_Tea    |     85    |" << endl;
		cout << "| 8 | Combo_pan_MilkTea|     79    |" << endl;
		cout << "| 9 | Combo_pan_Tea    |     70    |" << endl;
		cout << "+---+------------------+-----------+" << endl;
		cout<<line<<endl;

	}
	void savetotal_chang(int tempTotal,int frist){
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
			return savetotal_chang(tempTotal-cash,1);
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
