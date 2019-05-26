#include<bits/stdc++.h>
using namespace std;
class cdate{
	public:
		cdate(){
			y=2000;m=1;d=1;
			cout<<"执行初始化函数"<<endl;
		}
		cdate(int a,int b,int c){
			y=a;m=b;d=c;
			cout<<"执行构造函数"<<endl;
		}
		~cdate(){
			cout<<"执行析构函数"<<endl;
		} 
		void run(){
			if((y%4==0&&y%100!=0)||(y%400==0)) cout<<y<<"年是闰年";
			else cout<<y<<"年不是闰年"; 
			cout<<endl; 
		}
		void print(){
			cout<<y<<"年"<<m<<"月"<<d<<"日"<<endl;
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
