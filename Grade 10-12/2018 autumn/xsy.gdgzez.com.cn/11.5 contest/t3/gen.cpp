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
#include<ctime>
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
int random(int l,int r){
	return rand()%(r-l+1)+l;
}
int main(){
	freopen("in.in","w",stdout);
	srand(time(NULL));
	int n=100000,i;
	printf("%d\n",n);
	for(i=2;i<=n;i++) printf("%d %d\n",random(1,i-1),i);
	for(i=1;i<=n;i++) printf("%d ",random(1,10000)*2);
}
