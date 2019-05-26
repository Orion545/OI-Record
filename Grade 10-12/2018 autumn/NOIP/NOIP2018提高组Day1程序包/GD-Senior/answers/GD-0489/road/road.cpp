#include<iostream>
using namespace std;
#include<cstdio>
#include<cstring>
#include<fstream>

int n,d[100010];
long long ans;

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>d[i];
		if(d[i]>d[i-1]) ans+=(d[i]-d[i-1]);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
