#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=101;
int a[maxn],n,ans=0;
bool pan[25001]={};
void add(int k)
{
	if(pan[k])
	 {
	 	ans++;
	 	return;
	 }
	pan[k]=1;
	int avb=k;
	for(int i=1;i<=a[n];i++)
	 if(pan[i])
	  {
	  	avb=k+i;
		while(avb<=a[n])
		 {
		 	pan[avb]=1;
		 	avb+=k;
		 }
	  }
	  return;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	cin>>t;
	while(t>0)
	{
		t--;
		memset(pan,0,sizeof(pan));
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		 cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		 add(a[i]);
		cout<<n-ans<<endl;
	}
	return 0;
} 
