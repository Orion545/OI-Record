#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,d[100001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	int i,la=0,ans=0,s;
	d[0]=0;
	s=0;
	for(i=1;i<=n;i++){
		cin>>d[i];
		if(d[i]>d[i-1]) s=d[i]-la;
		else {
			ans+=s;
			s=0;
			la=d[i];
		} 
	}
	ans+=s;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
