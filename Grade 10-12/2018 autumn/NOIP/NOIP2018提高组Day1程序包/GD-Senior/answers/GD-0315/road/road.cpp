#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n,a[100007],mi,weizhi2,weizhi1;
long long ans,tot;

void shanchu(){
	for(int i=weizhi1;i<=weizhi2;i++){
		a[i]-=mi;
		if(a[i]==0)	tot++;
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	a[i]=0;
	for(int i=1;i<=n;i++)	scanf("%d",&a[i]);
	ans=0,tot=0;
	mi=100007,weizhi1=1,weizhi2=n;
	for(int i=1;i<=n;i++)
		 mi=min(a[i],mi);
	shanchu(),ans+=mi;
	while(tot!=n){
		mi=100007,weizhi1=0,weizhi2=0;
		int i=1;
		while(a[i]==0)	i++;
		weizhi1=i;
		for(i=weizhi1;i<=n+1;i++){
			if (a[i]==0){
				weizhi2=i-1,shanchu(),ans+=mi;
				break;
			}	
			else mi=min(a[i],mi);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
