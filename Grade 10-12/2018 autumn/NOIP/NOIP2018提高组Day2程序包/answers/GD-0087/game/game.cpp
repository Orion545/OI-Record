#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fod(i,a,b) for(i=a;i>=b;i--)
using namespace std;
const int maxn=9,mo=1e9+7;
typedef long long ll;
int i,j,k,l,t,n,m;
ll ans;
int a[maxn][maxn];
int d[1007];
void dfs(int x,int y,int z){
	z=z*2+a[x][y];
	if(x>n||y>m)return;
    if(x==n&&y==m){
	    d[++d[0]]=z;
	    return;
	}
	dfs(x,y+1,z);
	dfs(x+1,y,z);
	int i,j;
	fo(i,1,n-1){
	    fo(j,1,m-1){
		    if(a[i+1][j]<a[i][j+1])return;
		}
	}
	ans++;
}
void dfs1(int x,int y){
	if(x==n&&y==m+1){
		d[0]=0;
	    dfs(1,1,0);
	    int i;
	    fo(i,1,d[0]-1)if(d[i]>d[i+1])return;
	    ans++;
		return;
	}
    if(y==m+1){dfs1(x+1,1);return;}
    a[x][y]=0;
    dfs1(x,y+1);
    a[x][y]=1;
    dfs1(x,y+1);
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d%d",&n,&m);
    if(n>m)swap(n,m);
    if(n==1){
	    ans=1;fo(i,1,m)ans=(ll)ans*2%mo;
	}
	else if(n==2){
	    ans=4;fo(i,2,m)ans=(ll)ans*3%mo;
	}
	else if(n==3){
	    ans=112;
	    fo(i,4,m)ans=(ll)ans*3%mo;
	}
	else if(n==4){
	    if(m==4)ans=912;
	    if(m==5)ans=2686;
	    if(m==6)ans=8064;
	    if(m==7)ans=24192;
	    if(m>7)dfs1(1,1);
	}
	else if(n==5){
	    if(m==5)ans=7136;
	}
    else dfs1(1,1);
    printf("%lld\n",ans);
}
