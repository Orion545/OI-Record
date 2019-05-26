#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("road.in");
ofstream fout("road.out");
long long a[200000];
long long n,ans=0;
bool flag=1;
int main (){
	long long i,j,k;
	fin>>n;
	for(i=1;i<=n;i++)
	fin>>a[i];

	
	i=1;
	while(true){
	i=i;
	while(a[i]<=0&&i<=n) i++;
	if(i==n+1) break;
//	cout<<i<<" ";
	j=i;k=a[i];
	while(a[j]>0&&j<=n){
		k=min(a[j],k);
		j++;
	}
//	cout<<j-1<<" "<<k<<endl;
	ans+=k;
	for(int t=i;t<j;t++)
	a[t]-=k;  
}
fout<<ans;
return 0;
}
