#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
int aa[100100],final[8001000]; 
queue<int>a,b,c,x,y,z;
int n,m,q,u,v,t,l=0,len;
double p;
bool cmp(int l,int r){
	return l>r;
}
int main(){
	freopen("earthworm10.in","r",stdin);
	freopen("earthworm10.out","w",stdout);
	int i,j,tt,maxn,tmp;
	scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
	p=((double)u)/((double)v);
//	cout<<p<<endl;
	for(i=1;i<=n;i++){
		scanf("%d",&tt);
		aa[i]=tt;
	}
	sort(aa+1,aa+n+1,cmp);
	for(i=1;i<=n;i++) a.push(aa[i]);
	for(i=1;i<=n;i++) x.push(0);
	for(i=1;i<=m;i++){
//		cout<<"i = "<<i<<endl;
//		queue<int>ttmp;
//		ttmp=a;
//		while(!ttmp.empty()){
//			cout<<ttmp.front()<<ends;ttmp.pop();
//		}
//		cout<<endl;
//		ttmp=b;
//		while(!ttmp.empty()){
//			cout<<ttmp.front()<<ends;ttmp.pop();
//		}
//		cout<<endl;
//		ttmp=c;
//		while(!ttmp.empty()){
//			cout<<ttmp.front()<<ends;ttmp.pop();
//		}
//		cout<<endl;
		maxn=-1;
		if(!a.empty()&&maxn<a.front()+l-q*x.front()){
			maxn=a.front()+l-q*x.front();tmp=1;
		}
		if(!b.empty()&&maxn<b.front()+l-q*y.front()){
			maxn=b.front()+l-q*y.front();tmp=2;
		}
		if(!c.empty()&&maxn<c.front()+l-q*z.front()){
			maxn=c.front()+l-q*z.front();tmp=3;
		}
//		cout<<a.front()+l<<ends<<b.front()+l<<ends<<c.front()+l<<endl;
		switch(tmp){
			case 1:a.pop();x.pop();break;
			case 2:b.pop();y.pop();break;
			case 3:c.pop();z.pop();break;
		}
		b.push(floor(((double)maxn)*p));c.push(maxn-floor(((double)maxn)*p));
		y.push(i);z.push(i);
		if(!(i%t)) printf("%d ",maxn);
		l+=q;
	}
	len=0;
	while(!a.empty()){
		final[++len]=a.front()+l;a.pop();
	}
	while(!b.empty()){
		final[++len]=b.front()+l-q*y.front();b.pop();y.pop(); 
	}
	while(!c.empty()){
		final[++len]=c.front()+l-q*z.front();c.pop();z.pop();
	}
	cout<<endl;
	sort(final+1,final+len+1,cmp);
	for(i=t;i<=len;i+=t) printf("%d ",final[i]);
}
