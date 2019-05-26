#include<iostream>
#include<cstdio>
using namespace std;
void money(){
	int a[1000],b[1000],c[50005],d,e,m,n,count;
	cin>>m;
	count=0;
	c[0]=1;
	for(int i=1;i<=20000;i++){c[i]=0;}
	for(int i=1;i<=m;i++){cin>>a[i];}
	for(int i=m;i>=1;i--){for (int j=1;j<i;j++){if(a[j]>a[j+1])swap(a[j],a[j+1]);}}
	//for(int i=1;i<=m;i++){cout<<a[i];}
	for(int i=1;i<=m;i++){
		if (c[a[i]]==0) {count=count+1;for (int j=0;j<=25000;j++){if (c[j]==1)c[j+a[i]]=1;}}
	}
	cout<<count<<endl;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout); 
int t;
cin>>t;
for(int i=1;i<=t;i++)money();
fclose(stdin);fclose(stdout);
return 0;
}
