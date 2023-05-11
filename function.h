#include<iostream>
using namespace std;
#define line "========================================="
#define Max 5
#define discountNumber -5
//===========================//
namespace user{

	

	void open(){
		cout<<line<<endl;
		cout<<"  welcome  POS-Dos system"<<endl;
		cout<<"    start(1)      exit(0) "<<endl;
		
	}
	int mod(){
		int a;
		cin>>a;
		return a;
	}
	void menu(){
		cout<<endl<<endl<<endl<<line<<endl;
		cout << "+---+------------------+-----------+" << endl;
		cout << "| # |      Name        |   price   |" << endl;
		cout << "+---+------------------+-----------|" << endl;
		cout << "| 1 | Ice              |     15    |" << endl;
		cout << "| 2 | Pancake          |     45    |" << endl;
		cout << "| 3 | Pancake_Icecream |     59    |" << endl;
		cout << "| 4 | MilkTea          |     45    |" << endl;
//		cout << "| 5 | Tea              |     30    |" << endl;
//		cout << "| 6 | Combo_ice_MilkTea|     99    |" << endl;
//		cout << "| 7 | Combo_ice_Tea    |     85    |" << endl;
//		cout << "| 8 | Combo_pan_MilkTea|     79    |" << endl;
//		cout << "| 9 | Combo_pan_Tea    |     70    |" << endl;
		cout << "+---+------------------+-----------+" << endl;
		cout<<line<<endl;

	}
	int order(){
		int input;
        cout<<"input number:";
        cin>>input;
        cout<<line<<endl;
		return input;
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
		if(tempTotal!=0){
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
		
		
	}
	int discount(int num,int *ptr){
		if(num>3){
			cout<<"have cup"<<endl;
			cout<<" yes(1) no(0)"<<endl;
			int cup;
			cin>>cup;
			if(cup==1){
				*ptr+=1;
				return discountNumber;
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
	void view(){
		ifstream Idata;
		product meal[Max];
		Idata.open("data.txt",ios::binary);
        for(int i=0;i<Max;i++){
            Idata.read(reinterpret_cast<char * >(&meal[i]),sizeof(product));
            meal[i].show();  
        }  
        Idata.close();
	}
	void setPrice(){
		ofstream Odata;
		product meal[Max];
		cout<<"Please do not end the program midway!!!!!"<<endl;
        Odata.open("data.txt",ios::binary);
        for(int i=0;i<Max;i++){
            int a;
            cout<<"number:"<<i+1<<" price:";
            cin>>a;
            cout<<endl;
            meal[i].setNumber_andPrice(i+1,a);
            Odata.write( reinterpret_cast<char * > (&meal[i]),sizeof(product));
        }
        Odata.close();
        system("pause");
	}
}
//===========================================================================//

namespace reset{
	void menu(){
		int check;
		cout<<"are you sure to reset file and data?"<<endl;
		cout<<" yes(1)  no(0)"<<endl;
		cin>>check;
		if(check==0){
			system("pause");
			exit(0);
		}
	}
	void totalFile_reset(){
		fstream totalFile;
		int temp;
		totalFile.open("total.txt",ios::out);
		temp=0;
		cout<<"total.txt="<<temp<<endl;
		cout<<"============================================="<<endl;
		totalFile<<temp;
		totalFile.close();
		cout<<"the daily file is reset"<<endl;
	}
	void productFile_reset(){
		 product meal[Max]; 
   		 fstream productFile;
		productFile.open("data.txt",ios::in|ios::binary);
		for(int i=0;i<Max;i++){
			productFile.read(reinterpret_cast<char *>(&meal[i]),sizeof(product));
			meal[i].show();
		}
		productFile.close();
		cout<<"============================================="<<endl;
		productFile.open("data.txt",ios::out|ios::binary);
		for (int i = 0; i < Max; i++)
		{
			meal[i].resetCount();
			productFile.write(reinterpret_cast<char* >(&meal[i]),sizeof(product));
			meal[i].show();
		}
		productFile.close();
	}
}
