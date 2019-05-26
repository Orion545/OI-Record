#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
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
vector<int>num[1000010];
int n,m,len;
int main(){
	n=read();int i,t1,t2,tmp;
	for(i=1;i<=n;i++) t1=read(),num[t1].push_back(i);
	m=read();
	while(m--){
		len=read();
//		cout<<"read in "<<len<<'\n';
		tmp=0;bool flag=1;
		for(i=1;i<=len;i++){
			t1=read();
			if(!flag) continue;
			t2=lower_bound(num[t1].begin(),num[t1].end(),tmp+1)-num[t1].begin();
//			cout<<"	do "<<i<<' '<<t1<<' '<<t2<<' '<<'\n';
			if(t2<num[t1].size()) tmp=num[t1][t2];
			else flag=0;
		}
		if(flag) puts("TAK");
		else puts("NIE");
	}
}
