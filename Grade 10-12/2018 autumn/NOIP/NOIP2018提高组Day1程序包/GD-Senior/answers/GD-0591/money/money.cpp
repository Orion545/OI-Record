#define il inline
#define rg register
#define For(i,a,b) for(rg int i=(a);i<=(b);i++)
#define rep(i,n) for(rg int i=0;i<(n);i++)
typedef long long LL;
typedef unsigned int u32;
typedef unsigned long long u64;
const int N=110,M=1000000007,INF=0x3f3f3f3f;
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

//freopen(".in","r",stdin);freopen(".out","w",stdout);

il void read(int &x){
	x=0;int f=1;char c=getchar();
	while((c<'0'||c>'9')&&(c!=EOF)){if(c=='-')f=-1;c=getchar();}
	if(c==EOF)return;
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}

int n,a[N],t;
int b[N],tot;
bool f[26000];int v;
int ans;

int main(){
	freopen("money.in","r",stdin);freopen("money.out","w",stdout);
	
	read(t);
	while(t--){
		memset(f,0,sizeof f);f[0]=1;ans=0;tot=1;
		
		read(n);
		For(i,1,n){
			read(a[i]);if(a[i]==1){ans=1;}
		}
		if(ans==1){printf("1\n");continue;}
		sort(a+1,a+1+n);b[1]=a[1];
		For(i,2,n){
			bool flag=1;
			For(j,1,i-1)if(a[i]%a[j]==0){flag=0;break;}
			if(flag)b[++tot]=a[i];
		}
		v=b[tot];
		For(i,1,tot)if(!f[b[i]]){
			For(j,b[i],v)f[j]|=f[j-b[i]];
			ans++;
		}
		printf("%d\n",ans);
	
	}
	return 0;
}



