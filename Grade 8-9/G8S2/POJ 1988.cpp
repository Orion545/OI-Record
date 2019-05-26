#include<iostream>
#include<cstring>
#include<cstring>
using namespace std;
int pre[30011],cnt[30011],top[30011];
void make_set(){
	for(int i=1;i<=30010;i++){
		pre[i]=i;cnt[i]=1;top[i]=0;
	}
}
int find(int x){
	int t;
	if(x!=pre[x]){
		t=pre[x];
		pre[x]=find(pre[x]);
		top[x]+=top[t];
	}
	return pre[x];
}
void join(int x,int y){
	int nx=find(x),ny=find(y);
	if(nx!=ny){
		pre[ny]=nx;
		top[ny]=top[nx];
		cnt[nx]+=cnt[ny];
	}
	return;
}
int n;
int main(){
	std::ios::sync_with_stdio(false);
	cin>>n;
	make_set();
	char x;int b,c;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x=='M'){
			cin>>b>>c;
			join(b,c);
		}
		if(x=='C'){
			cin>>b;
			cout<<cnt[find(b)]-top[b]-1<<endl;
		}
	}
} 
