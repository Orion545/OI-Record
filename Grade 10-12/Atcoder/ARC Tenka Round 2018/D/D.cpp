/*

���桪��
��������֮�£��и���֮��������֮����
���ʥ��֮����������Ӵ���־������Ӧ�ɡ�
�ڴ����ģ����ǳɾ�����һ������֮�ˣ�������������һ�����֮�ˣ�
������֮����������ͽ�����Ǵ������Ĳ����ߣ�
��Ϊ�����������֮���죬����ֹ֮�����ְɣ����֮�ػ��ߣ�

*/
#include<vector>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
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
int n;
vector<int>s[100010];
int main(){
	n=read();int tmp=n,i,j,cur=0;
	tmp*=2;tmp=(int)sqrt(tmp);
	if(tmp*(tmp+1)!=n*2){puts("No");return 0;}
	puts("Yes");
	for(i=1;i<=tmp;i++){
		for(j=1;j<=i;j++){
			s[i+1].push_back(cur+j);
			s[j].push_back(cur+j);
		}
		cur+=i;
	}
	printf("%d\n",tmp+1);
	for(i=1;i<=tmp+1;i++){
		printf("%d",s[i].size());
		for(auto j:s[i]) printf(" %d",j);
		printf("\n");
	}
}

