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
int n,m;char s[10010][10010];
int random(int l,int r){
	return rand()%(r-l+1)+l;
}
int main(){
	srand(time(NULL));
	n=10000;m=10000;int i;
	printf("%d %d\n",n,m);
	for(i=1;i<=m;i++){
		s[1][i]=(char)random((int)'a',(int)'z');
		putchar(s[1][i]);
	}
	putchar('\n');
	for(i=2;i<=n;i++){
		int f=random(0,1),pos=random(1,m),pre=random(1,i-1);
		char c;
		if(s[pre][pos]=='a') c=random((int)'b',(int)'z');
		else if(s[pre][pos]=='z') c=random((int)'a',(int)'y');
		else c=f*random((int)'a',(int)s[pre][pos]-1)+(f^1)*random((int)s[pre][pos]+1,(int)'z');
//		c=s[pre][pos];
		printf("%d %d %c\n",pre,pos,c);
		memcpy(s[i],s[pre],sizeof(s[pre]));
		s[i][pos]=c;
	}
}
