#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define maxn 35005
using namespace std;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int T,N;
int arr[101];
bool used[maxn];
int ans;
void solve(int x){
	for(int i=1;x*i<=arr[N];i++)
		used[x*i]=1;
	for(int i=0;i+x<=arr[N];i++)
		if(used[i])
			used[i+x]=1;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	read(T);
	while(T--){
		read(N);
		memset(used,0,sizeof(used));
		used[0]=1;
		ans=0;
		for(int i=1;i<=N;i++)
			read(arr[i]);
		sort(arr+1,arr+1+N);
		if(arr[1]==1||N==1){
			printf("1\n");
			continue ;
		}
		for(int i=1;i<=N;i++){
			if(!used[arr[i]]){		
				ans++;
				solve(arr[i]);	
			}
		}
		printf("%d\n",ans);
	}
}
