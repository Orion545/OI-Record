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
#include<bitset>
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
int n;bitset<4000010>b;
int main(){
	n=read();b[0]=1;int i,sum=0,a;for(i=1;i<=n;i++) a=read(),b|=b<<a,sum+=a;
	for(i=(sum+1)/2;;i++) if(b[i]){cout<<i;return 0;}
}
/*

20
100 200 300 400 500 600 1000 1 1 1 1 1 1
123
132
1
3

2
3
7657


*/
