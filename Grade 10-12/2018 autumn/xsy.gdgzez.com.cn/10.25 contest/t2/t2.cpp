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
int tot,n,a[200010],aa[200010];
int main(){
	tot=read();n=read();int i,pos1=0,pos2=0,cnt=1;
	for(i=1;i<=n;i++){
		a[i]=read();
		if(a[i]&1){
			if(pos2){puts("Impossible");return 0;}
			if(pos1) pos2=i;
			else pos1=i;
		}
	}
	if(!pos1){
		for(i=1;i<=n;i++) aa[i]=a[i];
	}
	else{
		for(i=1;i<=n;i++){
			if(i==pos1) aa[1]=a[i];
			else if(i==pos2) aa[n]=a[i];
			else aa[++cnt]=a[i];
		}
	}
	if(n==1){
		cout<<a[1]<<'\n';
		if(a[1]==1) puts("1\n1");
		else printf("2\n%d %d\n",a[1]-1,1);
		return 0;
	}
	for(i=1;i<=n;i++) printf("%d ",aa[i]);
	puts("");
	aa[1]++;aa[n]--;if(aa[n]==0) n--;
	printf("%d\n",n);
	for(i=1;i<=n;i++) printf("%d ",aa[i]);
}
