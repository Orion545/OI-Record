#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
inline ll rd(){
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0'; c=getchar();}
	return f*x;
} 
const int maxn=100;
ll N,T,A[maxn+50],ans,B[maxn+50],num;
bool flag;
inline void Dfs(int now,ll sum){
	if(flag)return;
	if(sum==0){
		flag=1;
		return;
	}
	if(now>num)return;
	for(int k=0;k*B[now]<=sum;k++)
		Dfs(now+1,sum-B[now]*k);
	return;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=rd();
	while(T--){
		N=rd();
		for(int i=1;i<=N;i++)A[i]=rd();
		sort(A+1,A+N+1);
		if(A[1]==1)ans=1;
		else if(N==2){
			if(A[2]%A[1]==0)ans=1;
			else ans=2;
		}
		else{
			B[1]=A[1];
			num=1;
			for(int i=2;i<=N;i++){
				flag=0;
				Dfs(1,A[i]);
				if(flag==0)B[++num]=A[i];
			}
			ans=num;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
