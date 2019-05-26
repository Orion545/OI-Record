#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
long a[20000],q[3000000],T,n,b[20000];
long  kp(long x,long y){
	long i=x,j=y,z=a[(x+y)/2];
	while(i<=j){
		while(a[i]<z)i++;
		while(a[j]>z)j--;
		if(i<=j){
			long t=a[i];a[i]=a[j];a[j]=t;
			i++;j--;
		}
	}
	if(i<y)kp(i,y);
	if(j>x)kp(x,j);
}
long gcd(long a,long b){
	if(a%b!=0)gcd(b,a%b);
	else return b;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%ld",&T);
	for(int i=1;i<=T;i++){
		scanf("%ld",&n);
		memset(q,0,sizeof(q));
		long t=0;
		for(int j=1;j<=n;j++){
			scanf("%ld",&a[j]);
			long p=0;
			for(int k=1;k<=t;k++){
				if(gcd(b[k],a[j])!=1||b[k]==1){
					b[k]=min(a[j],b[k]);p=1;break;
				}
			}
			if(p==0){
				t++;b[t]=a[j];
			}
		}
		if(t==1){
			printf("1\n");continue;
		}
		long ans=2500000;
		for(int j=1;j<=t;j++){
			for(int k=j+1;k<=t;k++){
				ans=min(ans,b[j]*b[k]-b[j]-b[k]);
			}
		}
		kp(1,n);
		long res=0;
		for(int j=1;j<=n;j++){
			if(a[j]>ans)break;
			else {
				if(q[a[j]]==0){
					res++;
					q[a[j]]=1;
					for(int k=1;k<=ans-a[j];k++)
						if(q[k]==1){
							q[k+a[j]]=1;	
						}
				}
			}
		}
		printf("%ld\n",res);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
