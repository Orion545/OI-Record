#include<cstdio>
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,ans=0,p,q=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p);
		if(p>q)ans+=p-q;
		q=p;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
