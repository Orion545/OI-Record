#include<cstdio>
#include<cstring>
using namespace std;
int a[10001],n;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int t,loc,cnt,ans;
	t=0; ans=0;
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		t=t+a[i];
	}
	while(t>0){
		loc=1; while(a[loc]==0) loc++;
		cnt=1; while(a[loc+cnt]!=0) cnt++;
		//printf("a[%d] => a[%d] \n",loc,loc+cnt-1);
		for(int i=loc;i<=loc+cnt-1;i++) a[i]--;
		t=t-cnt; ans++;
	}
	printf("%d\n",ans);
	fclose(stdout);
	return 0;
}
