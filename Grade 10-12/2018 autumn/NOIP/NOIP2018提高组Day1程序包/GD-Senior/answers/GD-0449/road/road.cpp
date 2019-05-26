# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# include <cmath>
# include <vector>
# include <map>
# include <set>
# include <queue>
# define Fo(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int maxn = 1e5+10;
const int maxk = 20;
int n;
int d[maxn];
namespace Subtask1{
	//BruteForce 70%
	int solve(int l,int r){
		if(l>r)return 0;
		int mini = l;
		Fo(i,l,r) if(d[mini]>d[i])mini=i;
		int x=d[mini];
		Fo(i,l,r)d[i]-=x;
		return solve(l,mini-1)+solve(mini+1,r)+x;
	}
}
namespace Subtask2{
	int minv[maxn][maxk];
	void init(){
		for(int i=1;i<=n;++i)minv[i][0]=i;
		for(int k=1;(1<<k)<=n;++k)
			for(int i=1;i+(1<<k)<=n+1;++i){
				if(d[minv[i][k-1]]<d[minv[i+(1<<(k-1))][k-1]])minv[i][k]=minv[i][k-1];
				else minv[i][k]=minv[i+(1<<(k-1))][k-1];
			}
	}
	int solve(int l,int r,int v){
		if(l>r)return 0;
		int x=0; for(;!(l+(1<<x) >= r+1-(1<<x));++x);
		int mini = minv[l][x];
		if(d[minv[r+1-(1<<x)][x]]<d[mini])mini=minv[r+1-(1<<x)][x];
		return solve(l,mini-1,d[mini])+solve(mini+1,r,d[mini])+(d[mini]-v);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	Fo(i,1,n)scanf("%d",d+i);
	if(n<=1000)printf("%d\n",Subtask1::solve(1,n));
	else{ Subtask2::init();printf("%d\n",Subtask2::solve(1,n,0)); }
	return 0;
}
