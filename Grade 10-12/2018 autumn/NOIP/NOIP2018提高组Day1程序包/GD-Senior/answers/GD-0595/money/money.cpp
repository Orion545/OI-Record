//NOIP2018day1T2	2018.11.10	用bfs类似于筛法的方法筛出不能被其他货币表示出的货币 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int bfs[30000],head,tail,last,i,j,n,a[200],ans,da,t,l;
bool ask[26000];
int read(){
	int ans=0;char c=getchar();
	while(c < '0' || c > '9')	c=getchar();
	while(c >= '0' && c <= '9'){ans=(ans<<1)+(ans<<3)+c-48;c=getchar();}
	return ans;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	t=read();
	for(l=1;l <= t;l++){
		n=read();
		da=0;
		for(i=1;i <= n;i++)	a[i]=read();
		for(i=1;i <= n;i++)	da=max(da,a[i]);
		for(i=0;i <= da;i++)	ask[i]=false;
		for(i=1;i <= n;i++)	bfs[i]=a[i];
		head=last=0;tail=n;
		while(head < tail){
			head=last+1;last=tail;
			for(i=head;i <= last;i++)
				for(j=1;j <= n;j++)
					if(bfs[i]+a[j] <= da)
						if(ask[bfs[i]+a[j]] == false){
							bfs[++tail]=bfs[i]+a[j];
							ask[bfs[i]+a[j]]=true;
						}
		}
		ans=0;
		for(i=1;i <= n;i++)
			if(ask[a[i]] == false)	ans++;
		printf("%d\n",ans);
	}
	return 0;
}
