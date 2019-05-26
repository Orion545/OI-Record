#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,f[110],t,a,b,c;
bool h[110];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if (n==2){
			scanf("%d %d",&a,&b);
			if (a>b) swap(a,b);
			if (b%a==0) printf("1\n");
			else printf("2\n");
		}
		else if (n==3){
			for (int i=1;i<=n;i++) scanf("%d",&f[i]);
			sort(f+1,f+1+n); int ans=3;
			if (f[2]%f[1]==0){
				ans--; h[2]=false;
			} 
			if (f[3]%f[2]==0&&f[2]%f[1]!=0){
				ans--; f[3]=false;
			} 
			if (f[3]%f[1]==0){
				ans--; f[3]=false;
			} 
			if (ans==1||ans==2) printf("%d\n",ans);
			else{
				bool k=false;
				int cnt=f[3]/f[1];
				while(cnt){
					if ((f[3]-f[1]*cnt)%f[2]==0) k=true;
					cnt--;
				}
				if (k) printf("2\n");
				else printf("3\n");
			}
		}
		else if (n==4){
			for (int i=1;i<=n;i++){
				scanf("%d",&f[i]);
			}
			for (int i=2;i<=4;i++){
				for (int j=1;j<i;j++) if (f[i]%f[j]==0) h[i]=true;
			}
			int cnt=0;
			for (int i=1;i<=4;i++) if (h[i]==false) cnt++;
			if (cnt==1||cnt==2) printf("%d\n",cnt);
		}
	}
	return 0;
}
