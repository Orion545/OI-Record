#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define ri register int
#define N 5005
#define M 10005
using namespace std;

int i,j,k,l,m,n,arr,bian[N][N],ex[N];

int gi()
{
	int res,w=1;
	char ch;
	while(ch=getchar(),ch<'0'||ch>'9')if(ch=='-')w=-1;
	res=ch-48;
	while(ch=getchar(),ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+ch-48;
	return res*w;
}
int dfs(int x,int fa){
	int l=bian[x][0];
	for(ri i=1;i<=l;i++){
		arr=bian[x][i];
		if(arr==fa||ex[arr])continue;
		ex[arr]=1;
		printf("%d ",arr);
		dfs(arr,x);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=gi(),m=gi();
		for(ri i=1;i<=m;i++){
			j=gi(),k=gi();
			l=++bian[j][0];
			bian[j][l]=k;
			l=++bian[k][0];
			bian[k][l]=j;
		}
		for(ri i=1;i<=n;i++)sort(bian[i]+1,bian[i]+bian[i][0]+1);
		printf("%d ",1);
		ex[1]=0;
		dfs(1,0);
	return 0;
}
