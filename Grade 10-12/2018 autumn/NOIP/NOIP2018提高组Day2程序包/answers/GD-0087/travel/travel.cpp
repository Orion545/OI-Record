#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fod(i,a,b) for(i=a;i>=b;i--)
#define rep(i,a) for(i=first[a];i;i=next[i])
using namespace std;
const int maxn=5007;
int i,j,k,l,t,n,m,ans,num,x,y;
int first[maxn*2],last[maxn*2],next[maxn*2];
int a[maxn][maxn],yi,er,tou,d[maxn],an[maxn],dfx;
bool bz[maxn],az;
void add(int x,int y){
    last[++num]=y,next[num]=first[x],first[x]=num;
}
void dfs1(int x,int y){
    int i;
    if(tou)return;
    if(bz[x]){az=1;tou=x;return;}bz[x]=1;
    rep(i,x)if(last[i]!=y)dfs1(last[i],x);
    if(az)d[++d[0]]=x;if(tou==x)az=0;
}
void dfs(int x,int y){
	int i;
	if(x==yi&&y==er||x==er&&y==yi||t==2)return;
	dfx++;
	if(t==0&&an[dfx]<x)t=2;
	if(t==0&&an[dfx]>x)t=1;
	if(t==1)an[dfx]=x;
	rep(i,x)if(last[i]!=y)dfs(last[i],x);
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d%d",&n,&m);
    fo(i,1,n)an[i]=n+1;
    fo(i,1,m){
	    scanf("%d%d",&x,&y);
	    a[x][++a[x][0]]=y,a[y][++a[y][0]]=x;
	}
	fo(i,1,n)sort(a[i]+1,a[i]+a[i][0]+1);
	fo(i,1,n)fod(j,a[i][0],1)add(i,a[i][j]);dfx=0;
	if(m==n){
		dfs1(1,0);
	    fo(i,1,d[0]-1){
		    yi=d[i],er=d[i+1];
		    t=0;dfx=0;dfs(1,0);
		}
		yi=d[1],er=d[d[0]];t=0;dfx=0;dfs(1,0);
	}
	else dfs(1,0);
	fo(i,1,n)printf("%d ",an[i]);
}
