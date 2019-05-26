#include<iostream>
#include<cstdio>
using namespace std;

int t,a[105],b[105],m,n;
bool vis[105],ch;

inline int read()
{
	char ch=getchar(); 
	while (ch>'9'||ch<'0') ch=getchar();
	int res=ch-48;
	ch=getchar();
	while (ch<='9'&&ch>='0')
	{
		res=res*10+ch-48; ch=getchar();
	}
	return res;
}

void DFS_(int num,int x)
{
	if (num==0) 
	{
		ch=true; return;
	}
	for (int i=x; i>=1; i--)	
		if (!ch&&num-b[i]>=0)
			DFS_(num-b[i],x);
}

bool check(int x)
{
	for (int i=1; i<=n; i++)
		if (!vis[i])
		{
			ch=false;
			DFS_(a[i],x);
			if (!ch) return false;
		}	
	return true;
}
void DFS(int x)
{
	if (x>m) return;
	if (m>x&&x!=0&&check(x)) 
	{
		m=x; return;
	}
	
	for (int i=1; i<=n; i++)
		if (!vis[i])
		{
			vis[i]=true;
			b[x+1]=a[i];
			DFS(x+1);
			vis[i]=false;
		}
}

void quicksort(int l,int r)
{
	int i,j,mid,t;
	i=l; j=r; mid=a[(i+j)/2];
	while (i<=j)
	{
		while (a[i]<mid) i++;
		while (a[j]>mid) j--;
		if (i<=j)
		{
			t=a[i]; a[i]=a[j]; a[j]=t;
			i++; j--;
		}
	}
	if (i<r) quicksort(i,r);
	if (l<j) quicksort(l,j);
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	t=read();
	while (t--)
	{
		n=read();
		for (int i=1; i<=n; i++)	
		{
			a[i]=read(); vis[i]=false;
		}
		quicksort(1,n);
		for (int i=1; i<=n; i++)
		{
			if (a[i]!=0)
				for (int j=i+1; j<=n; j++)
					if (a[j]%a[i]==0)
					{
						n--; 
						for (int k=j; j<=n; j++)
							a[k]=a[k+1];
					}
		}	
		
		m=n;
		DFS(0);
		printf("%d\n",m);
	}
	
	fclose(stdin);fclose(stdout);
	return 0;
}
