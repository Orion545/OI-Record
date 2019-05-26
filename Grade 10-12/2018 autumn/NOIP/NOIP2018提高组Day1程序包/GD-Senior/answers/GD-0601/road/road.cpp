#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 200005
using namespace std;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int N;
int arr[maxn];
long long ans;
void solve(int l,int r){
	if(l==r){
		ans+=arr[l];
		return ;
	}
	if(l>r)
		return ;
	int minn=0x3f3f3f3f,min_pos=0;
	for(int i=l;i<=r;i++){
		if(minn>arr[i]){
			minn=arr[i];
			min_pos=i;
		}
	}
	if(minn!=0){
		ans+=minn;
		for(int i=l;i<=r;i++){
			arr[i]-=minn;
		}
	}
	solve(l,min_pos-1);
	solve(min_pos+1,r);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(N);
	for(int i=1;i<=N;i++)
		read(arr[i]);
	solve(1,N);
	printf("%lld",ans);
}
