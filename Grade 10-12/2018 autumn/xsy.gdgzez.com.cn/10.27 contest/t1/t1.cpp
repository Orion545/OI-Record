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
long double n,nn,d,delta;
long double calc(long double st,long double del,long double tot){
	return (st+del*(tot+1.0)/2.0);
}
int main(){
	nn=n=read();d=read();delta=read();d-=delta;
	long double ans=0;
	for(int i=1;i<=nn;i++){
		ans+=calc(d,delta,n*2.0);
//		cout<<i<<' '<<d<<' '<<delta<<' '<<ans<<'\n';
		d=(3.0*delta+(n*2.0+2.0)*d)/(n*2.0);
		delta=((n*2.0+4.0)*delta)/(n*2.0);
		n--;
	}
	printf("%.15lf\n",(double)ans);
}

