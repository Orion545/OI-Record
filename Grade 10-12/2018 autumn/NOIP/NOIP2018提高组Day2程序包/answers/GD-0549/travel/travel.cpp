#include<cstdio>
int n,m;
int redd(){
	char c=getchar();int re=0;
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9') re=re*10+c-'0',c=getchar();
	return re;
}
bool tu[5005][5005];
void t(int a,int b){
	tu[a][b]=true;tu[b][a]=true;
}
void dfs1(int a,int fa){
	printf("%d ",a);
	for(int i=1;i<=n;i++)
		if(tu[a][i]&&i!=fa) dfs1(i,a);
}
int dfs[5001],top=0,tjm[5001];
bool flag;
void fcnt(int a){
	int mc=dfs[top-1],lao=dfs[a]+1;
	for(;lao<top;lao++){
//		printf("%d ",dfs[lao]);
		if(dfs[lao]>mc){/*printf("%d %d",dfs[lao],dfs[lao-1])*/
			int x=dfs[lao],y=dfs[lao-1];
			tu[x][y]=false;tu[y][x]=false;
			flag=true;break;
		}
	}
}
void dfs2(int a,int fa){
	if(flag) return;
	if(tjm[a]>0) fcnt(a); 
	tjm[a]=top;dfs[top]=a;top++;
	for(int i=1;i<=m;i++)
		if(tu[a][i]&&i!=fa) dfs2(i,a);
	tjm[a]=0;top--;	
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=redd();m=redd();
	for(int m1=0;m1<m;m1++) t(redd(),redd());
	if(m==n) dfs2(1,0);	
	dfs1(1,0);printf("\n");
	return 0;
}
