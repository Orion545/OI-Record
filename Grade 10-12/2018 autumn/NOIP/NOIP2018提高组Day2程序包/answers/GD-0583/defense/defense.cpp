#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;
int n,m,ans;
bool map[10001][10001],a[100001];
bool v[10001];
void xz(int to){
		for(int i=1;i<=n;i++){
				if(map[to][i]==true){
					ans+=v[i];
					v[i]=true;
				}
			}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n-1;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		map[x][y]=true;
		map[y][x]=true;
	}
	for(int i=1;i<=m;i++){
		memset(v,0,sizeof(v));
		int a1,x,y,b1;
		scanf("%d%d%d%d",&a1,&x,&b1,&y);
		if(x==0&&y==0&&map[x][y]==true){
			puts("-1");
			continue;
			
		}
		int maxn=0;
		ans=0;
		int to;
		v[a1]=true;
		v[b1]=true;
		if(x==0){
			for(int i=1;i<=n;i++){
				if(map[a1][i]&&a[i]>=maxn&&!v[i]){
					maxn=a[i];
					to=i;
				}
			}
			ans+=maxn;
			xz(to);
		}
		maxn=0;
		if(y==0){
			for(int i=1;i<=n;i++){
				if(map[b1][i]&&a[i]>=maxn&!v[i]){
					maxn=a[i];
					to=i;
				}
			}
			ans+=maxn;
			xz(to);
		}
		if(x==1){
			ans+=a[a1];
		xz(a1);
		}
		if(y==1){
			ans+=a[b1];
			xz(b1);
		}
		for(int i=1;i<=n;i++){
			if(!v[i]){
				v[i]=true;
				xz(v[i]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
