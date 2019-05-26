#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#define ll long long
const int N=1e5+50;
using namespace std;
int n,m;
int x,y;
int a,b,l,r;
int ans=0,num,now;
char s[N];
int p[N];
bool vis[N],f[N];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m); scanf("%s",s);
	for (int i=1;i<=n;i++)
	  scanf("%d",&p[i]);
	for (int i=1;i<n;i++)
	  scanf("%d%d",&x,&y);
	for (int i=1;i<=m;i++){
	  scanf("%d%d%d%d",&a,&l,&b,&r);
	  ans=0; now=0;
	  memset(f,false,sizeof(f));
	  memset(vis,false,sizeof(vis));
	  if (abs(a-b)==1&&l==0&&r==0) {
	  	puts("-1");
	  	continue;
	  }
	  if (l==1) vis[a]=true,ans+=p[a];
	  if (r==1) vis[b]=true,ans+=p[b];
	  if (l==0) f[a]=true; if (r==0) f[b]=true; 
	  if (s[0]=='A') {
	  	for (int j=1;j<=n;j++){
	  	  for (int j=1;j<n;j++){
	    if (vis[j]||vis[j+1]) continue;
	    else {
	      num=1<<30;
	      if (!f[j]) num=p[j],now=j;
	      if (!f[j+1]) {
	      	if (p[j+1]<num) num=p[j+1];
	      	now=j+1;
	      }
	      vis[now]=true;
	      ans+=num;
	    }
	  	  }
	  	}
	  	printf("%d\n",ans);
	  }
	  else {
	    sort(p+1,p+n+1);
	    for (int i=1;i<=n/2;i++)
	      ans+=p[i];
	    printf("%d\n",ans);
	  }
	}
	fclose(stdin); fclose(stdout);
	return 0;
}

