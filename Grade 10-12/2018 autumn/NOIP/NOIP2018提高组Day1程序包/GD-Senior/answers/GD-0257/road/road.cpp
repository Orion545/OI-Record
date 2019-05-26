#include<stdio.h>
#include<vector>
using namespace std;
typedef long long ll;
int a[100010],st[100010],L[100010],R[100010],tp;
vector<int>v[10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,i,j;
	ll s;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		v[a[i]].push_back(i);
	}
	for(i=1;i<=n;i++){
		while(tp&&a[i]<=a[st[tp]])tp--;
		L[i]=st[tp];
		st[++tp]=i;
	}
	tp=0;
	for(i=n;i>0;i--){
		while(tp&&a[i]<=a[st[tp]])tp--;
		R[i]=st[tp];
		st[++tp]=i;
	}
	s=0;
	for(i=1;i<=10000;i++){
		if(!v[i].empty()){
			for(j=0;j<(int)v[i].size();j++){
				if(j<(int)v[i].size()-1&&R[v[i][j]]-1>=v[i][j+1])continue;
				s+=i-max(a[L[v[i][j]]],a[R[v[i][j]]]);
			}
		}
	}
	printf("%lld",s);
}
