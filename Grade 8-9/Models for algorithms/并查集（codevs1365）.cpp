#include<iostream>
#include<vector>
using namespace std;
int x,n,m;
int pre[20001];
int find(int x){
	int r=x;
	while(r!=pre[r]) r=pre[r];
	int i=x,j;
	while(i!=r){
		j=pre[i];
		pre[i]=r;
		i=j;
	}
	return r;
}
void same(int x,int y){
	if(find(x)==find(y)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
int main(){
	for(int i=0;i<=20000;i++) pre[i]=i;
	cin>>x>>n>>m;
	int xx,yy;
	for(int i=1;i<=n;i++){
		cin>>xx>>yy;
		pre[xx]=yy;
	}
	for(int i=1;i<=m;i++){
		cin>>xx>>yy;same(xx,yy);
	}
} 
