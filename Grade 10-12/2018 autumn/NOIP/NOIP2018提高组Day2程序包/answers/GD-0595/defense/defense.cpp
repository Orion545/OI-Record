#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int read(){
	int ans=0;c=getchar();
	while(c < '0' || c > '9')	c=getchar();
	while(c >= '0' && c <= '9'){ans=(ans<<1)+(ans<<3)+c-48;c=getchar();}
	return ans;
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read();m=read();i=read();
	for(i=1;i <= n;i++)	w[i]=read();
	for(i=1;i <= n-1;i++){
		a=read();b=read();
		way[++num][0]=b;way[num][1]=far[a];far[a]=num;
		way[++num][0]=a;way[num][1]=far[b];far[b]=num;
	}
	for(l=1;l <= m;l++){
		a=read();b=read();c=read();d=read();
		ans=0;memset(ask,0,sizeof(ask));
		if(b == 1){
			ask[a]=true;ans+=w[a];
			i=a-2;
			while(i > 0){
				ans+=w[i];i-=2;
				ask[i+2]=true;
				ask[i+1]=true;
			}
			i=a+2;
			while(i <= n){
				asn+=w[i];i+=2;
				ask[i-1]=true;
				ask[i-2]=true;
			}
		}
		printf("%d",ans);
	}
	return 0;
}
