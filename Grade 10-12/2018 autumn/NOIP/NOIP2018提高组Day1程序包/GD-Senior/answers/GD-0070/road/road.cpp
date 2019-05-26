#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int a[100005],n,count,top=0,bot=0;
	cin>>n;
	count=0;
	for(int i=1;i<=n;i++){cin>>a[i];}
	for(int i=1;i<=n;i++){
		if (a[i]>a[i-1])top=a[i];
		if (a[i+1]<a[i]){count=count+top;top=0;}
		}
	for(int i=1;i<=n;i++){
		if (a[i]<a[i-1])bot=a[i];
		if (a[i]>a[i-1]){count=count-bot;bot=0;}
		}	
	cout<<count;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
