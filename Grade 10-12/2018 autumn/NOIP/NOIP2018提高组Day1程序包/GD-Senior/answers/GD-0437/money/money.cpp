#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
int n;

int b[101];
bool bfs(int n, int need)
{
	int head=0 ,tail=1;
	int trail[100000];
	trail[1]=0;
	do
	{
		head++;
		for(int i=1;i<=n;i++)
		{
			if(trail[head]+b[i]<=need)
			{
				tail++;
				trail[tail]=trail[head]+b[i];
				if(trail[tail]==need) return false;
			}
		}
	}
	while (head<tail);
	return true;
}
bool pd(int ans, int num){
	if (ans==1)
		return num%b[1]==0? false : true;
	else{
		return bfs(ans, num);
	}
}
void doit(){
	int temp;
	int ans=1;
	int min;
	priority_queue <int, vector<int> ,greater<int> > a;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>temp;
		a.push(temp);
	}
	min=a.top();
	if (a.top()==1){printf("1"); return;}
	a.pop();
	b[1]=min;
	while(!a.empty())
	{
		if(pd(ans, a.top())){
			ans++;
			b[ans]=a.top();
		}
		a.pop();
	}
	cout<<ans<<endl;
}

int main()
{
	int T;
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	cin>>T;
	while(T--) doit();
	return 0;
}
