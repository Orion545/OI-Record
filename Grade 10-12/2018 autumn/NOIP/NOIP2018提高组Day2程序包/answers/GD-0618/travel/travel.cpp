#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
using namespace std;
int n,m,cnt=0;
int a[10010],link[10010],head[5010];
void addlink(int x,int y){
	cnt++;
	a[cnt]=y;
	link[cnt]=head[x];
	head[x]=cnt;
}
void dfs1(int now,int father){
	cout<<now<<" ";
	int s[1000],sum=0;
	memset(s,0,sizeof(s));
	for(int l=head[now];l!=-1;l=link[l])
		if(a[l]!=father) s[++sum]=a[l];
	if(sum==0) return ;
	if(sum==1){
		dfs1(s[sum],now);
		return ;
	}
	sort(s+1,s+sum+1);
	for(int i=1;i<=sum;i++)
		dfs1(s[i],now);
	return ;
}
/*bool findQQ(int now,int father){
	if(tag[now]==1){
		qut[++sau]=now;
		return 1;
	}
	else tag[now]=1;
	for(int l=head[now];l!=-1;l=link[l])
		if(a[l]!=father)
			if(findQQ(a[l],now)){
				qut[++sau]=now;
				return 1;
			}
	return 0;
}
void dfs2(int now,int father,string s){
	cout<<now;
	string sk;
	stringstream ss;
	if(s.length()==n) cout<<s<<endl;
	else{
		for(int l=head[now];l!=-1;l++){
			if(a[l]!=father){
				ss.clear();
				ss<<now;
				ss>>sk;
				sk=s+sk;
				dfs2(a[l],now,sk);
			} 
		}
	}
	return ;
}*/
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	memset(head,-1,sizeof(head));
	memset(link,-1,sizeof(link));
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;
		addlink(x,y);
		addlink(y,x);
	}
	if(m+1==n) dfs1(1,0);
	return 0;
}
