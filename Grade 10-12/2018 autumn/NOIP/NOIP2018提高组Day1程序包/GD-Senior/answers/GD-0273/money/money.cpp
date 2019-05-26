#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#define mem(a) memset(a,0,sizeof(a))
const int N=105;
using namespace std;
int read(){
	int ans=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-48;c=getchar();}
	return ans*f;
}
int a[N],b[N],t,mx;
int fl,tt,pp;
void pre(){
	fl=0,tt=0;
	for(int i=1;b[3]-b[1]*i>=b[2];i++){
		int x=b[3]-b[1]*i;
		if(x%b[2]==0){fl=1;break;}
	}
	if(fl){
		for(int i=1;b[4]-b[1]*i>=b[2];i++){
			int x=b[4]-b[1]*i;
			if(x%b[2]==0){tt=1;break;}
		}	
	}
	else{
		int no=0;
		for(int i=0;tt==0,i*b[1]<=b[4];i++){
			no=i*b[1];
			for(int j=0;tt==0,j*b[2]+no<=b[4];j++){
				int now=no+j*b[2];
				if((b[4]-now)%b[3]==0)tt=1;
			}
		}
	}
}
void solve(){
	pre();
	if(fl&&tt){
		for(int i=1;b[5]-b[1]*i>=b[2];i++){
			int x=b[5]-b[1]*i;
			if(x%b[2]==0){pp=1;break;}
		}
	}
	else if(fl){
		int no=0;
		for(int i=0;pp==0,i*b[1]<=b[5];i++){
			no=i*b[1];
			for(int j=0;pp==0,j*b[2]+no<=b[5];j++){
				int now=no+j*b[2];
				if((b[5]-now)%b[4]==0)pp=1;
			}
		}
	}
	else if(tt){
		int no=0;
		for(int i=0;pp==0,i*b[1]<=b[5];i++){
			no=i*b[1];
			for(int j=0;pp==0,j*b[2]+no<=b[5];j++){
				int now=no+j*b[2];
				if((b[5]-now)%b[3]==0)pp=1;
			}
		}
	}
	else{
		int no=0;
		for(int i=0;pp==0,i*b[1]<=b[5];i++){
			no=i*b[1];
			for(int j=0;pp==0,j*b[2]+no<=b[5];j++){
				int now=no+j*b[2];
				for(int z=0;pp==0,z*b[3]+now<=b[5];z++){
					int nn=now+z*b[3];
					if((b[5]-nn)%b[4]==0)pp=1;
				}
			}
		}
	}
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T=read();
	while(T--){
		int n=read();t=0;
		for(int i=1;i<=n;i++)a[i]=read();
		if(n==1){printf("1\n");continue;}
		sort(a+1,a+1+n);
		b[++t]=a[1];fl=0;tt=0;pp=0;
		for(int i=2;i<=n;i++){
			int oo=0;
			for(int j=1;j<i;j++)
				if(a[i]%a[j]==0){oo=1;break;}
			if(!oo)b[++t]=a[i];
		}
		if(t<=2){
			printf("%d\n",t);
			continue;
		}
		mx=b[1]*b[2];
		while(t&&b[t]>=mx)t--;
		if(t==3){
			for(int i=1;b[3]-b[1]*i>=b[2];i++){
				int x=b[3]-b[1]*i;
				if(x%b[2]==0){fl=1;break;}
			}
			if(fl)printf("2\n");
			else printf("3\n");
			continue;
		}
		if(t==4){
			pre();
			printf("%d\n",t-fl-tt);
			continue;
		}
		if(t==5){
			solve();
			printf("%d\n",t-fl-tt-pp);
			continue;
		}
		printf("%d\n",t);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
