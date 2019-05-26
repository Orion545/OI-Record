#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define N 10000
using namespace std;
int t,n,mmax=0;
int a[N],bj[26000];
queue<int>q;
void bfs()
{
	while(q.empty()==false)
	{
		int x=q.front();q.pop();
		if(x>=mmax)continue;
		for(int i=1;i<=n;i++)
		{
			//if(x+a[i]==13||x+a[i]==11||x+a[i]==17||x+a[i]==19||x+a[i]==29)cout<<"ac"<<endl;
			//cout<<x<<" "<<a[i]<<" "<<a[i]+x<<" "<<bj[a[i]+x]<<endl;
			if(bj[a[i]+x]==1||x+a[i]>mmax)continue;
			bj[a[i]+x]=1;q.push(a[i]+x);
		}
	}
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
    	scanf("%d",&n);
    	mmax=0;
    	int num=0;
    	for(int i=1;i<=n;i++)
    	{
    		scanf("%d",&a[i]);
    		mmax=max(mmax,a[i]);//cout<<"mmax="<<mmax<<endl;
    		q.push(a[i]);
    	}
    	for(int i=1;i<=mmax;i++)bj[i]=0;
    	bfs();
    	for(int i=1;i<=n;i++)
    	{
    		if(bj[a[i]]==0){
    			num++;//cout<<a[i]<<" "<<bj[a[i]]<<endl;
    		}
    	}	
    	printf("%d\n",num);
    }
	return 0;
}
