#include<bits/stdc++.h>
using namespace std;
int p[5001][5001],n,m,i,ans[5001],a,b,cnt,d[5001],o;
int j,bb[5001],biana[5001],bianb[5001],incir[5001],cnt1,cnt2;
queue<int> q;
void dfs(int o,int fa){
	for(int i=1;i<=n;i++)
	  if(p[o][i]==1&&i!=o&&i!=fa){
	  	ans[++cnt]=i;
	  	dfs(i,o);
	  }
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		p[a][b]=1;p[b][a]=1;
		d[a]++;d[b]++;
	}
	if(m==n-1){
		ans[++cnt]=1;
		dfs(1,0);
		for(i=1;i<=n;i++)
		  printf("%d ",ans[i]);
	}else
	if(m==n){
		ans[++cnt]=1;
		for(i=1;i<=n;i++)
		  if(d[i]==1) q.push(i);
		while(!q.empty()){
			o=q.front();q.pop();
			d[o]=0;
			for(i=1;i<=n;i++)
			  if(p[o][i]==1&&d[i]>0){
				d[i]--;
				if(d[i]==1) q.push(i);
			}
		}
		for(i=1;i<=n;i++)
		  if(d[i]>0) incir[++cnt1]=i;
		for(i=1;i<=cnt1;i++)
		  for(j=1;j<=cnt1;j++)
		    if(i!=j&&p[incir[i]][incir[j]]>0){
		    	biana[++cnt2]=incir[i];
		    	bianb[cnt2]=incir[j];
		    }
		for(i=1;i<=n;i++)
		  bb[i]=n+1;
		for(i=1;i<=cnt2;i++){
			p[biana[i]][bianb[i]]=0;
			p[bianb[i]][biana[i]]=0;
			cnt=0;
			ans[++cnt]=1;
			dfs(1,0);
			for(j=1;j<=n;j++)
			  if(bb[j]>ans[j]) j=n+3;
			  else if(bb[j]<ans[j]) j=n+15;
			if(j==n+4)
			  for(int u=1;u<=n;u++)
			    bb[u]=ans[u];
			p[biana[i]][bianb[i]]=1;
			p[bianb[i]][biana[i]]=1;
		}
		for(i=1;i<=n;i++)
		  printf("%d ",bb[i]);
	}
	return 0;
}
