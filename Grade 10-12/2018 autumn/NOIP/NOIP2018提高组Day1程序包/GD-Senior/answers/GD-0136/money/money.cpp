#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 50005
using namespace std;

int n,T,i,j,k,flag,md,l;
int a[MAXN],s[MAXN],sj[MAXN];

int dfs(int md,int gs,int num) {
	int i,j;
	if (gs>k) {
		//判断所选的数能否凑和 
		int t[50005];
		memset(t,0,sizeof(t));
		t[0]=1;
		for (i=0; i<=md; i++) 
			if (t[i]) 
				for (j=1; j<=gs; j++)
					if (i+a[j]==md) return 1; else t[i+a[j]]=1;
		return 0;
	}
	for (i=num; i<=l; i++) {
		//选数 
		a[gs]=s[i];
		if (dfs(md,gs+1,i+1)) return 1;
		a[gs]=0;
	}
	return 0;
}

int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	 
	scanf("%d",&T);
	for (i=1; i<=T; i++) {
		
		memset(sj,0,sizeof(sj));		
		memset(s,0,sizeof(s));
		l=0;
		scanf("%d",&n);
		for (j=1; j<=n; j++)
			scanf("%d",&sj[j]);
		sort(sj+1,sj+1+n);

		for (j=1; j<=n; j++) {
			md=sj[j];
			for (flag=1,k=1; k<=l; k++) 
				if (md%s[k]==0) { flag=0; break; }
			if (flag) 
				for (k=2; k<=l; k++) {
					memset(a,0,sizeof(a));
					if (dfs(md,1,1)) flag=0;
				}
			if (flag) s[++l]=md; 
		}
		printf("%d\n",l);
	}
	return 0;
}
	

