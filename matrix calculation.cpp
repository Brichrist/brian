#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
class matriks{
	private:
		int no1;
		int no2;
		int no3;
		int no4;
	public:
		matriks(){
			no1=0;
			no2=0;
			no3=0;
			no4=0;
			cout<<"woi"<<endl;
		}
		~matriks(){
			cout<<"Open Our Vision and Encourage Ourself"<<endl;
		}
		void seta(int a){
			this->no1=a;
		}
		void setb(int b){
			this->no2=b;
		}
		void setc(int c){
			this->no3=c;
		}
		void setd(int d){
			this->no4=d;
		}
		int get1(){
			return no1;
		}
		int get2(){
			return no2;
		}
		int get3(){
			return no3;
		}
		int get4(){
			return no4;
		}	
};


int main(){
	matriks A,B,C;
	int choose,a,b,c,d;
	do{
		cout<<"BlueJack Calculation Matrix 2 Dimension\n";
		cout<<"==========================================\n";
		cout<<"1. Input Matrix\n";
		cout<<"2. Calculate your Matrix\n";
		cout<<"3. Exit\n";
		do{
			cout<<"choose:";
			cin>>choose;
		}while(choose<1||choose>3);
		
		switch(choose){
			case 1:
			{
				cout<<"Input Matrix 1"<<endl;
				cout<<"================="<<endl;
				do{
					cout<<"Input Number 1 [0..9]:";
					cin>>a;
				}while(a<0||a>9);
				do{
					cout<<"Input Number 2 [0..9]:";
					cin>>b;
				}while(b<0||b>9);
				do{
					cout<<"Input Number 3 [0..9]:";
					cin>>c;
				}while(c<0||c>9);
				do{
					cout<<"Input Number 4 [0..9]:";
					cin>>d;
				}while(d<0||d>9);
				A.seta(a);
				A.setb(b);
				A.setc(c);
				A.setd(d);
				cout<<"| " <<A.get1()<<"\t"<<A.get2()<<"|\n";
				cout<<"| " <<A.get3()<<"\t"<<A.get4()<<"|\n";
				cout<<"Input Matrix 2\n";
				cout<<"=================\n";
				do{
					cout<<"Input Number 1 [0..9]:";
					cin>>a;
				}while(a<0||a>9);
				do{
					cout<<"Input Number 2 [0..9]:";
					cin>>b;
				}while(b<0||b>9);
				do{
					cout<<"Input Number 3 [0..9]:";
					cin>>c;
				}while(c<0||c>9);
				do{
					cout<<"Input Number 4 [0..9]:";
					cin>>d;
				}while(d<0||d>9);
				B.seta(a);
				B.setb(b);
				B.setc(c);
				B.setd(d);
				cout<<"|"<<B.get1()<<"\t"<<B.get2()<<"|\n";
				cout<<"|"<<B.get3()<<"\t"<<B.get4()<<"|\n\n\n";
				cout<<"|"<<A.get1()<<"\t"<<A.get2()<<"|\t\t|"<<B.get1()<<"\t"<<B.get2()<<"|\n";
				cout<<"|"<<A.get3()<<"\t"<<A.get4()<<"|\t\t|"<<B.get3()<<"\t"<<B.get4()<<"|\n";
				break;
			}
			case 2:
			{
				cout<<"Calculating Matrix Result:\n";
				a=(A.get1()*B.get1())+(A.get2()*B.get3());
				b=(A.get1()*B.get2())+(A.get2()*B.get4());
				c=(A.get3()*B.get1())+(A.get4()*B.get3());
				d=(A.get3()*B.get2())+(A.get4()*B.get4());
				C.seta(a);
				C.setb(b);
				C.setc(c);
				C.setd(d);
				cout<<"|"<<A.get1()<<"\t"<<A.get2()<<"|\tx\t|" <<B.get1()<<"\t"<< B.get2()<<"|\t=\t|"<<C.get1()<<"\t"<<C.get2()<<"|\n";
				cout<<"|"<<A.get3()<<"\t"<<A.get4()<<"|\t \t|" <<B.get3()<<"\t"<< B.get4()<<"|\t \t|"<<C.get3()<<"\t"<<C.get4()<<"|\n";
				break;
			}
			case 3:{
				break;
			}
		}
	}while(choose!=3);
}
