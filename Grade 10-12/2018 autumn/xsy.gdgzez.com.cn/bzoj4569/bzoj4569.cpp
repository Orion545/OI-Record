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
#define log DEEP_DARK_FANTASY
#define ll long long
#define MOD 1000000007
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
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
int n,m;
int f[20][100010],log[200100];
int find(int cur,int x){return ((f[cur][x]==x)?x:(f[cur][x]=find(cur,f[cur][x])));}
void join(int cur,int l,int r){
	int fl=find(cur,l),fr=find(cur,r);
	f[cur][fl]=fr;
}
int main(){
	n=read();m=read();int i,t1,t2,t3,t4,j;
	for(j=0;j<=19;j++){
		for(i=1;i<=n;i++) f[j][i]=i;
	}
	for(i=2;i<=n;i++) log[i]=log[i>>1]+1;
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();t4=read();j=log[t2-t1];
		join(j,t1,t3);
		join(j,t2-(1<<j)+1,t4-(1<<j)+1);
	}
	for(j=log[n];j>0;j--){
		for(i=1;i<=n-(1<<j)+1;i++){
			t1=find(j,i);
			join(j-1,t1,i);
			join(j-1,t1+(1<<(j-1)),i+(1<<(j-1)));
		}
	}
	int cnt=0;
	for(i=1;i<=n;i++) cnt+=(find(0,i)==i);
	printf("%lld\n",9ll*qpow(10,cnt-1)%MOD);
}
