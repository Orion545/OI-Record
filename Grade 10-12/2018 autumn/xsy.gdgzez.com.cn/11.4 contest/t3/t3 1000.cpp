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
#include<set>
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
int n,m;
struct node{
	int minn[5],maxn[5],siz;
	inline bool operator <(const node &b) const{
		for(int i=0;i<m;i++) if(maxn[i]>b.minn[i]) return 0;
		return 1;
	}
	inline bool operator >(const node &b) const{
		for(int i=0;i<m;i++) if(minn[i]<b.maxn[i]) return 0;
		return 1;
	}
	void merge(node b){
		siz+=b.siz;
		for(int i=0;i<m;i++){
			minn[i]=min(minn[i],b.minn[i]);
			maxn[i]=max(maxn[i],b.maxn[i]);
		}
	}
}a[100010];
set<node>s;
int main(){
//	cout<<"begin\n";
	n=read();m=read();int i,j;set<node>::iterator it,cur;
	for(i=1;i<=n;i++){
		for(j=0;j<m;j++) a[i].maxn[j]=a[i].minn[j]=read();
		a[i].siz=1;
	}
	for(i=1;i<=n;i++){
		it=s.lower_bound(a[i]);
		while(it!=s.end()&&!((*it)>a[i])){
			cur=it;it++;
			a[i].merge(*cur);
			s.erase(cur);
		}
		s.insert(a[i]);
		it=s.end();it--;
		printf("%d ",it->siz);
	}
}
