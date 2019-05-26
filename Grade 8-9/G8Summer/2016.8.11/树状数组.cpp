#include<iostream>
using namespace std;
int n,m,a[1000001],s[1000001],sum[1000001];
void find(int x,int internal){
	if(x==0) return;
	sum[internal]+=s[x];
	find(x-(x&-x),internal);
}
void add(int x,int y){
	if(x>n) return;
	s[x]+=y;
	add(x+(x&-x),y);
}
int main(){
	cin>>n;int y;
	for(int i=1;i<=n;i++){
		cin>>y;a[i]+=y;
		add(i,y);
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<" "<<s[i]<<endl;
	cin>>m;find(m,m);
	cout<<sum[m];
}
