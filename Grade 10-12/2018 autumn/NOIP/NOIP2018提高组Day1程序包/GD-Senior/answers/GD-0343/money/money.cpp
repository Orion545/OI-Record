#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int num[100];
int op[25001];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T,n,i,ans,j,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",num+i);
		sort(num,num+n);
		memset(op,-1,sizeof(op));
		ans=0;
		for(i=0;i<n;i++)
			if(op[num[i]]==-1){
				ans++;
				op[num[i]]=i;
				for(j=0;j<=num[n-1];j++)
					if(op[j]>=0&&op[j]<=i)
						for(k=num[i];j+k<=num[n-1];k+=num[i])
							op[j+k]=i+1;
			}
		printf("%d\n",ans);
	}
	return 0;
}
