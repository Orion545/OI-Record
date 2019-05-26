#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#define F(i,x,y) for(int i=x;i<=y;++i)

using namespace std;

const int M=600010;
long long n,m;
long long ans=0;

long long a[M];

void dg(int u,int v){

	long long Mm=M;
		
	F(i,u,v) if(a[i]<Mm) Mm=a[i];

	ans+=Mm;
	F(i,u,v) a[i]-=Mm;
		
	int i=u,las=0;
	while(i<=v){
		if(!las&&!a[i]) i++;
		else if(las&&a[i]) i++;
		else if(!las&&a[i]){
			las=i;
			i++;
		}
		else{
			dg(las,i-1);
			las=0;
		}
	}
		
	if(las) dg(las,v);
}

long long read(){
	long long ret=0;
	char ch=getchar();
	while(!(ch>='0'&&ch<='9')) ch=getchar();
	while((ch>='0'&&ch<='9')) ret=ret*10+ch-'0',ch=getchar();
	return ret;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n=read();
	
	F(i,1,n) a[i]=read();
	dg(1,n);

	printf("%lld\n",ans);
	return 0;
}
