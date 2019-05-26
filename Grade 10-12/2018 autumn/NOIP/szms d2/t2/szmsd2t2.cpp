/*

���桪��
�����������и���֮��������֮����
Ӧʥ��֮�٣�������Ӵ���־������Ӧ�ɡ�
�ڴ����ģ���Ը�ɾ�����һ��֮���У���Ը�ﾡ����һ��֮���С�
��Ϊ�����������֮���죬����ֹ֮�����ְɣ����֮�ػ��ߣ�

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<queue>
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
inline void add(int &a,int b){
	a+=b;
	if(a>=MOD) a-=MOD;
}
int n,a[110],dp[110][20][2];
int dfs(int pos,int val,int top){
	if(dp[pos][val][top]) return dp[pos][val][top];
	if(pos==n+1) return dp[pos][val][top]=1;
	int j,lim=(top?a[pos]:9);
	for(j=val;j<=lim;j++){
		add(dp[pos][val][top],dfs(pos+1,j,top&&(j==lim)));
	}
	return dp[pos][val][top];
}
char s[110];
int main(){
	int i;
	
	scanf("%s",s);
	n=strlen(s);
	for(i=0;i<n;i++) a[i+1]=s[i]-'0';
	a[n]--;i=n;
	while(a[i]<0){
		a[i]+=10;
		a[i-1]--;
		i--;
	}
	if(a[1]==0){
		for(i=1;i<n;i++) a[i]=a[i+1];
		n--;
	}
	
	int ans0=dfs(1,0,1);
	
	memset(s,0,sizeof(s));
	memset(a,0,sizeof(a));
	memset(dp,0,sizeof(dp));
	
	scanf("%s",s);
	n=strlen(s);
	for(i=0;i<n;i++) a[i+1]=s[i]-'0';
	
	int ans1=dfs(1,0,1);
	
	cout<<(ans1-ans0+MOD)%MOD<<'\n';
}
