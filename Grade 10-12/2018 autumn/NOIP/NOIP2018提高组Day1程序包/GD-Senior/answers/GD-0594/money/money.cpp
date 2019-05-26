#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n,T;
int a[110];
bool tf[25010];
int mmax,ans;

int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		memset(tf,false,sizeof(tf));
		mmax=0;ans=0;tf[0]=true;
		for(int i=1;i<=n;i++) a[i]=read(),mmax=max(mmax,a[i]);
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			if(tf[a[i]]) continue;
			ans++;
			for(int k=0;k+a[i]<=mmax;k++) tf[k+a[i]]|=tf[k];
		}
		printf("%d\n",ans);
	}
	return 0;
}
