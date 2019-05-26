#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct II
{
	int a,s;
}q[5005*2],qq[5005*2];
struct I
{
	int t,n;
}edge[5005*2];
int n,m,h[5005],w[5005],e[5005],v[5005],v2[5005],cur=-1,ww[5005],p,pp,s,a;
bool cmp(II a,II s)
{
	if (a.a==s.a) return a.s>s.s;
	return a.a<s.a;
}
void add(int f,int t)
{
	cur++;
	edge[cur].t=t;
	edge[cur].n=h[f];
	h[f]=cur;
}
void dfs2(int now)
{
	w[s]=now;
	s++;
	for (int i=h[now];i!=-1;i=edge[i].n)
	{
		if (!v[edge[i].t])
    	{
		   v[edge[i].t]=1;
		   dfs2(edge[i].t);
    	}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) 
	{
		scanf("%d%d",&q[i].a,&q[i].s);
		q[i+m].a=q[i].s;
		q[i+m].s=q[i].a;
		e[q[i].a]++;
		e[q[i].s]++;
	}
	if (n!=m)
	{
		sort(q+1,q+1+2*m,cmp);
	for (int i=1;i<=n;i++) h[i]=-1; 
	for (int i=1;i<=2*m;i++)
	 add(q[i].a,q[i].s);
		s=1;
		v[s]=1;
		dfs2(1);
	} else
	{
		for (int i=1;i<=n;i++) ww[i]=5005;
		for (int i=1;i<=m;i++)
		 if (e[q[i].a]>1&&e[q[i].s]>1)
		 {
		 	a=0;
		 	for (int j=1;j<=2*m;j++)
		 	if (i!=j&&i+m!=j)
		  {
		  	a++;
		  	qq[a].a=q[j].a;
		  	qq[a].s=q[j].s;
		  }
		  sort(qq+1,qq+1+2*m-2,cmp);
		  cur=-1;
        	for (int j=1;j<=n;j++) h[j]=-1; 
        	for (int j=1;j<=2*m-2;j++)
        	 add(qq[j].a,qq[j].s);
	    	s=1;
	    	memset(v,0,sizeof(v));
	    	v[s]=1;
	    	dfs2(1);
		    p=0;
		    for (int j=1;j<=n;j++)
		    {
		    	if (w[j]>ww[j])
		    	{
		    		break;
		    	} 
		    	if (w[j]<ww[j])
		    	{
		    		p=1;
		    		break;
		    	}
		    }
		    if (p) for (int j=1;j<=n;j++) ww[j]=w[j];
		 }  
		  for (int i=1;i<=n;i++) w[i]=ww[i];
	}
	for (int i=1;i<=n;i++) printf("%d ",w[i]);
	return 0;
}
