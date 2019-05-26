#include<algorithm>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<iostream>
using namespace std;
#define fo(i,a,b) for(i=a;i<=b;i++)
#define rep(i,x) for(i=la[x];i;i=ne[i])
const int N=5003;
struct arr{int x,y;}a[N];
int s[N][N],la[N],ne[N*2],da[N*2],T[N],ans[N];
int n,m,i,j,sum,Px,Py,de;
bool P;
int read(){
	char c=getchar();int x=0;
	for(;'0'>c||'9'<c;c=getchar());
	for(;'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
	return x;
}
void ins(int x,int y){
	da[++sum]=y;ne[sum]=la[x];la[x]=sum;
	da[++sum]=x;ne[sum]=la[y];la[y]=sum;
}
void doit(int x,int fa){
	T[de]=x;
	if(T[de]<ans[de]) P=1;
	if(P) ans[de]=T[de];
	else if(T[de]>ans[de]) return;
	int i,y;
	fo(i,1,s[x][0]){
		y=s[x][i];if(y==fa) continue;
		if(((x!=Px)&&(x!=Py))||((y!=Px)&&(y!=Py))) de++,doit(y,x);
		if(T[de]>ans[de]) return;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	n=read(),m=read();
	fo(i,1,m){
		a[i].x=read(),a[i].y=read();
		ins(a[i].x,a[i].y);
	}
	fo(i,1,n){
		rep(j,i) s[i][++s[i][0]]=da[j];
		sort(s[i]+1,s[i]+s[i][0]+1);
	}
	memset(ans,127,sizeof(ans));
	if(m==n){
		fo(i,1,m){
			Px=a[i].x,Py=a[i].y;
			P=0;de=1;doit(1,0);
		}
	}else P=0,de=1,doit(1,0);
	fo(i,1,n) printf("%d ",ans[i]);
	printf("\n");
}
