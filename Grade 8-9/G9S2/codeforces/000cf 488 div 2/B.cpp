#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n,k;
struct node{
	ll a,c,ans,num;
}a[100010];
bool cmp1(node l,node r){
	return l.a<r.a;
}
bool cmp2(node l,node r){
	return l.num<r.num;
}
priority_queue<int>q;ll tmp[110];
int main(){
	n=read();k=read();ll i,j;
	for(i=1;i<=n;i++){
		a[i].a=read();a[i].num=i;
	}
	for(i=1;i<=n;i++){
		a[i].c=read();
	}
	sort(a+1,a+n+1,cmp1);
	for(i=1;i<=n;i++){
		a[i].ans=a[i].c;
//		cout<<i<<'\n';
		for(j=1;j<=min(k,i-1);j++){
			tmp[j]=q.top();q.pop();
			a[i].ans+=tmp[j];
		}
//		cout<<"half \n";
		for(j=1;j<=min(k,i-1);j++){
			q.push(tmp[j]);
		}
		q.push(a[i].c);
	}
	sort(a+1,a+n+1,cmp2);
	for(i=1;i<=n;i++){
		printf("%I64d ",a[i].ans);
	}
}
/*
4 1
1 2 3 4
1000 100 10 1

*/
