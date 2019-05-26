#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define INF 2147483647
using namespace std;
long long ans;
int n,a[100010],cnt,st[200010][20],b[20],num,pos[200010][20],tmp;
void dfs(int l,int r,int pre){
	if(r<l)return;
//	int mn=INF,w=0;
//	for(int i=l;i<=r;i++){
////		cnt++;
//		if(a[i]<mn){
//			mn=a[i];
//			w=i;
//		}
//	}
	tmp=log2(r-l+1);
	int mn,w;
	if(st[l][tmp]<=st[r-b[tmp]+1][tmp]){
		mn=st[l][tmp];
		w=pos[l][tmp];
	}
	else {
		mn=st[r-b[tmp]+1][tmp];
		w=pos[r-b[tmp]+1][tmp];
	}
	ans+=mn-pre;
//	printf("%d %d %d\n",l,r,w);
	dfs(l,w-1,mn);
	dfs(w+1,r,mn);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	num=log2(n);
	b[0]=1;
	for(int i=1;i<=num;i++)b[i]=b[i-1]*2;
//	printf("%d\n",num);
	memset(st,0x7f7f7f7f,sizeof(st));
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		st[i][0]=a[i];
		pos[i][0]=i;
	}
	for(int i=1;i<=num;i++){
		for(int j=1;j<=n;j++){
			if(st[j][i-1]<=st[j+b[i-1]][i-1]){
				st[j][i]=st[j][i-1];
				pos[j][i]=pos[j][i-1];
			}
			else{
				st[j][i]=st[j+b[i-1]][i-1];
				pos[j][i]=pos[j+b[i-1]][i-1];
			}
		}
	}
//	for(int i=1;i<=num;i++){
//		for(int j=1;j<=n;j++)printf("%d ",pos[j][i]);
//		printf("\n");
//	}
	dfs(1,n,0);
//	printf("%d\n",cnt);
	printf("%lld\n",ans);
}
