#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,damage,times,money,repair,ans=0;
void dfs(int x,int hp,int sum){
	//���dfs��ʾ�����x���ʱ�򣬵������ֵΪhp���Ѿ���õ�������Ϊsum
	//��ʵ���Լ��仯�������� 
	if(hp>=100) hp=100;
	if(hp<=0) hp=0;
	ans=max(ans,sum);
	if(x>n) return;
	hp=hp-(((x+1)%times)==0)*damage;
	dfs(x+1,hp,sum+money*hp);
	dfs(x+1,hp+repair,sum);
}
int main(){
	freopen("Archer.in","r",stdin);
	freopen("Archer.out","w",stdout);
	n=read();damage=read();times=read();money=read();repair=read();
	dfs(1,100,0);
	printf("%d\n",ans);
//	system("pause"); 
}
/*
3 10 1 100 10

*/

