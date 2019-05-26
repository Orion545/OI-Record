#include<stdio.h>
#include<algorithm>
#define N 50005
using namespace std;
int i,j,k,n,m,a,b,c,h[N],v[N],s[N],f[2][N],ans;
struct ha{
	int a,b,c,n;
	bool operator < (const ha &A)const{
		return c<A.c;
	}
}d[N*2];
void charu(int a,int b,int c){
	d[++j].a=a,d[j].b=b,d[j].c=c;
	d[j].n=h[a],h[a]=j;
	d[++j].b=a,d[j].a=b,d[j].c=c;
	d[j].n=h[b],h[b]=j;
}
void dfs(int a){
	int i,b,he1=0,he2=0,c;
	for(i=h[a];i;i=d[i].n){
		b=d[i].b,c=d[i].c;
		if(!v[b]){
			v[b]=1;
			dfs(b);
			if(s[b]+c>=he1)he2=he1,he1=s[b]+c;
			else if(s[b]+c>he2)he2=s[b]+c;
		}
	}
	s[a]=he1;
	if(he1+he2>ans)ans=he1+he2;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==1){
		for(i=1;i<n;i++){
			scanf("%d%d%d",&a,&b,&c);
			charu(a,b,c);
		}
		v[1]=1,dfs(1);
		printf("%d",ans);
	}
	else{
		int o=0,oo=0;
		for(i=1;i<n;i++){
			scanf("%d%d%d",&a,&b,&c);
			charu(a,b,c);
			if(a!=1)o=1;
			if(b!=a+1)oo=1;
		}
		if(!o){
			sort(d+1,d+2*n-1);
			int a[N];
			for(i=1;i<n;i++)a[i]=d[i*2-1].c;
			n--;
			if(m*2<=n){
				j=n-m,ans=1e9;
				for(i=1;i<=m;i++){
					if(a[j+i]+a[j+1-i]<ans)ans=a[j+i]+a[j+1-i];
				}
				printf("%d",ans);
			}
			else{
				j=2*m-n,ans=a[n+1-j];
				for(i=1;i<=(n-j)/2;i++){
					if(a[i]+a[n-j+1-i]<ans)ans=a[i]+a[n-j+1-i];
				}
				printf("%d",ans);
			}
		}
		else if(!oo){
			int a[N];n--;
			for(i=1;i<n*2;i+=2){
				a[d[i].a]=d[i].c;
			}
			for(i=1;i<=n;i++)s[i]=s[i-1]+a[i],f[1][i]=s[i];
			for(i=2;i<=m;i++){
				o=i%2;
				for(j=i;j<=n;j++){
					f[o][j]=0;
					for(k=i-1;k<j;k++){
						f[o][j]=max(f[o][j],min(f[o^1][k],s[j]-s[k]));
					}
				}
			}
			printf("%d",f[m%2][n]);
		}		
	}
	return 0;
}
