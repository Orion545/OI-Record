#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
const int N=1e5+7;
using namespace std;
int read(){
	int ans=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-48;c=getchar();}
	return ans*f;
}
int f[N],a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read();a[0]=0;f[0]=0;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		if(a[i]<=a[i-1])f[i]=f[i-1];
		else{
			f[i]=f[i-1]+(a[i]-a[i-1]);
		}
	}
	printf("%d",f[n]);
	fclose(stdin);fclose(stdout);
	return 0;
}
