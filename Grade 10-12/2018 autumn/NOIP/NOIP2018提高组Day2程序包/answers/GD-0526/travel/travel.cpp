#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n,m,cnt,p;
int c[5004],lc,l;
int ls[5004],ne[10005],y[10005],bz[5004],ch[5004];
bool b[5004];
int cch[5004];

void dfs(int i){
	b[i]=1;
	c[++lc]=i;
	if (lc==n) return;
	int u=ch[i];
	while (u){
		int t=ls[i],d=n;
		while (t){
			if (y[t]<d&&!b[y[t]]) d=y[t];
			t=ne[t];
		}
		ch[d]--;
		dfs(d);
		if (lc==n) return;
		u--;
	}
}

void search(int i){
	b[i]=1;
	c[++lc]=i;
	if (lc==n) return;
	int u=ch[i];
	while (u){
		int t=ls[i],d=n;
		while (t){
			if (y[t]<d&&!b[y[t]]) d=y[t];
			t=ne[t];
		}
		ch[d]--;
		dfs(d);
		if (lc==n) return;
		u--;
	}
}

void try1(int i){
	b[i]=1;
	c[++lc]=i;
	if (lc==n) return;
	int d=ls[i];
	if (!b[y[d]]&&!b[y[ne[d]]]) d=y[d]<y[ne[d]]?d:ne[d]; else
	if (b[y[d]]) d=ne[d];
	dfs(y[d]);
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int x,a;
		scanf("%d%d",&x,&a);
		ne[++cnt]=ls[x];ls[x]=cnt;y[cnt]=a;bz[a]++;ch[x]++;
		ne[++cnt]=ls[a];ls[a]=cnt;y[cnt]=x;bz[x]++;ch[a]++;
		if (bz[x]>2||bz[a]>2) p=1;
	}
	if (m==n-1){
		dfs(1);
	} else
	{
		if (!p) try1(1); else{
			search(1);
		}
	}
	for (int i=1;i<=n;i++)
		printf("%d ",c[i]);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
