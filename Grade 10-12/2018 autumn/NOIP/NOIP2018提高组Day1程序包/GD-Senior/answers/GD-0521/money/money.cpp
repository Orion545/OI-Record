#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;
int T,n,mxai,ans;
int a[110];
bool b[25010],bpi[25010];
inline int rd(){
	int ret=0;char c=getchar();
	for(;!isdigit(c);)c=getchar();
	for(;isdigit(c);)ret=ret*10+c-'0',c=getchar();
	return ret;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=rd();
	while(T--){
		ans=0;
		memset(b,0,sizeof(b));
		memset(bpi,0,sizeof(bpi));
		n=rd();
		for(int i=1;i<=n;i++){
			a[i]=rd();
			bpi[a[i]]=1;
			mxai=max(mxai,a[i]);
		}
		for(int i=1;i<=n;i++)
			for(int j=a[i]<<1;j<=mxai;j+=a[i])b[j]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=mxai;j++)
				if(b[j]||bpi[j])
					for(int k=j+a[i];k<=mxai;k+=a[i])b[k]=1;
		for(int i=1;i<=n;i++)
			if(b[a[i]]!=1)ans++;
		printf("%d\n",ans);
	}
}
