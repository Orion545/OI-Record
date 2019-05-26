#include<iostream>
#include<cstring>
#include<algorithm>
#define next nextt
#define N 5001
#define M 30000
using namespace std;
int n,m;
int to[M],next[M],dfn[N],ce[N],low[N],cnt=0;
int sta[N],ans[N],acnt=0,scnt=0;
int cir[N],rcnt=0,dfnt=0;
int del1,del2;
void link(int u,int v){
	to[++cnt]=v;
	next[cnt]=ce[u];
	ce[u]=cnt;
	to[++cnt]=u;
	next[cnt]=ce[v];
	ce[v]=cnt;
}
int incir=0;
void dfsc(int v,int last){
	if(dfn[v]) return;
	dfn[v]=low[v]=++dfnt;
	sta[++scnt]=v;
	int p,l=dfnt;
	for(p=ce[v];p;p=next[p]){
		if(to[p]==last)continue;
		dfsc(to[p],v);
		l=min(l,low[to[p]]);
	}
	low[v]=l;
	if(dfn[v]==low[v]){
		if(incir){
			while(sta[scnt]!=v){
				cir[++rcnt]=sta[scnt];
				scnt--;
			}
			cir[++rcnt]=v;
			scnt--;
			incir=0;
		}else scnt--;
	}else{
		incir=1;
	}
}
int heap[N],cq=0;
void dfs(int v,int last,int *res,int &rec){
	int p,qs=cq,i;
	res[++rec]=v;
	for(p=ce[v];p;p=next[p]){
		if(to[p]==last) continue;
		if((v==del1&&to[p]==del2)||(v==del2&&to[p]==del1)) continue;
		heap[++cq]=to[p];
	}
	if(cq>qs){
		sort(heap+qs+1,heap+cq+1);
		for(i=qs+1;i<=cq;i++) dfs(heap[i],v,res,rec);
	}
	cq=qs;
}
int cmp(int *a,int *b){//a<b·µ»Ø1 
	int i=1;
	while(a[i]==b[i])i++;
	if(i<=n) return a[i]<b[i];
	return 0;
}
void set(int *a,int *b){
	int i;
	for(i=1;i<=n;i++) a[i]==b[i];
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(ce,0,sizeof(ce));
	cin>>n>>m;
	int i,x,y;
	for(i=1;i<=m;i++){
		cin>>x>>y;
		link(x,y);
	}
	del1=del2=0;
	if(m==n-1) dfs(1,1,ans,acnt);
	else{
		int res[N],rcp;
		dfsc(1,1);
		for(i=1;i<=rcnt;i++){
			if(i==rcnt){
				del1=cir[i];
				del2=cir[1];
			}else{
				del1=cir[i];
				del2=cir[i+1];
			}
			rcp=0;
			if(i==1) dfs(1,1,ans,acnt);
			else{
				dfs(1,1,res,rcp);
				if(cmp(res,ans)){
					set(ans,res);
				}
			} 
		}
	}
	for(i=1;i<=n;i++) cout<<ans[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
