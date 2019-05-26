#include<cstdio>

const int INF=0x9fffff;
const int N=100005;
int n,d[N],ans,mind,l,r;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&d[i]);
	while(true){
		for(int i=l;i<=n;i++){
			if(d[i]!=0) break;
			else l++;
		}
		if(l>n) break;
		mind=INF; r=n+1;
		for(int i=l;i<=n;i++){
			if(d[i]==0){
				r=i;
				break;
			}
			if(mind>d[i]) mind=d[i];
		}
		ans+=mind;
		for(int i=l;i<=r;i++){
			d[i]-=mind;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
