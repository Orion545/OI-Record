#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;
int n,m,a[50005],b[50005],t[50005],l[50005];
int main(){
    FILE *fin,*fout;
    memset(t,0,sizeof(t));
	fin=fopen("money.in","rb");
	fout=fopen("money.out","wb");
	fscanf(fin,"%d",&n,m);
	for (int i=1;i<n;i++){
	    fscanf(fin,"%d%d%d",&a[i],&b[i],&l[i]);
	    t[a[i]]++;;
	    t[b[i]]++;
	}
	int ans=10005;
	for (int i=1;i<n;i++)
	 ans=min(ans,l[i]);
	fprintf(fout,"%d",ans);
	fclose(fin);
	fclose(fout);
	return 0; 
}
