#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,p[10000010],prime[1000010],cnt;
void shai(){
	int i,j;
	for(i=2;i<=n;i++) p[i]=1;
	p[1]=0;
	for(i=2;i<=n;i++){
//		cout<<i<<ends<<p[i]<<ends<<cnt<<endl;
		if(p[i]) prime[++cnt]=i;
		for(j=1;j<=cnt&&i*prime[j]<=n;j++){
//			cout<<"	renew "<<i*prime[j]<<endl;
			p[i*prime[j]]=0;
			if(i%prime[j]==0) break;
		}
	}
}
int main(){
	int t1,i;
	scanf("%d%d",&n,&m);
	shai();
	for(i=1;i<=m;i++){
		scanf("%d",&t1);
		if(p[t1]) printf("Yes\n");
		else printf("No\n");
	}
} 
