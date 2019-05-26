#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=re*10+ch-'0',ch=getchar();
	return re;
}
inline void swap(int &a,int &b){int t=a;a=b;b=t;return;}
struct heap{
	int n,a[1000010];
	heap(){n=0;memset(a,0,sizeof(a));}
	inline void up(int k){
		if(k==1) return;
		if(a[k>>1]>a[k]){
			swap(a[k>>1],a[k]);
			up(k>>1);
		}
	}
	inline void down(int k){
		if((k<<1)>n) return;
		if((k<<1)==n){
			if(a[k<<1]<a[k]){
				swap(a[k],a[k<<1]);
				down(k<<1);
			}
			return;
		}
		if(a[k<<1]<a[k]){
			if(a[(k<<1)+1]<a[k<<1]){
				swap(a[k],a[(k<<1)+1]);
				down((k<<1)+1);
			}
			else{
				swap(a[k],a[k<<1]);
				down(k<<1);
			}
		}
		else if(a[(k<<1)+1]<a[k]){
			swap(a[k],a[(k<<1)+1]);
			down((k<<1)+1);
		}
	}
	inline void push(int k){
		a[++n]=k;
		up(n);
//		for(int i=1;i<=n;i++) cout<<a[i]<<endl;
	}
	inline void pop(){
		a[1]=a[n--];
		down(1);
//		for(int i=1;i<=n;i++) cout<<a[i]<<endl;
	}
	inline int top(){
		return a[1];
	}
	
}H;
int main(){
	int i,t1;
	int n;n=read();
//	cout<<"read n "<<n<<endl; 
	for(i=1;i<=n;i++){
//		cout<<"read in "<<i<<endl;
		t1=read();
		if(t1==1) H.push(read());
		if(t1==2) printf("%d\n",H.top());
		if(t1==3) H.pop();
	}	
}
