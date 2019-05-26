/*

���桪��
��������֮�£��и���֮��������֮����
���ʥ��֮����������Ӵ���־������Ӧ�ɡ�
�ڴ����ģ����ǳɾ�����һ������֮�ˣ�������������һ�����֮�ˣ�
������֮����������ͽ�����Ǵ������Ĳ����ߣ�
��Ϊ�����������֮���죬����ֹ֮�����ְɣ����֮�ػ��ߣ�

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
#define MOD 998244353
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll cnt[100010];ll ans=0,n,m;
void add(ll &a,ll b){
	a+=b;
	if(a>=MOD) a-=MOD;
}
int main(){
//	freopen("in.in","r",stdin);
	n=read();m=read();
	ll i,j,lim,t1,t2,t3,k,orz=sqrt(m);
	for(i=1;i<=n;i++){
		lim=read();
		cnt[lim]++;
	}
	for(i=1;i<=orz;i++){
		for(j=1;j<=i;j++){
			t1=i*i-j*j;t3=i*i+j*j;t2=2*i*j;
			if(t3>m) break;
			if(__gcd(t3,__gcd(t1,t2))>1) continue;
			for(k=1;k*t3<=m;k++){
				add(ans,cnt[t1*k]*cnt[t2*k]*cnt[t3*k]%MOD);
			}
		}
	}
	
	cout<<ans<<'\n';
}
