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
int n,a[100010],b[100010],rka[100010];
int x[100010],dp[100010];
int main(){
//	freopen("in.in","r",stdin);
	n=read();int i,len,cur;
	for(i=1;i<=n;i++) a[i]=read(),rka[a[i]]=i;
	for(i=1;i<=n;i++) b[i]=read(),x[i]=rka[b[i]];
	memset(dp,127,sizeof(dp));
	dp[0]=0;dp[1]=a[1];len=1;
	for(i=2;i<=n;i++){
		cur=upper_bound(dp,dp+len+1,x[i])-dp-1;
//		cout<<"find "<<i<<' '<<cur<<'\n';
		if(cur==len) len++;
		dp[cur+1]=x[i];
	}
	cout<<len<<' '<<'\n';
}
