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
int main(){
	int n;double p1=0,p2=0,p3=0,p;
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%lf",&p);
		p3=p*(p3+3.0*p2+3.0*p1+1.0)+(1.0-p)*p3;
		p2=p*(p2+2.0*p1+1.0);
		p1=p*(p1+1.0);
//		cout<<i<<' '<<p1<<' '<<p2<<' '<<p3<<'\n';
	}
	printf("%.1lf\n",p3);
}
