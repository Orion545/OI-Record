#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define inf 0x7fffffff
using namespace std;
long long n,nn,k1,k2,k3,ans=inf;
struct node{
	long long x,y,num;
}a[50005],aa[50005];
bool vis[50005];
void dfs(int k,int t1,int t2,int t3){
	if(k==3){
		long long maxx,maxy,minx,miny;
		minx=miny=inf;maxx=maxy=-1;
		for(int i=1;i<=nn;i++){
			if(i!=a[t1].num&&i!=a[t2].num&&i!=a[t3].num){
				minx=min(minx,aa[i].x);
				maxx=max(maxx,aa[i].x);
				miny=min(miny,aa[i].y);
				maxy=max(maxy,aa[i].y);
			}
		}
		long long tmp=(maxx-minx)*(maxy-miny);
		if(tmp<ans){
			ans=tmp;
			k1=a[t1].num;k2=a[t2].num;k3=a[t3].num;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(k==0) dfs(1,i,0,0);
		if(k==1&&i!=t1) dfs(2,t1,i,0);
		if(k==2&&i!=t1&&i!=t2) dfs(3,t1,t2,i);
	}
}
bool cmp1(node l,node r){
	return l.x<r.x;
}
bool cmp2(node l,node r){
	return l.y<r.y;
}
bool cmp3(node l,node r){
	return l.num<r.num;
}
int main(){
	freopen("reduce.in","r",stdin);
	freopen("reduce.out","w",stdout);
	int i;
	scanf("%lld",&nn);
	for(i=1;i<=nn;i++){
		scanf("%lld%lld",&aa[i].x,&aa[i].y);
		aa[i].num=i;
	}
	
	sort(aa+1,aa+nn+1,cmp1);n=0;
	
//	for(i=1;i<=nn;i++) cout<<aa[i].x<<ends<<aa[i].y<<ends<<aa[i].num<<endl;
	
//	for(i=1;i<=3;i++) a[++n].x=aa[i].x,a[n].y=aa[i].y,a[n].num=aa[i].num,vis[aa[i].num]=1;
//	for(i=nn-2;i<=nn;i++) a[++n].x=aa[i].x,a[n].y=aa[i].y,a[n].num=aa[i].num,vis[aa[i].num]=1;
	
	if(!vis[aa[1].num]) a[++n].x=aa[1].x,a[n].y=aa[1].y,a[n].num=aa[1].num,vis[aa[1].num]=1;
	if(!vis[aa[2].num]) a[++n].x=aa[2].x,a[n].y=aa[2].y,a[n].num=aa[2].num,vis[aa[2].num]=1;
	if(!vis[aa[3].num]) a[++n].x=aa[3].x,a[n].y=aa[3].y,a[n].num=aa[3].num,vis[aa[3].num]=1;
	if(!vis[aa[nn-2].num]) a[++n].x=aa[nn-2].x,a[n].y=aa[nn-2].y,a[n].num=aa[nn-2].num,vis[aa[nn-2].num]=1;
	if(!vis[aa[nn-1].num]) a[++n].x=aa[nn-1].x,a[n].y=aa[nn-1].y,a[n].num=aa[nn-1].num,vis[aa[nn-1].num]=1;
	if(!vis[aa[nn  ].num]) a[++n].x=aa[nn  ].x,a[n].y=aa[nn  ].y,a[n].num=aa[nn  ].num,vis[aa[nn  ].num]=1;
	
	sort(aa+1,aa+nn+1,cmp2);
	
//	cout<<endl<<endl<<n<<ends<<nn<<endl<<endl;
	
	if(!vis[aa[1].num]) a[++n].x=aa[1].x,a[n].y=aa[1].y,a[n].num=aa[1].num,vis[aa[1].num]=1;
	if(!vis[aa[2].num]) a[++n].x=aa[2].x,a[n].y=aa[2].y,a[n].num=aa[2].num,vis[aa[2].num]=1;
	if(!vis[aa[3].num]) a[++n].x=aa[3].x,a[n].y=aa[3].y,a[n].num=aa[3].num,vis[aa[3].num]=1;
	if(!vis[aa[nn-2].num]) a[++n].x=aa[nn-2].x,a[n].y=aa[nn-2].y,a[n].num=aa[nn-2].num,vis[aa[nn-2].num]=1;
	if(!vis[aa[nn-1].num]) a[++n].x=aa[nn-1].x,a[n].y=aa[nn-1].y,a[n].num=aa[nn-1].num,vis[aa[nn-1].num]=1;
	if(!vis[aa[nn  ].num]) a[++n].x=aa[nn  ].x,a[n].y=aa[nn  ].y,a[n].num=aa[nn  ].num,vis[aa[nn  ].num]=1;
	
	sort(aa+1,aa+nn+1,cmp3);
	
//	for(i=1;i<=n;i++) cout<<a[i].x<<ends<<a[i].y<<ends<<a[i].num<<endl;
	
	dfs(0,0,0,0);
	
	printf("%lld",ans);
}
