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
ll n,a[110],lim;
int main(){
	n=read();lim=read();int i;ll sum=0;
	for(i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		sum+=a[i];
		if(lim<sum){
			cout<<i-1<<'\n';
			return 0;
		}
	}
	if(lim==sum) cout<<n<<'\n';
	else cout<<n-1<<'\n';
}
