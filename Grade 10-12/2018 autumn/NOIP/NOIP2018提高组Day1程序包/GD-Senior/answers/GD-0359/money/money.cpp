#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#define INF 0x3f3f3f3f
using namespace std;
const int N=110;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<48||ch>57) f=(ch=='-')?-1:1,ch=getchar();
	while (ch>=48&&ch<=57) x=(x*10)+(ch^48),ch=getchar();
	return x*f;
}
int t,n,a[N],ans=0,v[25010];
int dfs(int left,int num){
	if (v[left]!=0) return v[left]; 
	//printf("left=%d num=%d a[num]=%d\n",left,num,a[num]);
	int f=1;
	if (left==0) return -1;
	if (num==0) return 1;
	if (a[num]==0) return f=((v[left]=dfs(left,num-1))==-1)?-1:f;
	for (int j=0;left-a[num]*j>=0;j++){
		//printf("now j=%d a[num]=%d find %d %d\n",j,a[num],left-a[num]*j,num-1);
		f=((v[left]=dfs(left-a[num]*j,num-1))==-1)?-1:f;
	}
	return f;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	t=read();
	while (t--){
		ans=1;
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		sort(a+1,a+1+n);
		/*if (n==2){
			if (a[2]%a[1]==0) printf("1\n");else printf("2\n");
			continue;
		}
		if (n==3){
			if (a[2]%a[1]==0){
				if (a[3]%a[1]==0) printf("1\n");else printf("2\n");
			}else{
				int flag=0;
				for (int i=0;a[3]-i*a[1]>=0;i++)if ((a[3]-i*a[1])%a[2]==0){
					 flag=1;
					 break;
				}
				if (flag) printf("2\n");else printf("3\n");
			}
			continue;
		}*/
		for (int i=2;i<=n;i++) {
			int f=1;
			for (int j=1;j<=i-1;j++) if ((a[j]!=0)&&(a[i]%a[j]==0)) {
				a[i]=0;
				f=0;
				break;
			}
			memset(v,0,sizeof(v));
			if (f&&(dfs(a[i],i-1)==1)) ++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}
