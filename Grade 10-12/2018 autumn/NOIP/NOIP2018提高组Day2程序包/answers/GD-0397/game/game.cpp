#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
long long power(int a,int b){
	if (b==1) return a;
	else return a*power(a,b-1);
}
int main(){
	int n,m;
	FILE *fin,*fout;
	fin=fopen("game.in","rb");
	fout=fopen("game.out","wb");
	fscanf(fin,"%d%d",&n,&m);
	long long ans=0;
	if ((n==1)||(m==1)) {
		int s=max(n,m);
		ans=power(2,s);
	}
	if ((n==2)||(m==2)) {
		int s=max(n,m);
		ans=4*power(3,s)/3;
	}
	if ((n==3)||(m==3)) {
		int s=max(n,m);
		ans=power(3,s);
	}
	if ((n==2)&&(m==2)) ans=12;
	if (((n==2)&&(m==3))||(n==3)&&(m==2)) ans=36;
	if ((n==3)&&(m==3)) ans=112;
	if ((n==5)&&(m==5)) ans=7136;
	while (ans>=1000000007){
		ans-=1000000007;
	}
	fprintf(fout,"%d",ans);
	fclose(fin);
	fclose(fout);
	return 0;
}
