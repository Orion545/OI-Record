#include<bits/stdc++.h>
using namespace std;
class A{
	public:
		A(){
			x=0;
			cout<<"ִ��A��ʼ������"<<endl;
		}
		A(int m){
			x=m;
			cout<<"ִ��A���캯��"<<endl;
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
			cout<<"ִ��B��ʼ������"<<endl;
		}
		B(int m,int n){
			x=m;
			y=n;
			cout<<"ִ��B���캯��"<<endl;
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
