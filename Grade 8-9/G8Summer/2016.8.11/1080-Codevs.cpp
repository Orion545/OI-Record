#include<iostream>
#include<cstdio>
using namespace std;
int n,m,data[100001],order[10001][4];
int do1(int a,int b){
	int ans=0;
	for(int i=a;i<=b;i++) ans+=data[i];
	return ans; 
} 
void do2(int a,int b,int x){
	for(int i=a;i<=b;i++){
		data[i]+=x;
	} 
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>data[i];
	cin>>m;
	int ans[10001],tmp=0;
	for(int i=1;i<=m;i++){
		cin>>order[i][0];
		if(order[i][0]==1) cin>>order[i][1]>>order[i][2]>>order[i][3];
		else cin>>order[i][1]>>order[i][2];
	} 
	for(int i=1;i<=m;i++){
		if(order[i][0]==1) do2(order[i][1],order[i][2],order[i][3]);
		else ans[++tmp]=do1(order[i][1],order[i][2]);
	}
	for(int i=1;i<=tmp;i++){
		printf("%d\n",ans[i]);
	}
}
