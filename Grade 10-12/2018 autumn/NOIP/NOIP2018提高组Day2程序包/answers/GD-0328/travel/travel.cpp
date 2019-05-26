#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int c2[20005],v3[20005],w,que[20005],y3,o2,i,deep[2000005],v[20005],v2[20005],cur,he,t,h[20005],u,ans[20005],r[20005],n,m;
struct tt
{
	int to,next;
} e[20005];
struct ttt
{
	int a,b;
} c[20005];
bool cmp(ttt x,ttt y)
{
	return x.b>y.b;
}
void add(int x,int y)
{
	cur++;
	e[cur].to=y;
	e[cur].next=h[x];
	h[x]=cur;
}
void dfs(int s)
{
        v3[s]=1;
	    u++;
	    ans[u]=s; 
		int p=100000000;
		for(i=1;i<=n;++i) if (v[i]==1) p=min(p,i);
	 	y3=h[s];
	 	while(y3!=-1) 
		 {
	 	    o2=e[y3].to;c2[o2]++;
			if (v[o2]) 	 	 	 
			 {
	 	 	 	y3=e[y3].next;
	 	 	 	continue;
	 	 	 }
            v[o2]=1; 
            y3=e[y3].next;
	 	 }
	 	v[s]=2; 
	 	int z=0;
	 	int y2=h[s];
	 	while(y2!=-1) 
	 	 {
	 	    int o=e[y2].to;
			if (v3[o]) 	 	 	 
			{
	 	 	 	y2=e[y2].next;
	 	 	 	continue;
	 	 	 }
	 	 	if (r[o]==1||o==p) 
			 {
			  z=1;
			  dfs(o); 
		     }
		    y2=e[y2].next;
	 	 }
		v3[s]=2;
		y3=h[s];
	 	while(y3!=-1) 
		 {
	 	    o2=e[y3].to;			
			c2[o2]--;
            if (c2[o2]==0&&v[o2]!=2) v[o2]=0;
			if (v3[o2]) 	 	 	 
			 {
	 	 	 	y3=e[y3].next;
	 	 	 	continue;
	 	 	 }
            r[o2]--; 
            y3=e[y3].next;
	 	 }
}
void bfs()
{
	he=1; t=1; v2[1]=1;
	que[1]=1; deep[1]=1;
	while(he<=t)
	 {
	 	w=que[he];
	 	y3=h[w];
	 	while(y3!=-1)
	 	 {
	 	 	o2=e[y3].to;
			if (deep[o2]==0||deep[o2]>deep[w])r[o2]++;
	 	 	if (v2[o2]) 
	 	 	 {
	 	 	 	y3=e[y3].next;
	 	 	 	continue;
	 	 	 }
	 	 	deep[o2]=deep[w]+1;
		 	
	 	 	t++;
	 	 	que[t]=o2;
	 	 	v2[o2]=1;
	 	 	y3=e[y3].next;
	 	 }
	 	he++;
	 }
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	cur=-1; memset(h,-1,sizeof(h));
	for(i=1;i<=m;++i) 
	 {
	 	scanf("%d%d",&c[i*2-1].a,&c[i*2-1].b);
	 	c[i*2].a=c[i*2-1].b;
	 	c[i*2].b=c[i*2-1].a;
	 }
	sort(c+1,c+m*2+1,cmp);
	for(i=1;i<=m*2;++i) 
	 {
	 	add(c[i].a,c[i].b);
	 }
	bfs();
	ans[1]=1; 
//	for(i=1;i<=n;++i) v[i]=1000000;
	dfs(1);
	for(i=1;i<=n;++i) printf("%d ",ans[i]);
	return 0;
}
