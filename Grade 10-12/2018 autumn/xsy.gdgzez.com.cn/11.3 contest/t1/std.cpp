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
#include<map>
#define uint unsigned int
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
int n,top=2,a[100010],dp[100010];uint f[100];
map<int,int>s;
int main(){
	freopen("in.in","r",stdin);
	n=read();int i,j,l,r;
	f[1]=f[2]=1;
	while(f[top]<=2e9){
		f[top+1]=f[top]+f[top-1];
		top++;
	}
	top--;
	for(i=1;i<=top;i++) s[f[i]]=i;
	for(i=1;i<=n;i++) a[i]=read();
	dp[0]=0;
	for(i=1;i<=n;i++){
		dp[i]=1e9;
		for(j=1;j<=i;j++){
			bool flag=1;
			for(l=j;l<i;l++){
				for(r=l+1;r<=i;r++){
					if(s.count(a[l]+a[r])){flag=0;break;}
				}
			}
			if(flag) dp[i]=min(dp[i],dp[j-1]+1);
		}
	}
	printf("%d\n",dp[n]);
}
