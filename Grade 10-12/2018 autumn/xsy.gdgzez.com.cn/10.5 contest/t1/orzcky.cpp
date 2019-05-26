#include<iostream>
#include<bitset>
#include<cstdio>
#include<cstring>
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
int T,n,k,x,cs;double ans;bitset<1005>e[1005];
int main()
{
    for(T=read();T--;cs++,printf("Case #%d: %.5lf\n",cs,ans),ans=0)
    {
        n=read();for(int i=1;i<=n;i++) e[i].reset(),e[i][i]=1;
        for(int i=1,j;i<=n;i++) for(k=read(),j=1;j<=k;j++) x=read(),e[i][x]=1;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(e[j][i]) e[j]|=e[i];
        for(int i=1,gg=0;i<=n;i++,ans+=1.0/gg,gg=0) for(int j=1;j<=n;j++) gg+=(e[j][i]==1);
    }
}

