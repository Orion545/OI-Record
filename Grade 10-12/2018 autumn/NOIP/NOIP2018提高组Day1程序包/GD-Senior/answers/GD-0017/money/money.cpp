#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int T,n,a[120],ans,end;
int bj[25100];
void sort(int l,int r){
	int i,j,mid,p;
	i=l; j=r; mid=a[(i+j)/2];
	while (i<=j){
		while (a[i]<mid) i++;
		while (mid<a[j]) j--;
		if (i<=j){
			p=a[i]; a[i]=a[j]; a[j]=p;
			i++; j--;
	    }
    }
    if (i<r) sort(i,r);
    if (l<j) sort(l,j);
    return;
}
int main()
{
	freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
	scanf("%d",&T);
	for (int i=1;i<=25000;i++) bj[i]=0;
	for (int k=1;k<=T;k++){
		scanf("%d",&n);
		ans=n;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(1,n);
		bj[0]=k;
		for (int i=1;i<=n;i++){
			if (bj[a[i]]==k){ans--; continue;}
			end=a[n]-a[i];
			for (int j=0;j<=end;j++)
		    	if (bj[j]==k) bj[j+a[i]]=k;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
    fclose(stdout);
	return 0;
}
