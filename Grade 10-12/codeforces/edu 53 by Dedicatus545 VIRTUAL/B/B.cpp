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
int n,a[200010],pos[200010],b[200010];
int main(){
	n=read();int i,cur=0;
	for(i=1;i<=n;i++){
		a[i]=read();
		pos[a[i]]=i;
	}
	for(i=1;i<=n;i++){
		b[i]=read();
		if(pos[b[i]]>cur){
			printf("%d ",pos[b[i]]-cur);
			cur=pos[b[i]];
		}
		else{
			printf("0 ");
		}
	}
}
