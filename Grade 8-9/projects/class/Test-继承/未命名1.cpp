#include<bits/stdc++.h>
using namespace std;
class A{
	public:
		A(){
			x=0;
			cout<<"执行A初始化函数"<<endl;
		}
		A(int m){
			x=m;
			cout<<"执行A构造函数"<<endl;
		}
		void print(){
			cout<<x<<" ";
		}
	protected:
		int x;
};
class B:public A{
	public:
		B(){
			x=0;
			y=0;
			cout<<"执行B初始化函数"<<endl;
		}
		B(int m,int n){
			x=m;
			y=n;
			cout<<"执行B构造函数"<<endl;
		}
		void print(){
			cout<<x<<" "<<y<<endl;
		}
	private:
		int y;
};
int main(){
	B n;
	n=B(1,2);
	n.print();
}
