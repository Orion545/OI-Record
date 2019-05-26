#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;
const int maxn=100005;
int a[maxn];
int main(){
	int n,j,k,ans=0;
	FILE *fin,*fout;
	fin=fopen("road2.in","rb");
	fout=fopen("road2.out","wb");
	fscanf(fin,"%d",&n);
	for (int i=1;i<=n;i++)
	 fscanf(fin,"%d",&a[i]);
	for (int i=1;i<=n;i++)
	 while (a[i]!=0){
	    	j=i;
	    	while (a[j]!=0) j++;
	    	j--;
	    	for (k=i;k<=j;k++)
	    	 a[k]-=1;
	    	ans++; 
	 }
	 fprintf(fout,"%d",ans);
	 fclose(fin);
	 fclose(fout);
	 return 0; 
}
