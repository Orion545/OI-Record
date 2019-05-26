#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
#define re register int
using namespace std;
const int N = 105;
const int M = 25005;
int a[N],n,T,maxn;
int f[M];
bool used[N],flag;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch == '-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T = read();
	while(T--){
		n = read();
		flag = false;
		for(re i=1; i<=n; i++){
			a[i] = read();
			maxn = max(maxn,a[i]);
			if(a[i] == 1){
				flag = true;
			}
		}
		if(flag){
			printf("1\n");
			continue;
		}
		sort(a+1,a+n+1);
		memset(f,0,sizeof(f));
		int cnt=0,ans=0;
		for(re i=1; i<=n; i++){
			if(f[a[i]]){
				ans++;
				continue;
			}
			f[a[i]] = 1;
			for(re j=a[i]+1;j<=maxn;j++){
				if(f[j-a[i]]){
					f[j] = 1;
				}
			}
			cnt = 0;
			for(re j=1; j<=n; j++){
				if(f[a[j]]){
					cnt ++;
				}
			}
			if(cnt == n){
				printf("%d\n",i-ans);
				flag = true;
				break;
			}
		}
		if(!flag){
			printf("%d\n",n);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
