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
	freopen("gen.in","w",stdout);
	srand(time(NULL));
	int n=50000,m=50000,t1,t2;
	printf("%d %d\n",n,m);
	while(m--){
		if(m>=20000){
			printf("0 ");
			t1=random(1,n);
			if(t1==1) t2=random(2,n);
			else t2=random(1,n-1);
			printf("%d %d\n",t1,t2);
		}
		else{
			printf("1 ");
			t1=random(1,n);
			if(t1==1) t2=random(2,n);
			else t2=random(1,n-1);
			printf("%d %d\n",t1,t2);
		}
	}
}
