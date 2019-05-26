/*
ID: marcoli2
PROG: milk2
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct seg{
	int l,r;
}a[5010];
int n,ans1=0,ans2=0;
bool cmp(seg l,seg r){
	return l.l<r.l;
}
int main(){
	freopen("milk2.in","r",stdin);
	freopen("milk2.out","w",stdout);
	int i,op=0,ed=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&a[i].l,&a[i].r);
	sort(a+1,a+n+1,cmp);
	op=a[1].l;ed=a[1].r;
	ans1=max(ans1,ed-op);
	for(i=2;i<=n;i++){
//		cout<<i<<ends<<ans1<<ends<<ans2<<ends<<op<<ends<<ed<<endl;
		if(ed>=a[i].l){
			ed=max(ed,a[i].r);
		}
		else{
			ans1=max(ans1,ed-op);ans2=max(ans2,a[i].l-ed);
			op=a[i].l;ed=a[i].r;
		}
	}
	ans1=max(ans1,ed-op);
	printf("%d %d\n",ans1,ans2);
} 
/*
10
2 3
4 5
6 7
8 9
10 11
12 13
14 15
16 17
18 19
1 20

4
100 200
201 301
302 402
403 503

*/
