#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct pt{int d,i;}g[800010],no;
int n,m,k,l;
void at(int i,int lei,int ruo)
{
	if(lei==ruo)
	{
		g[i]=no;
		return;
	}
	int mid=(lei+ruo)/2;
	if(mid<no.i) at(i*2+2,mid+1,ruo);
	else at(i*2+1,lei,mid);
	if(g[i].d<g[i*2+1].d)g[i]=g[i*2+1];
	if(g[i].d<g[i*2+2].d)g[i]=g[i*2+2];
	return;
}
pt mx(int id,int lei,int ruo)
{
	if(lei>=k && ruo<=l) return g[id];
	int mid=(lei+ruo)/2;
	if(mid>=l) return mx(id*2+1,lei,mid);
	if(k>mid) return mx(id*2+2,mid+1,ruo);
	pt nodd=mx(id*2+1,lei,mid),wmdd=mx(id*2+2,mid+1,ruo);
	if(nodd.d<wmdd.d) return wmdd;
	return nodd;
}
void df(int x,int lei,int ruo)
{
	k=lei;
	l=ruo;
	pt nod=mx(0,0,n-1);
	m=m+10000-nod.d-x;
	if(lei<nod.i) df(10000-nod.d,lei,nod.i-1);
	if(nod.i<ruo) df(10000-nod.d,nod.i+1,ruo);
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&no.d);
		no.d=10000-no.d;
		no.i=i;
		at(0,0,n-1);
	}
	m=0;
	df(0,0,n-1);
	printf("%d\n",m);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
