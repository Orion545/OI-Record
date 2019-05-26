#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
struct road{
	int In;
	int Out;
	int Jia;
}a[50010];
int Max=0,Min=0x7fffffff,n,p[50010],m;
int search(int x,int y)
{
	Max=max(Max,y);
	for (int i=1;i<=n-1;++i) {
		if (a[i].In==x&&p[i]==0) {
			p[i]=1;
			search(a[i].Out,y+a[i].Jia);
			p[i]=0;
		}else{
			if (a[i].Out==x&&p[i]==0)  {
				p[i]=1;
				search(a[i].In,y+a[i].Jia);
				p[i]=0;
			}
		}
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n-1;++i){
		scanf("%d%d%d",&a[i].In,&a[i].Out,&a[i].Jia);
		Min=min(a[i].Jia,Min);
	}
		if (m==1) {
			for (int i=1;i<=n-1;++i) search(i,0);
			cout<<Max;
			return 0;
		}
	cout<<Min;
	return 0;
}
