#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,f[100100],first[101000],c[101000];
struct edge{
	int to,next;
}a[201000];
bool ans[101000];
int find(int x){
	return (f[x]<=0?x:f[x]=find(f[x]));
}
void join(int x,int y){
	if(f[x]<f[y]) f[x]+=(f[y]?f[y]:-1),f[y]=x;
	else f[y]+=(f[x]?f[x]:-1),f[x]=y;
}
int main(){
	int i,j,t1,t2,u,v,flag,fx,fy;
	memset(first,-1,sizeof(first));
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&t1,&t2);
		a[i*2-1].to=t2;a[i*2-1].next=first[t1];first[t1]=i*2-1;
		a[i*2].to=t1;a[i*2].next=first[t2];first[t2]=i*2;
	}
	for(i=1;i<=n;i++) f[i]=0;
	for(i=1;i<=n;i++) scanf("%d",&c[i]);
	for(i=n;i>=1;i--){
		u=c[i];flag=0;
//		cout<<"doing "<<u<<endl;
		for(j=first[u];~j;j=a[j].next){
			v=a[j].to;
			if(!f[v]) continue;
//			cout<<"	into "<<v<<endl;
			flag=1;
			fx=find(u);fy=find(v);
			if(fx==fy) continue;
//			cout<<"	"<<fx<<ends<<fy<<endl;
//			cout<<"	renew "<<v<<endl;
			join(fx,fy);
		}
		if(flag==0){
			f[u]=-1;
			if(i!=n) ans[i]=0;
			else ans[i]=1;
		}
		else{
			if(f[find(u)]!=-(n-i+1)) ans[i]=0;
			else ans[i]=1;
		}
	}
	for(i=1;i<=n;i++){
		if(ans[i]) printf("YES\n");
		else printf("NO\n");
	}
} 
