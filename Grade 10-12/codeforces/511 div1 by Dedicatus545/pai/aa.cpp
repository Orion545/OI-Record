#include <cstdio>
#include <algorithm>
#include <map>
#define Rint register LL
#define LL long long
#define F(x,y,z) for(Rint x=y;x<=z;++x)
#define D(x,y,z) for(Rint x=y;x>=z;--x)
using namespace std;
LL fx[12]={0,1,2,3,2,1};
LL fy[12]={3,2,1,0,-1,-2};
LL Min(LL x,LL y){return x<y?x:y;}
LL Max(LL x,LL y){return x>y?x:y;}
inline LL R(){
    char c='!';LL x=0,z=1;
    for( ; c>'9'||c<'0';c=getchar()) if(c=='-')z=-1;
    for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
    return x*z;
}
LL n,m,ans;
LL  ma[110][110];
map<LL,bool> ss;
bool ck(LL x,LL y){
	if (x<1||x>n) return 0;
	if (y<1||y>m) return 0;
	return ma[x][y]==0;
}
void dfs(LL dep){
	ans=Max(ans,dep);
	LL now=0;
	F(i,1,n)
		F(j,1,m) now=now*4131237+ma[i][j];
	if (ss[now]) return;
	ss[now]=1;
	F(i,1,n)
		F(j,1,m){
			if (ma[i][j]==1) continue;
			ma[i][j]=1;
			F(k,0,5)
				if (ck(i+fx[k],j+fy[k])){
					ma[i+fx[k]][j+fy[k]]=1;
					dfs(dep+1);
					ma[i+fx[k]][j+fy[k]]=0;
				}
			ma[i][j]=0;
		}
}
int main(){
	LL aa=R(),bb=R();
	if (aa*bb<=20){
		n=aa;
		m=bb;
		dfs(0);
		printf("%d\n",ans*2);
		return 0;
	}
	{
		ans=0;
		n=Min(aa,bb);
		m=Max(aa,bb);
		if (n==1){
			ans+=m/6*6;
			m%=6;
			while (m>3)--m,ans+=2;
			printf("%d\n",ans);
			return 0;
		}
		ans=n*m;
		if (ans&1)--ans;
		printf("%I64d",ans);
	}
	return 0;
}
