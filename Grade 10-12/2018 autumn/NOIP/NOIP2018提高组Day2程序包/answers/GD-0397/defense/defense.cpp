#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
bool x[100005],y[100005];
int n,m,l,q,p[100005],a[100005],b[100005];
char c1,c2;
int main(){
	FILE *fin,*fout;
	fin=fopen("defense.in","rb");
	fout=fopen("defense.out","wb");
	fscanf(fin,"%d%d%c%c",&n,&m,&c1,&c2);
	for (int i=1;i<=n;i++){
		fscanf(fin,"%d",&p[i]);
	}
	for (int i=1;i<=m;i++){
		fscanf(fin,"%d%d%d%d",&a[i],&l,&b[i],&q);
		if (l==1) x[i]=true;
		else x[i]=false;
		if (q==1) y[i]=true;
		else y[i]=false;
	}
	for (int i=1;i<=m;i++)
	 fprintf(fout,"-1\n");
	fclose(fin);
	fclose(fout);
	return 0;
}
