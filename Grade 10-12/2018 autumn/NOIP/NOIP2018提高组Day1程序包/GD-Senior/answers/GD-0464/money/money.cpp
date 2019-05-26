#include<bits/stdc++.h>
using namespace std;
int n,t,a[110],b[110],tot,ans,x,y;
bool f;
long long p;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		if(a[1]==1){
			printf("1\n");
		}else if(n==1){
			printf("1\n");
		}else if(n==2){
			if(a[2]%a[1]!=0) printf("2\n"); else printf("1\n");
		}else if(n>=3&&n<=5){
			tot=0; ans=0;
			for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++){
				if(a[j]!=0&&a[i]!=0&&a[j]%a[i]==0){
					a[j]=0;
					ans++;
				}
			}
			for(int i=1;i<=n;i++) if(a[i]!=0) b[++tot]=a[i];
			if(n==3&&ans>=2){
				printf("1\n");
			} else if(n==3&&ans==1){
				printf("2\n");
			} else if(n==3&&ans==0){
				x=2; y=2; f=false;
				if(b[1]+b[2]==b[3]) f=true; else{
					while((x*b[1]+y*b[2])<=b[3]){
						if(x*b[1]+y*b[2]==b[3]) f=true;
						if((y+1)*b[2]<(x+1)*b[1]+y*b[2]){
							x=1;
							y++;
						}else x++;
					}
				}
				if(f==true) printf("2\n"); else printf("3\n");
			}else{
				for(int i=1;i<=n;i++) if(a[i]!=0) b[++tot]=a[i];
				p=b[1]*b[2]-b[1]-b[2];
				for(int i=1;i<=tot;i++) if(b[i]>p) ans++;
				printf("%d\n",n-ans);
			}
		}else{
			tot=0; ans=0;
			memset(b,0,sizeof(0));
			for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++){
				if(a[j]!=0&&a[i]!=0&&a[j]%a[i]==0){
					a[j]=0;
					ans++;
				}
			}
			for(int i=1;i<=n;i++) if(a[i]!=0) b[++tot]=a[i];
			p=b[1]*b[2]-b[1]-b[2];
			for(int i=1;i<=tot;i++) if(b[i]>p) ans++;
			printf("%d\n",n-ans);
		}
	}
	return 0;
}
