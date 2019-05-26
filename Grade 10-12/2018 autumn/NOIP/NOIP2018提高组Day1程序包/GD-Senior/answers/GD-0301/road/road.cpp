#include<bits/stdc++.h>
using namespace std;
const int maxn=100010,inf=99999999;
int a[maxn],ans=0;
void gui(int l,int r,int jian){
	if(l>r)return ;
	int minx=inf,num;
	vector<int>v;
	for(int i=l;i<=r;++i)minx=min(minx,a[i]);
	ans+=minx-jian;
	jian+=minx-jian;
	for(int i=l;i<=r;++i)if(a[i]==minx)v.push_back(i);
	for(int i=0;i<v.size();++i){
		if(i==0)gui(l,v[i]-1,jian);
		else gui(v[i-1]+1,v[i]-1,jian);
	}
	gui(v[v.size()-1]+1,r,jian);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	gui(1,n,0);
	cout<<ans;
	return 0;
}
