#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;

int a[100010],n;
bool tf[100010];
vector<int> f[10010];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	int mmax=0;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),f[a[i]].push_back(i),mmax=max(mmax,a[i]);
	tf[0]=tf[n+1]=true;
	long long ans=0;
	int tot=1;
	for(int i=0;i<(int)f[0].size();i++){
		if(tf[f[0][i]-1] && tf[f[0][i]+1]) tot--;
		else if(!tf[f[0][i]-1] && !tf[f[0][i]+1]) tot++;
		tf[f[0][i]]=true;
	}
	for(int i=1;i<=mmax;i++){
		ans+=tot;
		for(int j=0;j<(int)f[i].size();j++){
			if(tf[f[i][j]-1] && tf[f[i][j]+1]) tot--;
			else if(!tf[f[i][j]-1] && !tf[f[i][j]+1]) tot++;
			tf[f[i][j]]=true;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
