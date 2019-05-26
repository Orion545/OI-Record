#include<bits/stdc++.h>
using namespace std;

long long re=0;
int n;
int d[100001];

void solve(int l,int r){
	if (l>r) return;
	int mmin=999999999;
	vector<int> v;
	for (int i=l;i<=r;i++){
		mmin=min(mmin,d[i]);
	}
	re+=mmin;
	for (int i=l;i<=r;i++){
		d[i]-=mmin;
		if (!d[i]) v.push_back(i);
	}
	int last=l;
	for (int i=0;i<v.size();i++){
		solve(last,v[i]-1);
		last=v[i]+1;
	}
	solve(last,r);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&d[i]);

	solve(1,n);
	printf("%lld",re);
	return 0;
}
