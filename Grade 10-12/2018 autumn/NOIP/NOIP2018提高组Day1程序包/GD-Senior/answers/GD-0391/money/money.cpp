#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> q;
int n,a[101],tot;

bool dfs(int x,int p){//cout<<x<<" "<<p<<endl;
	if(x%q[p]==0)return 1;
	else if(p>=q.size()-1)return 0;
	else{
		for(int i=x/q[p];i>=0;i--){
			bool op=dfs(x-i*q[p],p+1);
			if(op)return 1;
		}
	}
	return 0;
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int x;bool op;
	int T;
	scanf("%d",&T);
	while(T--){
	//	cout<<T<<endl;
	tot=0;
	q.clear();
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);op=0;
		for(int j=1;j<=tot;j++){
			if(x<a[j]){
				if(a[j]%x==0){
					a[j]=x;op=1;break;
				}
			}
			if(x>=a[j]){
				if(x%a[j]==0){
					op=1;break;
				}
			}
		}
		if(!op)a[++tot]=x;
	}
	if(tot==1||tot==2){
		cout<<tot<<'\n';
		continue;
	}
	sort(a+1,a+1+tot);
	//for(int i=1;i<=tot;i++)cout<<a[i]<<" ";
	int tmax=a[1]*a[2]-a[1]-a[2];
	q.push_back(a[1]);q.push_back(a[2]);
	for(int i=3;a[i]<tmax&&i<=tot;i++){
		if(!dfs(a[i],0))q.push_back(a[i]);
	}
	cout<<q.size()<<'\n';
	}
}
