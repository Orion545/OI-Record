#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const bool local=0;
const int N=1e5+2;
void read(int &x){
	int c=getchar();
	x=0;
	while((c<'0')||(c>'9'))c=getchar();
	while((c>='0')&&(c<='9')){
		x=x*10+(c^48);
		c=getchar();
	}
	return;
}
int tou[N],shu,wei[N<<1],xt[N<<1];
void add(int x,int y){
	++shu;
	nxt[shu]=tou[x];
	tou[x]=shu;
	wei[shu]=y;
}
int n,m,p,q,r,t,f[N][2],c[N],ans;
bool v[N];
int main(){
	read(n);read(m);read(t);
	for (int i = 1; i <= n; ++i){
		read(c[i]);
	}
	for (int i=1;i<n;++i){
		read(p);read(q);
		add(p,q);add(q,p);
	}
	for (int i = 0; i < m; ++i)
	{
		memset(f,0x3f,sizeof f);
		read(p);read(r);
		if (r) f[p][1]=c[p];
		if (!r) f[p][0]=0;
		read(q);read(r);

	}
}