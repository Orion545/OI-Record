#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,sum_l=0,ans=1000000000;
bool p1,p2;
struct edge1{
	int a,b,l;
}e[50008];
bool cmp1(edge1 a,edge1 b){
	return a.l<b.l;
}
bool cmp2(edge1 a,edge1 b){
	return a.a<b.a;
}
bool judge(int x_min){
	int tot_j=0,x_c=0;
	for(int i=1;i<=n-1;i++){
		x_c+=e[i].l;
		if(x_c>=x_min){
			x_c=0;
			tot_j++;
		}
	}
	if(tot_j>=m){
		return true;
	}
	return false;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	p1=true;
	p2=true;
	for(int i=1;i<=n-1;i++){
		cin>>e[i].a>>e[i].b>>e[i].l;
		sum_l+=e[i].l;
		if(e[i].a!=1)p1=false;
		if(e[i].b-e[i].a!=1)p2=false;
	}
	if(p1){
		sort(e+1,e+n-1+1,cmp1);
		if(m*2<=n-1){
			for(int j=n-2*m;j<=n-m-1;j++){
				ans=min(ans,e[j].l+e[2*(n-m-1)+1-j].l);
			}
		}else{
			ans=e[2*(n-m-1)+1].l;
			for(int j=1;j<=n-m-1;j++){
				ans=min(ans,e[j].l+e[2*(n-m-1)+1-j].l);
			}
		}
	}
	if(p2){
		sort(e+1,e+n-1+1,cmp2);
		int l=1,r=sum_l,mid;
		while(l<r){
			mid=(l+r+1)/2;
			if(judge(mid)){
				l=mid;
			}else{
				r=mid-1;
			}
		}
		ans=l;
	}
	cout<<ans;
	return 0;
}
