#include <stdio.h>
int n,m,i,j,k,xiao,ans1,ans2,ans3,ans,a,b,x,y;
int p[100005];
char c[10];
/*void charu(int a,int b){
	d[++j].a=a,d[j].b=b;
	d[j].n=h[a],h[a]=j;
}*/
void dfs1(int a,int q,int s){
	if(s>xiao)return;
	if(a<=1){
		if(s<xiao)xiao=s;
		return;
	}
	if(!q)dfs1(a-1,1,s+p[a-1]);
	if(q){
		dfs1(a-1,1,s+p[a-1]);
		dfs1(a-1,0,s);
	}
}
void dfs2(int a,int q,int s){
	if(s>xiao)return;
	if(a>=n){
		if(s<xiao)xiao=s;
		return;
	}
	if(!q)dfs2(a+1,1,s+p[a+1]);
	if(q){
		dfs2(a+1,1,s+p[a+1]);
		dfs2(a+1,0,s);
	}
}
void dfs3(int a,int b,int o,int q,int s){
	if(s>xiao)return;
	if(a>=b){
		if(s<xiao)xiao=s;
		return;
	}
	dfs3(a+1,b-1,1,1,s+p[a+1]+p[b-1]);
	if(o)dfs3(a+1,b-1,0,1,s+p[b-1]);
	if(q)dfs3(a+1,b-1,1,0,s+p[a+1]);
	if(o&&q)dfs3(a+1,b-1,0,0,s);
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", c+1);
	for(i=1;i<=n;i++)scanf("%d", &p[i]);
	for(i=1;i<n;i++){
		scanf("%d%d", &a, &b);
		//charu(a,b);charu(b,a);
	}
	if(c[1]=='A'){
		for(i=1;i<=m;i++){
			scanf("%d%d%d%d", &a, &x, &b, &y);
			if(a>b)k=a,a=b,b=k;
			if(b==a+1&&!x&&!y)printf("-1\n");
			else{
				xiao=1e9;
				dfs1(a-1,1,p[a-1]);	
				if(x)dfs1(a-1,0,0);
				ans1=xiao;
				xiao=1e9;
				dfs2(b+1,1,p[b+1]);
				if(y)dfs2(b+1,0,0);
				ans2=xiao;
				xiao=1e9;
				dfs3(a+1,b-1,1,1,p[a+1]+p[b-1]);
				if(x)dfs3(a+1,b-1,0,1,p[b-1]);
				if(y)dfs3(a+1,b-1,1,0,p[a+1]);
				if(x&&y)dfs3(a+1,b-1,0,0,0);
				ans3=xiao;
				ans=ans1+ans2+ans3;
				if(x)ans+=p[a];
				if(y)ans+=p[b];
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
