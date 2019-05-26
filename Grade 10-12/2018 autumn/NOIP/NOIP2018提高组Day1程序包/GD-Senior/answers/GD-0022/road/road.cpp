#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
#define maxn 100005
int n;
void read(int &x){
	x=0;char ch=getchar();bool f=0;
	while(ch<'0'||ch>'9'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	if(f)x=-x;
}
void read(long long &x){
	x=0;char ch=getchar();bool f=0;
	while(ch<'0'||ch>'9'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	if(f)x=-x;
}
int a[maxn];
int cf[maxn];
long long sum=0;
long long f=0;
long long hsum[maxn];
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
		cf[i]=a[i]-a[i-1];
	}
//	for(int i=1;i<=n;i++){
//		cout<<cf[i]<<" ";
//	}
	for(int i=1;i<=n;i++){
        sum+=abs(cf[i]);
		if(cf[i]<0)f+=(-cf[i]);
	}
	long long temp=0;
//	cout<<sum<<endl;
	long long zs=0;
	for(int i=1;i<=n;i++){
		if(cf[i]>=0){
			zs+=cf[i];
//			cf[i]=0;
		}
		else{
//			cout<<"check"<<endl;
			zs-=(0-cf[i]);
			sum-=2*(0-cf[i]);
			ans+=(0-cf[i]);
			cf[i]=0;
		}
	}
/*	for(int i=1;i<=n;i++){
		cout<<cf[i]<<" ";
	}
	cout<<zs<<endl;
	for(int i=1;i<=n;i++){
		ans+=cf[i];
	}*/
	ans+=zs;
	cout<<ans<<endl;
}
