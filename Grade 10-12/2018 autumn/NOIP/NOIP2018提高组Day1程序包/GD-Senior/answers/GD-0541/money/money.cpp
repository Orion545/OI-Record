#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=105;
int t,n,ans,temp,cnt,a[N],c[N],x,y,g,d[N];
bool b[N];
void dfs(int k,int s){
	if(s==0){
		d[k]=1;
		return;
	}
	for(int i=1;i<k;i++){
		if(c[i]>s)break;
		dfs(k,s-c[i]);
		if(d[k])break;
	}
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdin);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(b,0,sizeof(b));
		memset(d,0,sizeof(d));
		cnt=0;
		temp=0;
		ans=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++){
				if(a[j]%a[i]==0)b[j]=1;
			}
		for(int i=1;i<=n;i++)
			if(!b[i])c[++cnt]=a[i];
		for(int i=3;i<=cnt;i++)dfs(i,c[i]);
		for(int i=1;i<=cnt;i++)if(!d[i])ans++;
		printf("%d\n",ans);
	}
	return 0;
}
