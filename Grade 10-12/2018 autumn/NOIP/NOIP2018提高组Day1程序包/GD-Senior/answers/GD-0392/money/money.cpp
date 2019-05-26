#include <bits/stdc++.h>

using namespace std;
const int maxn=30005;
const int maxm=3000005;
int T,h,t,pu,ope[maxm],pan[maxn],to[maxm],nextt[maxm],pp[maxn];
int n,p,cnt,a[maxn],ma,dis[maxn],val[maxm];
void spfa()
{	
	h=1;t=1;ope[1]=1;pan[1]=1;
	while (h<=t)
	{
		pu=pp[ope[h]];
	 	while (pu>0)
	 	{
	 		if (dis[to[pu]]>dis[ope[h]]+val[pu])
	 		{
	 			dis[to[pu]]=dis[ope[h]]+val[pu];
	 			if (pan[to[pu]]==0) 
	 			{
	 				t++;ope[t]=to[pu];pan[to[pu]]=1;
	 			}
	 		}
	 		pu=nextt[pu];
	 	}
		pan[ope[h]]=0;
		h++;
		if (dis[ope[t]]<dis[ope[h]]) swap(ope[h],ope[t]);
		if (t>=2000000)
		{
			for (int i=h;i<=t;i++)
			ope[i-h+1]=ope[i];
			t=t-h+1;
			h=1;
		}
	}
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>T;
	for (int o=1;o<=T;o++)
	{
		cin>>n;
		p=0;ma=0;
		for (int i=1;i<=n;i++) 
		{scanf("%d",&a[i]);ma=max(ma,a[i]);}
		sort(a+1,a+1+n);
		for (int i=1;i<=a[1];i++)
		{dis[i]=100000;pp[i]=0;}
		if (a[1]*2>ma)
		{
			cnt=1;
			for (int i=2;i<=n;i++) if (a[i]!=a[i-1]) cnt++;
			cout<<cnt<<endl;
			continue;
		}
		dis[1]=0;
		cnt=1;
		for (int i=2;i<=n;i++)
		{
			if (dis[a[i]%a[1]+1]>a[i]/a[1])
			{
				cnt++;
				for (int j=1;j<=a[1];j++)
				{
					p++;to[p]=(a[i]+(j-1))%a[1]+1;
					nextt[p]=pp[j];pp[j]=p;val[p]=(a[i]+(j-1))/a[1];
				}
				spfa();
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
