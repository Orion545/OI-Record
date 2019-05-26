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
int cnt[100010];ll ans=0,n,m;
void add(ll &a,ll b){
	a+=b;
	if(a>=MOD) a-=MOD;
}
int main(){
	freopen("in.in","r",stdin);
	n=read();m=read();
	ll i,j,lim,tmp;
	for(i=1;i<=n;i++){
		lim=read();
		cnt[lim]++;
	}
	for(i=3;i<m;i++){
		if(!cnt[i]) continue;
		if(i%1000==0) cout<<"check "<<i<<'\n';
		lim=min((i*i)>>1,(ll)sqrt(m*m-i*i));
		if(lim<=i) break;
		for(j=i+1;j<=lim;j++){
			tmp=sqrt(i*i+j*j);
			if(tmp*tmp==i*i+j*j)
				add(ans,cnt[i]*cnt[j]*cnt[tmp]%MOD);
		}
	}
	cout<<ans<<'\n';
}
