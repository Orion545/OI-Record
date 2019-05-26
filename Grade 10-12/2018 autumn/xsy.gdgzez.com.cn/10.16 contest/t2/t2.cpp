#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int r,c,n,cnt;
struct node{
	int x,y,t,id;
	node(){};
	node(int xx,int yy,int ii){
		x=xx;y=yy;id=ii;
		if(x==0) t=1;
		else if(y==0) t=2;
		else if(x==r) t=3;
		else if(y==c) t=4;
	}
}a[1000010];
inline bool cmp(node l,node r){
	if(l.t!=r.t) return l.t<r.t;
	else{
		if(l.t==1) return l.y>r.y;
		if(l.t==2) return l.x<r.x;
		if(l.t==3) return l.y<r.y;
		if(l.t==4) return l.x>r.x;
	}
}
int s[1000010],top;
int main(){
	r=read();c=read();n=read();int i,t1,t2,t3,t4;
	for(i=1;i<=n;i++){
		t1=read();t2=read();t3=read();t4=read();
		if((t1==0||t2==0||t1==r||t2==c)&&(t3==0||t4==0||t3==r||t4==c)){
			a[++cnt]=node(t1,t2,i);
			a[++cnt]=node(t3,t4,i);
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(i=1;i<=cnt;i++){
		if(s[top]==a[i].id) top--;
		else s[++top]=a[i].id;
	}
	if(!top) puts("YES");
	else puts("NO");
}
