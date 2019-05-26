#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=5e3+5;
int f[maxn][maxn],a[maxn],d[maxn],bz[maxn],b[maxn];
int num,n,m,i,t,j,k,l,x,y,z;
void dg(int x,int y){
	int i;bz[x]=++num;d[num]=x;
	for (i=1;i<=f[x][0];i++){
		if (f[x][i]==y) continue;
		if (!bz[f[x][i]]) dg(f[x][i],x);
		else{
			if (a[0]) continue;
			for (i=bz[f[x][i]];i<=bz[x];i++) a[++a[0]]=d[i],bz[d[i]]=-1;
		}
	}
}
void dg1(int x,int y){
	int i;d[++num]=x;
	for (i=1;i<=f[x][0];i++){
		if (f[x][i]==y) continue;
		dg1(f[x][i],x);
	}
}
int main(){
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)scanf("%d%d",&x,&y),f[x][++f[x][0]]=y,f[y][++f[y][0]]=x;
	for (i=1;i<=n;i++) sort(f[i]+1,f[i]+f[i][0]+1);
	if (n==m){
		num=0;dg(1,0);
		if (a[2]>a[a[0]]){b[1]=a[1];
			for (i=a[0];i>=2;i++) b[a[0]-i+2]=a[i];
			swap(a,b);
		}
		for (i=2;i<a[0];i++){
			x=a[i];
			if (f[x][f[x][0]]==a[i+1] || f[x][f[x][0]-1]==a[i+1] && f[x][f[x][0]]==a[i-1])
				if (a[i+1]>a[a[0]]){
					for (j=1;j<=f[x][0];j++)
						if (f[x][j]==a[i+1]) f[x][j]=1e9;
					sort(f[x]+1,f[x]+f[x][0]+1);f[x][0]--;
					x=a[i+1];
					for (j=1;j<=f[x][0];j++)
						if (f[x][j]==a[i]) f[x][j]=1e9;
					sort(f[x]+1,f[x]+f[x][0]+1);f[x][0]--;
					break;
				}
		}
	}
	num=0,dg1(1,0);
	for (i=1;i<=n;i++) printf("%d ",d[i]);
}
