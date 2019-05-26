#include<bits/stdc++.h>
using namespace std;
bool tg[25500];
int n,a[150],uplm;

void add(int x){
	for(int i=0;i<=a[n]-x;i++)
		if(tg[i]) tg[i+x]=tg[i];
}

void wk(){
	int cnt=0;
	memset(tg,0,sizeof(tg));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	tg[0]=1;
	for(int i=1;i<=n;i++) 
		if(!tg[a[i]]) add(a[i]);
		else cnt++;
	printf("%d\n",n-cnt);
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d\n",&T);
	while(T--) wk();
}
