#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,a[5001][5001],b[5001],ans=1,c[5001],v[5001];
int phh(int q,int j){
	v[q]=1;
	if(c[q]!=1){
	int s=0;
	for(int i=2;i<=n;i++){
	if(a[q][i]==1&&v[i]!=1){
		ans++;
		j++;
		b[ans]=i;
		a[q][i]=0;
		a[i][q]=0;
		phh(i,j);	
		}
	s++;	
	}
	if(s==n){
	c[q]=1;
	j--;
	phh(b[j],j);
	}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		a[x][y]=1;
		a[y][x]=1;
	}
	int j=1;
	b[1]=1;
	phh(1,j);
	for(int i=1;i<=ans;i++)
	cout<<b[i]<<" ";
	return 0;
}
