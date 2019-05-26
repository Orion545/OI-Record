#include <cmath>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
//Constant
const int N=100;
const int A=25000;
//Quick Read
int Read(){
	int x=0;
	bool neg=false;
	char c=getchar();
	while(isdigit(c)==false)neg^=c=='-',c=getchar();
	while(isdigit(c)==true)x=x*10+c-'0',c=getchar();
	return x;
}
void Read(int &x){x=Read();}
//Main
int a[N+1];
bool fake[A+1];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int times=Read();
	while(times--){
		int n=Read(),max=0;
		for(int i=1;i<=n;++i)Read(a[i]),max=std::max(max,a[i]);
		std::sort(a+1,a+1+n);
		memset(fake,false,sizeof fake),fake[0]=true;
		int ans=n,rest=max;
		for(int i=1;i<=n;++i){
			int val=a[i];
			if(fake[val]==true){
				--ans;
				continue;
			}
			if(rest==0)continue;
			for(int j=val;j<=max;++j)
				if(fake[j]==false&&fake[j-val]==true)fake[j]=true,--rest;
		}
		printf("%d\n",ans);
	}
	return 0;
}
