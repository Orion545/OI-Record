#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
#define il inline
#define rg register
#define fileName "money"

il char gtc();
il int read();

int T,N,ans;
int A[105];

bool dfs(int,int);
int main(){
	freopen(fileName".in","r",stdin),
	freopen(fileName".out","w",stdout);
	T=read();
	while(T--){
		N=read(),
		ans=0;
		for(rg int i=0;i<N;++i)
			A[i]=read();
		sort(A,A+N);
		for(rg int i=0;i<N;++i)
			if(!dfs(i,A[i]))
				++ans;
		printf("%d\n",ans);
	}
	return 0;
}

bool dfs(int x,int q){
	if(q==0)
		return true;
	for(rg int i=x-1;i>=0;--i)
		if(q>=A[i])
			if(dfs(i+1,q-A[i]))
				return true;
	return false;
}
char gtc(){
	static char buff[0xFFFF],*p1=buff,*p2=buff;
	return ((p1==p2)&&(p2=(p1=buff)+fread(buff,1,0xFFFF,stdin),p1==p2))?(EOF):(*p1++);
}
int read(){
	int t=0;
	char c=gtc();
	while((c<'0')||(c>'9'))
		c=gtc();
	while((c>='0')&&(c<='9'))
		t=t*10+c-'0',
		c=gtc();
	return t;
}
