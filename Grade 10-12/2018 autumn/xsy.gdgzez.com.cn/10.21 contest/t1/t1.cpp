#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<set>
#define next DEEP_DARK_FANTASY
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
int n,next[100010];
char a[100010];set<int>s;
int main(){
	n=read();int i,tmp;char j;
	for(i=1;i<=n;i++){
		next[i]=read();
		next[i]=i-next[i];
	}
	next[0]=-1;
	a[1]='a';
	for(i=2;i<=n;i++){
		if(next[i]>0){a[i]=a[next[i]];continue;}
		s.clear();tmp=next[i-1]+1;
		while(tmp){
			s.insert(a[tmp]);
			tmp=next[tmp-1]+1;
		}
		j='a';
		while(s.count(j)) j++;
		a[i]=j;
	}
	printf("%s",a+1);
}
