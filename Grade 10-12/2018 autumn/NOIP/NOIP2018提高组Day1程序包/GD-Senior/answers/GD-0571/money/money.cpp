#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct dhasjfhs
{
	int now;
	int L;
	int sum;
}q[510000];
int T,n,a[550],now,bin[50],s,t,b[500000][10],L[1000000];
bool bj[500000],flag,flag2;
int gcd(int a,int b)
{
	if(b==0) return a;
	gcd(b,a%b);
}
void chec(int now,int L,int en)
{
	if(L+1>en) return;
	if(now==0) 
	{
		flag2=true;
		return;
	}
	if(now<a[L]) return;
	if(bj[L])
	{
		chec(now-a[L],L,en);
		if(flag2) return;
	}
	chec(now,L+1,en);
	if(flag2) return;
}
bool mo(int a,int b)
{
	if(a>b) 
	{
		if(a%b==0) return true; else return false;
	}
	else 
	if(b%a==0) 
	{
		return true; 
	}
	else return false;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	bin[1]=1;
	for(int i=2; i<=30; i++) bin[i]=bin[i-1]*2;
	while(T--)
	{
		scanf("%d",&n);
		if(n<=25)
		{
			for(int i=1; i<=n; i++) scanf("%d",&a[i]);
			int ppp=n;
			for(int i=1; i<=ppp-1; i++)
			for(int j=i+1; j<=ppp; j++)
			{
				if((mo(a[i],a[j])) && a[i]!=21474836 && a[j]!=21474836)
				{
					if(a[i]<=a[j]) a[j]=21474836,n--;
					else a[i]=21474836,n--;
				}
			}
			sort(a+1,a+ppp+1);
			s=0;
			t=1;
			q[1].L=0;
			q[1].now=0;
			q[1].sum=0;
			while(s<=t)
			{
				s++;
				flag=false;
				if(q[s].L==n)
				if(q[s].sum!=0)
				{
					flag=true;
					for(int i=1; i<=n; i++)
					if((q[s].now/bin[i])&1) bj[i]=true; else bj[i]=false;
					for(int i=1; i<=n; i++)
					if(!bj[i])
					{
						flag2=false;
						chec(a[i],1,i);
						if(!flag2) 
						{
							flag=false; break;
						}
					}
				}
				if(flag)
				{
					cout<<q[s].sum<<endl;
					break;
				}
				t++;
				q[t].L=q[s].L+1;
				q[t].sum=q[s].sum;
				q[t].now=q[s].now;
				t++;
				q[t].L=q[s].L+1;
				q[t].sum=q[s].sum+1;
				q[t].now=q[s].now+bin[q[t].L];
			}
			memset(bj,false,sizeof(bj));
		}
		else
		{
			for(int i=1; i<=n; i++) scanf("%d",&a[i]);
			int ppp=n;
			for(int i=1; i<=ppp-1; i++)
			for(int j=i+1; j<=ppp; j++)
			{
				if((mo(a[i],a[j])) && a[i]!=21474836 && a[j]!=21474836)
				{
					if(a[i]<=a[j]) a[j]=21474836,n--;
					else a[i]=21474836,n--;
				}
			}
			printf("%d\n",n);
		}
	}
}
