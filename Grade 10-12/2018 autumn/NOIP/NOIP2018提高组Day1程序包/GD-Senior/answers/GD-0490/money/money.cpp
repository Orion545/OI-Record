#include<cstdio>
#include<cstring>
#include<algorithm>
#include<fstream>
using namespace std;

#define rep(i,a,b) for(int i=a;i<=b;i++)
typedef long long ll;

ifstream fin("money.in");
ofstream fout("money.out");

const int N=104,M=25010;
int f[M],n,a[N],T,m,ans;

void add(int x){
	rep(i,x,m)f[i]|=f[i-x];
}

int main(){
	for(fin>>T;T--;){
		fin>>n;
		memset(f,0,sizeof f);
		rep(i,1,n)fin>>a[i],m=a[i]>m?a[i]:m;
		sort(a+1,a+n+1);
		
		for(int j=0;j<=m;j+=a[1])
			f[j]=1;
		
		ans=n;
		rep(i,2,n)
			if(f[a[i]])--ans;
			else add(a[i]);
		
		fout<<ans<<"\n";
	}
	
	return 0;
}

