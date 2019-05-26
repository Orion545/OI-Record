#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;
bool p[25005],count;
int T,n=0,ans=0,m,maxn=0,k,a[105],b[105];
void qsort(){
	int l=1;
	memset(p,false,sizeof(p));
	for (int i=1;i<=n;i++)
	 p[a[i]]=true;
	for (int i=1;i<=maxn;i++)
	 if (p[i]) {
	 	a[l]=i;
	 	l++;
	 }
	 return;
}
void cut(int x){
	int l=x;
	for (int i=l;i<n;i++)
	 a[i]=a[i+1];
	n--;
	return;
}
bool isvital(int x,int k){
	int l=x,q=k;
	for (int i=1;i<q;i++)
	 if (l%a[i]==0) return false;
	return true;
}
bool test(int c){
	for (int i=1;i<k;i++)
	 if (!isvital(c,k)) return true;
	return false; 
}
void work(int l){
	if (count) return;
	if (l<=0) return;
	if (test(l)) {
		cut(k);
		count=true;
	}
    else for (int c=1;c<k;c++)
          work(l-a[c]);
    return;      
}
int main(){
	FILE *fin,*fout;
	fin=fopen("money.in","rb");
	fout=fopen("money.out","wb");
	fscanf(fin,"%d",&T);
	int t=0;
	while (t<T){
		t++;
		maxn=0;
		fscanf(fin,"%d",&n);
		for (int j=1;j<=n;j++){
		 fscanf(fin,"%d",&a[j]);
		 maxn=max(maxn,a[j]);
	    }
		for (int i=1;i<=n;i++)
		 if (a[i]==1) n=1;
		if (n!=1){
			qsort();
			for (int i=1;i<=n-1;i++)
			 for (int j=i+1;j<=n;j++)
			  if (a[j]%a[i]==0) cut(j);
			for (int i=3;i<=n;i++){
			 	count=false;
				m=a[i];
			 	k=i;
			 	work(m);
			 }
		}
		fprintf(fout,"%d\n",n);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
