#include<iostream>
#include<cstring>
using namespace std;
int n,m,b[1001],k[1001];
bool a[10001][10001],used[1001];
void swap(int &aa,int &bb){
	int tt;
	tt=aa;aa=bb;bb=tt;
}
bool find(int x){
	for(int i=1;i<=m;i++){
		if(a[x][i]&&!used[i]){
			used[i]=1;
			if(b[i]!=-1){
				if(b[i]==0||find(b[i])){
					b[i]=x;return true;
				}
			}
		}
	}
	return false;
}
int main(){
	memset(b,-1,sizeof b);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k[i];int ttttt;
		for(int j=1;j<=k[i];j++){
			cin>>ttttt;a[i][ttttt]=1;
		}
	}
	cin>>m;int asdf;
	for(int i=1;i<=m;i++){
		cin>>asdf;b[asdf]=0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		memset(used,0,sizeof used);
		if(find(i)) ans++;
	}
	cout<<ans<<endl;
	int t[1001];
	for(int i=1;i<=m;i++){
		if(b[i]>0){
			t[i]=i;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=i;j++){
			if(b[j]>b[j+1]){
				swap(b[j],b[j+1]);
				swap(t[j],t[j+1]);
			}
		}
	}
	for(int i=1;i<=m+1;i++){
		if(b[i]>0){
			cout<<b[i]<<" "<<t[i]<<endl;
		}
	}
}
