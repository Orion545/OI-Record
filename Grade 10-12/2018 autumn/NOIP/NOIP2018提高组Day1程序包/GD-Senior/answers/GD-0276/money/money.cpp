#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=105;
int f[30005],n,a[N],T,ans,mxa;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	for (cin>>T;T--;){
		cin>>n;mxa=0;
		for (int i=1;i<=n;i++)scanf("%d",&a[i]),mxa=max(mxa,a[i]);
		sort(a+1,a+n+1);
		memset(f,0,sizeof f);
		f[0]=1;
		ans=0;
		for (int i=1;i<=n;i++){
			if (f[a[i]])continue;ans++;
			for (int j=a[i];j<=mxa;j++)f[j]|=f[j-a[i]];
		}
		cout<<ans<<endl;
	}
	return 0;
}
