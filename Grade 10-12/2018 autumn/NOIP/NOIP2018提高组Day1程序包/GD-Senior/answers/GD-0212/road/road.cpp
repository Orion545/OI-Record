#include<iostream>
#include<cstdlib>
#include<utility>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxN=100100;
int n,d[maxN];
int rmq[maxN][30];

void prepare()
{
	for(int i=1;i<=20;++i){
		for(int j=1;j<=n;++j){
			if((j+(1<<i)-1)<=n)
			if(d[rmq[j][i-1]]<d[rmq[j+(1<<(i-1))][i-1]])
				rmq[j][i]=rmq[j][i-1];
			else
				rmq[j][i]=rmq[j+(1<<(i-1))][i-1];
		}
	}
}

inline long long dg(int l,int r,int h)
{
	if(l==r)
		return d[l]-h;
	if(l>r)
		return 0;
	int len=r-l+1;
	int k=log(len)/log(2);
	int p1=rmq[l][k];
	int p2=rmq[r-(1<<k)+1][k];
	if(d[p1]>d[p2])
		return dg(l,p2-1,d[p2])+dg(p2+1,r,d[p2])+d[p2]-h;
	else
		return dg(l,p1-1,d[p1])+dg(p1+1,r,d[p1])+d[p1]-h;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>d[i];
		rmq[i][0]=i;
	}
	prepare();
	long long ans=dg(1,n,0);
	cout<<ans<<endl;
	return 0;
}
