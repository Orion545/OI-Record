#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 100001
#define LL long long
#define MAXN 99999999
using namespace std;
void read(int &x){
	char c;int f=1;x=0;c=getchar();
	while(c>57||c<48){if(c==45)f=-1;c=getchar();}
	while(c>=48&&c<=57){x=x*10+c-48;c=getchar();}
	x*=f;
}
int n,d[N];
//long long?
//k:ÒÑÍÚµÄÊý 
LL cal(int l,int r,int k){
	//!!!!
	//cout<<l<<" "<<r<<" "<<k<<endl;
	if(l==r)return (long long)(d[l]-k);
	int minn=MAXN;
	for(int i=l;i<=r;i++)
		if(d[i]<minn)minn=d[i];
	//cout<<minn<<endl;
	LL ans=(long long)(minn-k);
	int L=l;
	//cout<<ans<<endl;
	while(d[L]==minn)L++;
	bool flag=0;
	for(int i=L;i<=r;i++){
		if(flag){
			if(d[i]!=minn){
				flag=0;
				L=i;
			}
			else if(d[i]==minn)continue;
		}
		if(d[i]==minn){
			ans+=cal(L,i-1,minn);
			flag=1;
			continue;
		}
		if(i==r)ans+=cal(L,i,minn);
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)read(d[i]);
	printf("%lld\n",cal(1,n,0));
	return 0;
	fclose(stdin);
	fclose(stdout);
}
/*
6
4 3 2 5 3 5

7
9 8 2 4 2 6 5
*/
