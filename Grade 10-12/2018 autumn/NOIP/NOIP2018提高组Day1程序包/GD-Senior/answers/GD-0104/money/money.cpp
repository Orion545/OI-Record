#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 105;
const int L = 25005;

int n;
int a[N];
bool can[L];

void solve(){
	n=get();
	fo(i,1,n)a[i]=get();
	sort(a+1,a+1+n);
	fo(i,0,25000)can[i]=0;
	can[0]=1;
	int ans=0;
	fo(i,1,n)
	if (!can[a[i]]){
		ans++;
		fo(j,a[i],L)can[j]|=can[j-a[i]];
	}
	cout<<ans<<endl;
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	for(int T=get();T;T--)solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
