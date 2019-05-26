#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n,st[100010][17],d[100010],bin[100010],_bin[17];
int ans=0;
int len;
int _get(int l,int r){
	len=bin[r-l+1];
	return d[st[l][len]]<d[st[r-_bin[len]+1][len]]?st[l][len]:st[r-_bin[len]+1][len];
}
void dfs(int l,int r,int k)
{
	int pos=_get(l,r);ans+=d[pos]-k;
	if (pos>l) dfs(l,pos-1,d[pos]);
	if (pos<r) dfs(pos+1,r,d[pos]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&d[i]),st[i][0]=i;
	for (int i=2;i<=n;i++) bin[i]=bin[i>>1]+1;
	_bin[0]=1;for (int i=1;i<=16;i++) _bin[i]=_bin[i-1]<<1;
	for (int j=1;j<=16;j++) 
		for (int i=1;i<=n-_bin[j]+1;i++)
			st[i][j]=(d[st[i][j-1]]<d[st[i+_bin[j-1]][j-1]]?st[i][j-1]:st[i+_bin[j-1]][j-1]);
	dfs(1,n,0);
	cout<<ans;
	return 0;
}
