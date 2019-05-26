#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
struct vec
{
	int next,to;
}v[1000005];
struct data
{
	int sum,num[5005];
}son[5005];
int n,nn,m,s,c,p,father[5005],b[5005],z[5005],a[5005],u[5005],vv[5005],mi[5005],ans[5005];
void first_clean()
{
	s=0;
	for(int i=1;i<=n;i++)
	{
		son[i].sum=0;
		father[i]=0;
		b[i]=0;
	}
}
void in_vector(int x,int y)
{
	nn++;v[nn].next=z[x];v[nn].to=y;z[x]=nn;
}
void ans_tree(int k)
{
	c++;ans[c]=k;
	for(int i=1;i<=son[k].sum;i++) ans_tree(son[k].num[i]);
}
void in_tree(int k,int x,int y)
{
	if(b[k]==1) return;
	if(b[k]==0)
	{
		b[k]=1;
		s++;
	}
	for(int i=z[k];i>0;i=v[i].next)
	{
		if(v[i].to!=father[k]&&(x!=k||y!=v[i].to)&&(x!=v[i].to||y!=k))
		{
			son[k].sum++;son[k].num[son[k].sum]=v[i].to;
			father[v[i].to]=k;
			in_tree(v[i].to,x,y);
		}
	}
	sort(son[k].num+1,son[k].num+1+son[k].sum);
}
void find_ans1()
{
	in_tree(1,0,0);
	ans_tree(1);
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
}
void find_ans2()
{
	for(int i=1;i<=m;i++)
	{
		first_clean();
		in_tree(1,u[i],vv[i]);
		if(s!=n) continue;
		c=0;p=0;
		ans_tree(1);
		for(int i=1;i<=n;i++)
		{
			if(mi[i]<ans[i]) break;
			if(mi[i]>ans[i]) {p=1; break;}
		}
		if(p==1||mi[1]==0) for(int i=1;i<=n;i++) mi[i]=ans[i];
	}
	for(int i=1;i<=n;i++) printf("%d ",mi[i]);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u[i],&vv[i]);
		in_vector(u[i],vv[i]);
		in_vector(vv[i],u[i]);
	}
	if(m==n-1) find_ans1();
	else find_ans2();
	return 0;
}
