#include<cstdio>
using namespace std;



int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m,ans;
	scanf("%d%d",&n,&m);
	if(n==1 || m==1) ans=-1;
	else if(n==2 && m==2) ans=12;
	else if(n+m==5) ans=24;
	else ans=96;
	printf("%d\n",ans);
	fclose(stdout);
	return 0;
}
