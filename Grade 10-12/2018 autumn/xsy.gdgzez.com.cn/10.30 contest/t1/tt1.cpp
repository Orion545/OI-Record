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
int n,a[2010];
struct node{
	int val,s;
}x[1100010];int cnt=0;
inline bool cmp(node l,node r){return l.val<r.val;}
int main(){
	n=read();int i,sum=0,maxn=0;
	for(i=1;i<=n;i++) a[i]=read();
	
	if(n<=20){
		for(int s=1;s<(1<<n);s++){
			int tmp=0;
			for(i=1;i<=n;i++) if(s&(1<<(i-1))) tmp+=a[i];
			x[++cnt]=(node){tmp,s};
		}
		sort(x+1,x+cnt+1,cmp);
		cout<<x[(cnt+1)>>1].val<<'\n';
		return 0;
	}
	
	for(i=1;i<=n;i++) sum+=a[i],maxn=max(maxn,a[i]);
	if(maxn>=sum-maxn){printf("%d\n",maxn);return 0;}
	
	printf("%d\n",sum/2+(sum&1));
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
