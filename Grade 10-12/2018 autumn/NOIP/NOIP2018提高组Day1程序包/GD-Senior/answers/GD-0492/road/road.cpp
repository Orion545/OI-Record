#include<cstdio>
#include<algorithm>
using namespace std;

int line[1000002];
int pline[1000002];
int ans,iA;
bool cmp(const int a,const int b)
{
	return line[a]<line[b];
}
void del(int first,int last,int p)
{
	if(first>=last && line[first]==0) return;
	while(pline[p]<first || pline[p]>last) p++;
	while(line[pline[p]]>0)
	{
		for(iA=first;iA<=last;iA++)
			line[iA]--;
		ans++;
	}
	del(first,pline[p]-1,p+1);
	del(pline[p]+1,last,p+1);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,point=1;
	scanf("%d",&n);
	for(iA=1;iA<=n;iA++)
	{
		scanf("%d",&line[iA]);
		pline[iA]=iA;
	}
	sort(pline+1,pline+n+1,cmp);
	del(1,n,1);
	printf("%d",ans);
	return 0;
}
