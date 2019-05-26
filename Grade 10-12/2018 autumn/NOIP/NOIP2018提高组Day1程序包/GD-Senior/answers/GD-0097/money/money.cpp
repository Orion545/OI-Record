#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int T,a,v[1001],ue[1001],fir,sec;
int gcd(int s,int t)
{
	if(s%t==0) return t;
	else return gcd(t,s%t);
}
int find(int x,int y,int z)
{
	int q=gcd(x,y);
	if(z%x==0||z%y==0||z%(x+y)==0) return 1;
	if(z%q!=0) return 0;
	int mx=min(100,z/x);
	int my=min(100,z/y);
	for(int hh=1;hh<=mx;hh++)
	{
		for(int kk=1;kk<=my;kk++)
		if(hh*x+kk*y==z) return 1;
	}
	return 0;
}
int main()
{
	cin>>T;
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	while(T>0)
	{
		T--;
		cin>>a;
		for(int i=1;i<=a;i++) cin>>v[i];
		for(int i=1;i<=a;i++) ue[i]=1;
		sort(v+1,v+1+a);fir=v[1];
//		for(int i=1;i<=a;i++) cout<<v[i]<<endl;
		int gg=2;
		while(v[gg]%fir==0&&gg<a) 
		{
			gg++;ue[gg]=0;
		}
		if(gg==a)
		{
			if(v[gg]%fir==0) cout<<"1"<<endl;
			if(v[gg]%fir!=0) cout<<"2"<<endl;
		}
		else
		{	
			sec=v[gg];int st=gg+1;
			for(int i=st;i<=a;i++)
			{
				if(find(sec,fir,v[i])==1) ue[i]=0;
				for(int k=st;k<=i-1;k++)
				{
					if(ue[k]==0) continue;
					if(find(v[k],fir,v[i])==1)ue[i]=0;
					if(find(v[k],sec,v[i])==1)ue[i]=0;
				}
			}
		int ans=0;
		for(int i=1;i<=a;i++)if(ue[i]) ans++;
		cout<<ans<<endl;			
		}
	}
	return 0;
}
