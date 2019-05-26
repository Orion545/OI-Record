#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

#define N (100000+5)

using namespace std;

int n,i,j,top,ans;
int fa[N],st[N],d[N];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	top=0;
	for (i=1;i<=n;i++){
		scanf("%d",&d[i]);
		j=top;
		while (j>0&&d[i]<d[st[j]]) j--;
		if (j<top) 	fa[st[j+1]]=i;
		fa[i]=st[j];
		st[++j]=i;
		top=j;
	}
	for (i=1;i<=n;i++)
		ans+=d[i]-d[fa[i]];
	printf("%d\n",ans);
	return 0;
}
