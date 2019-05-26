#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
void subTask(){
	int n,a[109],v[25041],mmax=0;
	int flag=0,f2=0,f3=0;
	memset(v,0,sizeof(v));
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>mmax)mmax=a[i];
		if(a[i]==1)flag=1;
		if(a[i]==2)f2=1;
		if(a[i]==3)f3=1;
	}
	if(flag)printf("1\n");
	else if(f2&&f3)printf("2\n");
	else{
		int tmp=a[1];
		while(tmp<=mmax){
			v[tmp]++;
			tmp+=a[1];
		}
		v[0]=1;
		for(int i=2;i<=n;i++){
			for(int j=mmax;j>=0;j--){
				if(v[j]){
					tmp=j+a[i];
					while(tmp<=mmax){
						v[tmp]++;
						tmp+=a[i];
					}
				}
			}
		}
		for(int i=n;i>=1;i--){
			for(int j=mmax;j>=0;j--){
				if(v[j]){
					tmp=j+a[i];
					while(tmp<=mmax){
						v[tmp]++;
						tmp+=a[i];
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(v[a[i]]<=2)ans++;
		}
		//for(int i=1;i<=mmax;i++)if(!v[i])printf("%d ",i);
		printf("%d\n",ans);
	}
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)subTask();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
