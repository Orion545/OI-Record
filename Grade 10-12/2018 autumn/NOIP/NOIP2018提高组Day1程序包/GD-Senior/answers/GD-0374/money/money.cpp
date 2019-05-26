#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=105;
int a[N],m,f[N],p,t,n,tmp,i,j,k,l;

void pd()
{
	for(j=i-1;j>=1;j--){
		if(f[j]==1) continue;
		for(k=0;k<=a[i]/a[j];k++){
			tmp=a[i]-a[j]*k;
			for(l=1;l<=j;l++){
				if(f[l]==1) continue;
				if(tmp%a[l]==0){
					f[i]=1;
					m--;
					return ;
				}
			}
		}
	}
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		m=n;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		if(n==2){
			if(a[1]%a[2]==0||a[2]%a[1]==0) printf("%d\n",n-1);
			else printf("%d\n",n);
		}
		else if(n==3){
			m=n;
			sort(a+1,a+1+n);
			if(a[2]%a[1]==0){
				m--;
				f[2]=1;
			}
			if(f[2]==1){
				if(a[3]%a[1]==0) m--;
			}
			else {
				for(int j=0;j<=a[3]/a[1];j++){
					if((a[3]-a[1]*j)%a[2]==0){
						m--;
						break;
					}
				}
			}
			printf("%d\n",m);
		}
		else if(n==4){
			m=n;
			sort(a+1,a+1+n);
			if(a[2]%a[1]==0){
				m--;
				f[2]=1;
			}
			if(f[2]==1){
				if(f[3]%f[1]==0){
					f[3]=1;
					m--;
					if(f[4]%f[1]==0){
						m--;
						f[4]=1;
					} 
				}
			}
			else {
				for(int j=0;j<=a[3]/a[1];j++){
					if((a[3]-a[1]*j)%a[2]==0){
						m--;
						for(int k=0;k<=a[4]/a[1];k++){
							if((a[4]-a[1]*j)%a[2]==0){
								m--;
								break;
							}
						}
						break;
					}
				}
				if(m==4){
					for(int j=0;j<=a[4]/a[1];j++){
						for(int l=0;l<=a[4]/a[2];l++){
							if((a[4]-a[1]*j-a[2]*l)%a[2]==0){
								m--;
								break;
							}
						}
						if(m==3) break;
					}
				}
			}
			printf("%d\n",m);
		}
		else {
			pd();
			printf("%d\n",m);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
