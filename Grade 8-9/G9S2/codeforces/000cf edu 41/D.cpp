#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
double x[100010],y[100010];
bool e(double l,double r){
	return abs(l-r)<(1e-6);
}
bool same(double x1,double y1,double x2,double y2,double x3,double y3){
	double p1=x2-x1,p2=x3-x1,q1=y2-y1,q2=y3-y1;
	return p1*q2==p2*q1;
}
vector<int>s;
int main(){
	int n=read(),i,t;double tmp;
	for(i=1;i<=n;i++){
		x[i]=read();y[i]=read();
	}
	for(i=3;i<=n;i++){
		if(!same(x[1],y[1],x[2],y[2],x[i],y[i])) break;
	}
	t=i;int flag;
	for(i=3;i<=n;i++){
		if(i==t) continue;
		if(!same(x[1],y[1],x[2],y[2],x[i],y[i])) s.push_back(i);
	}
	flag=1;
	for(i=1;i<s.size();i++){
		if(!same(x[t],y[t],x[s[0]],y[s[0]],x[s[i]],y[s[i]])){
			flag=0;break;
		}
	}
	if(flag){
		printf("YES");return 0;
	}
//	cout<<"***********************"<<endl;
	s.clear();
	for(i=3;i<=n;i++){
		if(i==t) continue;
		if(!same(x[1],y[1],x[t],y[t],x[i],y[i])) s.push_back(i);
	}
	flag=1;
	for(i=1;i<s.size();i++){
		if(!same(x[2],y[2],x[s[0]],y[s[0]],x[s[i]],y[s[i]])){
			flag=0;break;
		}
	}
	if(flag){
		printf("YES");return 0;
	}
//	cout<<"***********************"<<endl;
	s.clear();
	for(i=3;i<=n;i++){
		if(i==t) continue;
		if(!same(x[t],y[t],x[2],y[2],x[i],y[i])) s.push_back(i);
	}
	flag=1;
	for(i=1;i<s.size();i++){
		if(!same(x[1],y[1],x[s[0]],y[s[0]],x[s[i]],y[s[i]])){
			flag=0;break;
		}
	}
	if(flag){
		printf("YES");return 0;
	}
//	cout<<"***********************"<<endl;
	printf("NO");
}
