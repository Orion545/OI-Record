#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int T,n;
long long s[200];
int ans;
bool dp[200][30000];

int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}

int exgcd(int a,int b,int &x,int &y){
	int d=a;
	if(b!=0){
		d=exgcd(b,a%b,y,x);
		y-=a/b*x;
	}
	else{
		x=1; y=0;
	}
	return d;
}

bool f(int a,int b,int c){
	int x,y,d;
	d=exgcd(a,b,x,y);
	x*=c; y*=c;
	if(x>b) return y+(x/b*a)>=0;
	if(y>a) return x+(y/a*b)>=0;
}

bool check(int a,int b,int c){
	int d=gcd(a,b);
	if(c%d!=0) return false;
	if(d==1) return f(a,b,c);
	else return check(a/d,b/d,c/d);
}

void solve(){
	if(n==1) return;
	if(s[1]==1){
		n=1;
		return;
	}
	bool g=0;
	for(int p=n;p>1;p--){
		bool t=0;
		for(int i=1;i<p;i++){
			if(s[p]%s[i]==0){
				t=1; break;
			}
		}
		if(t==0&&p>2){
			for(int i=1;i<p&&t==0;i++){
				for(int j=i+1;j<p&&t==0;j++){
					if(s[j]%s[i]!=0){
						if(gcd(s[i],s[j])==1&&s[p]>(s[i]*s[j]-s[i]-s[j])) t=1;
					    else if(check(s[i],s[j],s[p])) t=1;
					}
				}
			}
		}
		if(t){
			g=1;
		    n--;
			for(int i=p;i<=n;i++) s[i]=s[i+1];
		}
	}
	if(g) solve();
	else{
		ans=n;
		dp[0][0]=1;
		for(int i=1;i<n;i++){
			for(int j=0;j<s[i];j++)     dp[i][j]=dp[i-1][j];
			for(int j=s[i];j<=s[n];j++) dp[i][j]=dp[i-1][j]||dp[i][j-s[i]];
		}
		for(int i=1;i<n;i++) if(dp[i][s[i+1]]) ans--;
		n=ans;
	}
	return;
}

int main(){
	freopen ("money.in","r",stdin);
	freopen ("money.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>s[i];
		sort(s+1,s+1+n);
		solve();
		cout<<n<<endl;
	}
	return 0;
}
