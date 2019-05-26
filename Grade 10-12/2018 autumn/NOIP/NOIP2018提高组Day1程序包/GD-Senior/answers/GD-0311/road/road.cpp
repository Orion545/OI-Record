#include <cstdio>
int road[100001],count=0;
bool c(int l,int r)
{
	for(int i=l; i<=r; i++)
		if(road[i]!=0) return false;
	return true;
}
bool s(int l,int r)
{
	for(int i=l; i<=r; i++)
		if(road[i]==0) return false;
	return true;
}
void A(int l,int r)
{
	int minn=2e9;
	if(c(l,r)) return;
	if(l==r) { count+=road[l]; road[l]=0; }
	else if(!s(l,r))
	{
		for(int i=l; i<=r; i++)
			if(road[i]==0) { A(l,i-1); A(i+1,r); }
	}
	else 
	{
		for(int i=l; i<=r; i++)
		if(road[i]<minn) minn=road[i];
		for(int i=l; i<=r; i++)
		road[i]-=minn;
		count+=minn; A(l,r);
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&road[i]);
	A(1,n);
	printf("%d",count);
	fclose(stdin);fclose(stdout);
	return 0;
}
