#include<bits/stdc++.h>
using namespace std;
class cdate{
	public:
		cdate(){
			y=2000;m=1;d=1;
			cout<<"ִ�г�ʼ������"<<endl;
		}
		cdate(int a,int b,int c){
			y=a;m=b;d=c;
			cout<<"ִ�й��캯��"<<endl;
		}
		~cdate(){
			cout<<"ִ����������"<<endl;
		} 
		void run(){
			if((y%4==0&&y%100!=0)||(y%400==0)) cout<<y<<"��������";
			else cout<<y<<"�겻������"; 
			cout<<endl; 
		}
		void print(){
			cout<<y<<"��"<<m<<"��"<<d<<"��"<<endl;
		}
		private:
			int y,m,d;
}; 
int main(){
	cdate d1;
	cdate d2;
	d2=cdate(2015,10,1);
	d1.print();d1.run();
	d2.print();d2.run();
	return 0;
}
