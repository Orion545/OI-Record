#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 2010
using namespace std;
int gcd(int a,int b,int &x,int &y){
	if(!b){
		y=0;
		x=1;
		return a;
	}
	int g=gcd(b,a%b,y,x);
	y-=(a/b)*x;
	return g;
}
int n,a[N],tag[N],T;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(tag,0,sizeof(tag));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		if(n==1){
			printf("1\n");
			continue;
		}
		if(n==2){
			if(a[1]%a[2]==0||a[2]%a[1]==0){
				printf("1\n");
			}
			else{
				printf("2\n");
			}
			continue;
		}
		if(n>=3){
			int cnt=n;
			for(int i=1;i<=n;i++){
				if(tag[i])
					continue;
				for(int j=1;j<=n;j++){
					if(tag[j])
						continue;
					if(i!=j&&a[j]%a[i]==0)
						tag[j]=true,cnt--;
				}
			}
			for(int i=1;i<=n;i++){
				if(tag[i])
					continue;
				for(int j=1;j<=n;j++){
					if(tag[j])
						continue;
					int tx,ty,g;
					g=gcd(a[i],a[j],tx,ty);
					while(tx<0){
						tx+=a[j];
						ty-=a[i];
					}
//					printf("XY %d %d\n",x,y);
					for(int k=1;k<=n;k++){
						int x=tx,y=ty;
						if(k==i||k==j||tag[k])
							continue;
						if((a[k]%g))
							continue;
//						if(i==1&&j==5&&k==4){
//							printf("DEBUG :%d %d\n",x,y);
//						}
						x*=a[k]/g;
						y*=a[k]/g;
						while(y<0){
							x-=a[j];
							y+=a[i];
						}
						if(x>=0){
							cnt--,tag[k]=true;
//							printf("De %d %d %d %d %d %d\n",a[i],a[j],a[k],g,x,y);
						}
					}
				}
			}
//			for(int i=1;i<=n;i++)
//				if(!tag[i])
//					printf("%d ",a[i]);
			printf("%d\n",cnt);
			continue;
		}
	}
//	Solve();
	return 0;
}
