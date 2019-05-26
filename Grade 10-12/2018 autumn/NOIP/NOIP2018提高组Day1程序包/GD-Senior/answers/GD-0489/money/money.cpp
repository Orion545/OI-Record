#include<iostream>
using namespace std;
#include<cstdio>
#include<cstring>
#include<fstream>
#include<algorithm>

int t,n,ans,start;
long long a[105],b[105];

void _clear() {
	n=0;
	ans=1;
	memset(a,0,(sizeof a));
	memset(b,0,(sizeof b));
}

bool cmp(long long x,long long y) {
	return x<y;
}

bool dfs(int s,long long rest) {
	if(s==1) {
		if(rest%b[1]==0) return true;
		else return false;
	}
	else {
		for(int i=0;i<=rest/b[s];i++) {
			if(dfs(s-1,rest-b[s]*i)) return true;
		}
	}
	return false;
}

int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	while(t--) {
		_clear();
		cin>>n;
		start=n+1;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1,cmp);
		b[1]=a[1];
		for(int i=2;i<=n;i++) {
			if(a[i]%a[1]!=0) {
				ans++;
				b[ans]=a[i];
				start=i+1;
				break;
			}
		}
		long long maxn=b[1]*b[2]-b[1]-b[2];
		for(int i=start;i<=n;i++) {
			if(a[i]>maxn) break;
			if(!dfs(ans,a[i])) {
				ans++;
				b[ans]=a[i];
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
