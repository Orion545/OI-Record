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
int n,cnt[1010][30],pre[1010][30];
char s[1010];
int main(){
	n=read();scanf("%s",s);int i,j,k;
	for(i=0;i<n;i++){
		cnt[i+1][s[i]-'a']++;
	}
	for(i=1;i<=n;i++){
		for(j=0;j<26;j++){
			pre[i][j]=pre[i-1][j]+cnt[i][j];
		}
	}
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			bool flag=1;
			for(k=0;k<26;k++){
				if(pre[j][k]-pre[i-1][k]>((j-i+1)/2)) flag=0;
			}
			if(flag){
				puts("YES");
				for(k=i-1;k<j;k++) putchar(s[k]);
				return 0;
			}
		}
	}
	puts("NO");
}
