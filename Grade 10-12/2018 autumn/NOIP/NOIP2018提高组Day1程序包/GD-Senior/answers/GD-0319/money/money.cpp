#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
int a[110];
bool c[25001];
int t,n,ex;
void swp(int &a,int &b){
	int c=a; a=b; b=c;
}
void kp(int z,int y){
	int i=z,j=y,n=a[(z+y)/2];
	while (i<=j){
		while (a[i]<n) i++;
		while (a[j]>n) j--;
		if (i<=j) swp(a[i++],a[j--]);
	}
	if (i<y) kp(i,y);
	if (z<j) kp(z,j);
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for (int o=1;o<=t;o++){
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		kp(1,n); ex=0;
		memset(c,0,sizeof(c)); c[0]=1;
		for (int i=1;i<=n;i++){
			if (!c[a[i]]){
				ex++;
				for (int j=0;j<=25000-a[i];j++) if (c[j]) c[j+a[i]]=1;
			}
		}
		printf("%d\n",ex);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
