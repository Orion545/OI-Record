#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7fffffff
using namespace std;
class bt{
	public:
	int data;
	bt *l=NULL,*r=NULL;
}a[100001];
void inst(int k,bt &node,int num){
	if(k<=node.data){
		cout<<"*1"<<endl;
		if(node.l==NULL){
			cout<<"**1";
			node.l=&a[num];cout<<"***"<<endl;return;
		}
		else{
			cout<<"**2"<<endl;inst(k,*node.l,num);
		}
	}
	else{
		cout<<"*2"<<endl;
		if(node.r==NULL){
			cout<<"**3";
			node.r=&a[num];cout<<"***"<<endl;return;
		}
		else{
			cout<<"**4"<<endl;inst(k,*node.r,num);
		}
	}
}
int main(){
	int n;cin>>n;
	int t;
	for(int i=1;i<=n;i++){
		cin>>t;a[i].data=t;
	} 
	for(int i=2;i<=n;i++){
		cout<<i<<endl;
		inst(a[i].data,a[1],i);
	}
} 
