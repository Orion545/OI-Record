#include<iostream>
#include<cstring>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<cstdlib>
#include<cstdio>
#include<map>
#include<bitset>
#include<set>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
#define MAXN 1010
#define MAXM 1010
#define ll long long
#define eps 1e-8
#define MOD 1000000007
#define INF 1000000000
int p[40000010];
int C[40000010];
int s[40000010];
int *c;
int seed,n,k,S;
int ans1,ans2,ans3;
int getrand(){
	seed=((seed*12321)^9999)%32768;
	return seed;
}
void generateData(){
	scanf("%d%d%d",&k,&seed,&S);
	int t=0;
	n=k*2+1;
	memset(p,0,sizeof(p));
	for(int i=1;i<=n;i++)
	{
		p[i]=(getrand()/128)%2;
		t+=p[i];
	}
	int i=1;
	while(t>k)
	{
		while(p[i]==0)
			i++;
		p[i]=0;
		t--;
	}
	while(t<k){
		while(p[i]==1)
			i++;
		p[i]=1;
		t++;
	}
}
int main(){
	int i;
	generateData();
	c=C+20000005;
	for(i=1;i<=n;i++){
		if(!p[i]){
			p[i]=-1;
		}
		p[n+i]=p[i];
	}
	for(i=1;i<=n*2;i++){
		s[i]=s[i-1]+p[i];
	}
	int now=0;
	for(i=1;i<=n;i++){
		if(p[i]==1){
			c[s[i]]++;
			if(s[i]>0){
				now++;
			}
		}
	}
	for(i=1;i<=n;i++){
		if(p[i]==1){
			now-=c[1];
		}else{
			now+=c[0];
		}
		c+=p[i];
		if(p[i]==1){
			c[0]--;
		}
		if(p[i+n]==1){
			c[s[i+n]-s[i]]++;
			if(s[i+n]-s[i]>0){
				now++;
			}
		}
		if(p[i]==-1){
			if(now==S){
				ans2=i;
			}
			if(now==0){
				ans1=i;
			}
		}
	}
	memset(C,0,sizeof(C));
	now=0;
	c=C+20000005;
	for(i=1;i<=n;i++){
		if(p[i]==-1){
			c[s[i]]++;
			if(s[i]>0){
				now++;
			}
		}
	}
	for(i=1;i<=n;i++){
		if(p[i]==1){
			now-=c[1];
		}else{
			now+=c[0];
		}
		c+=p[i];
		if(p[i]==-1){
			c[0]--;
		}
		if(p[i+n]==-1){
			c[s[i+n]-s[i]]++;
			if(s[i+n]-s[i]>0){
				now++;
			}
		}
		if(p[i]==-1){
			if(k-now-c[0]==S){
				ans3=i;
			}
		}
	}
	printf("%d\n%d\n%d\n",ans1,ans2,ans3);
	return 0;
}

/*
5 3344 2

500000 4545 234567

*/

