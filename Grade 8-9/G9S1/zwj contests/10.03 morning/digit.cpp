#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int p[5]={0,2,3,5,7};
int n,k,lim[5];
int maxx(int l,int r){return (l>r)?l:r;};
int check(int x){
	if(x==0) return 1;
	for(int i=1;i<=4;i++){
		while(x%p[i]==0) x/=p[i],lim[i]++;
	}
	return x;
}
inline void put(int x){
	char s[100];int cnt=0;
	if(x==0) putchar('0');
	else{
		while(x){
			s[++cnt]=(char)(x%10+48);
			x/=10;
		}
	}
	while(cnt) putchar(s[cnt--]);
}
struct bigint{
	int a[20];
	bigint(){
		memset(a,0,sizeof(a));
	}
	bigint(int x){
		memset(a,0,sizeof(a));
		a[0]=1;a[1]=x;
	}
	inline void out(){
		for(int i=a[0];i>=1;i--){
			if(i==a[0]||a[i]>=1000) put(a[i]);
			else{
				if(a[i]<1000&&a[i]>=100) putchar('0'),put(a[i]);
				if(a[i]<100&&a[i]>=10) putchar('0'),putchar('0'),put(a[i]);
				if(a[i]>10&&a[i]<=1) putchar('0'),putchar('0'),putchar('0'),put(a[i]);
				if(a[i]==0) putchar('0'),putchar('0'),putchar('0'),putchar('0');
			}
		} 
		return ;
	}
	inline void operator =(const bigint &b){
		a[0]=b.a[0];
		for(int i=1;i<=a[0];i++) a[i]=b.a[i];
	}
	inline bigint operator +(const bigint &b){
		bigint re;int tmp;
		for(int i=1;i<=maxx(a[0],b.a[0]);i++){
			tmp=a[i]+b.a[i];
			re.a[i]+=tmp%10000;re.a[i+1]+=tmp/10000;
		}
		re.a[0]=20;
		while(!re.a[re.a[0]-1]) re.a[0]--;
		re.a[0]--;
		return re;
	}
	inline bigint operator -(const bigint &b){
		bigint re;int tmp;
		for(int i=1;i<=a[0];i++){
			tmp=a[i]-b.a[i];
			if(tmp<0) tmp+=10000,a[i+1]-=1;
			re.a[i]=tmp;
		}
		re.a[0]=20;
		while(!re.a[re.a[0]-1]) re.a[0]--;
		re.a[0]--;
//		cout<<"minus:";re.out();cout<<endl;
		return re;
	}
	inline void operator +=(const bigint &b){*this=(*this)+b;}
	inline bigint operator *(const int &b){
		bigint re;int tmp;
		for(int i=1;i<=a[0];i++){
				tmp=a[i]*b;
//				cout<<"	"<<i<<ends<<tmp<<endl;
				re.a[i]+=tmp%10000;
				re.a[i+1]+=tmp/10000;
		}
		re.a[0]=20;
		while(!re.a[re.a[0]-1]) re.a[0]--;
		re.a[0]--;
		return re;
	}
	inline void operator *=(int &b){*this=(*this)*b;}
};
bigint dp[40][30][20][20];
int main(){
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	int i,x,y,z,l;
	scanf("%d%d",&n,&k);
	if(k==0){
		bigint x(9),y(10),ans;
		for(i=1;i<n;i++){
//			x.out();cout<<endl;y.out();cout<<endl;
			x=x*9;y=y*10;
		}
//		cout<<"**"<<endl;
//		x.out();cout<<endl;y.out();cout<<endl;
//		cout<<"***"<<endl;
		ans=y-x;
		ans.out();
		return 0;
	}
	if(check(k)!=1){
		printf("0");return 0;
	}
	dp[0][0][0][0].a[0]=1;dp[0][0][0][0].a[1]=1;
	for(i=1;i<=n;i++){
		for(x=lim[1];x>=0;x--){
			for(y=lim[2];y>=0;y--){
				for(z=lim[3];z>=0;z--){
					for(l=lim[4];l>=0;l--){
						if(x>=1) dp[x][y][z][l]+=dp[x-1][y][z][l];
						if(x>=2) dp[x][y][z][l]+=dp[x-2][y][z][l];
						if(x>=3) dp[x][y][z][l]+=dp[x-3][y][z][l];
						if(y>=1) dp[x][y][z][l]+=dp[x][y-1][z][l];
						if(y>=2) dp[x][y][z][l]+=dp[x][y-2][z][l];
						if(x>=1&&y>=1) dp[x][y][z][l]+=dp[x-1][y-1][z][l];
						if(z>=1) dp[x][y][z][l]+=dp[x][y][z-1][l];
						if(l>=1) dp[x][y][z][l]+=dp[x][y][z][l-1];
					}
				}
			}
		}
	}
	dp[lim[1]][lim[2]][lim[3]][lim[4]].out();
}
