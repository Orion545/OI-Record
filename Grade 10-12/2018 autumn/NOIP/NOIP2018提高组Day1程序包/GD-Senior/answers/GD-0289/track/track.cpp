#include<iostream>
#include<cstdio>
#include<climits>
#include<algorithm>
#include<queue>
using namespace std;

const int maxnode=50001;
short fencha[maxnode];
bool erchashu,lian,juhua,tanxin;

int arr_juhua[maxnode*2];
long long totval,ans;
int totnode,needway;

struct info
{
	int nxt,to,val;
}edge[maxnode*2+2];
int head[maxnode],cnt;

void add(int x,int y,int v)
{
	++cnt;
	edge[cnt].nxt=head[x];
	edge[cnt].to=y;
	edge[cnt].val=v;
	head[x]=cnt;
}

bool judge(long long minn)
{
	int now=1,co=0,pp=0;
	while(now<totnode)
	{
		for(int i=head[now];i;i=edge[i].nxt)
		{
			if(edge[i].to==now-1) continue;
			else
			{
				pp+=edge[i].val;
				now=edge[i].to;
				break;
			}
		}
		if(pp>=minn)
		{
			++co;
			if(co>=needway)
			{
				return true;
			}
			pp=0;
		}
	}
	return false;
	
}
void sp_lian()
{
	long long l=1,r=totval;
	while(l<=r)
	{
		if(judge((l+r)>>1))
		{
			ans=(l+r)>>1;
			l=((l+r)>>1)+1;
		}
		else
		{
			r=l=((l+r)>>1)-1;
		}
	}
}

void sp_juhua()
{
	int tmp;
	priority_queue<int,vector<int> ,greater<int> > team;
	while(team.empty()==false) team.pop();
	sort(arr_juhua+1,arr_juhua+1+totnode);
	if(totnode-1<needway*2)
	{
		for(int i=2;i<=needway+1;++i)
		{
			team.push(arr_juhua[i]);
		}
		for(int i=totnode;i>needway+1;--i)
		{
			tmp=team.top()+arr_juhua[i];
			team.pop();
			team.push(tmp);
		}
		ans=team.top();
	}
	else
	{
		int cnt=0;
		for(int i=totnode;i>=totnode-needway+1;--i)
		{
			team.push(arr_juhua[i]);
		}
		for(int i=totnode-needway;i>=2;--i)
		{
			tmp=team.top()+arr_juhua[i];
			team.pop();
			team.push(tmp);
			++cnt;
			if(cnt>=needway) break;
		}
		ans=team.top();
	}
}

long long tanxindfs(int now,int fat)
{
	long long back=0,tmp;
	for(int i=head[now];i;i=edge[i].nxt)
	{
		if(edge[i].to==fat) continue;
		tmp=tanxindfs(edge[i].to,now)+edge[i].val;
		if(back<tmp) back=tmp;
	}
	return back;
}
void sp_tanxin()
{
	long long tmp,max1=0,max2=0;
	for(int i=head[1];i;i=edge[i].nxt)
	{
		tmp=tanxindfs(edge[i].to,1)+edge[i].val;
		if(max1<tmp)
		{
			max2=max1;max1=tmp;
		}
	}
	ans=max1+max2;
}

void sp_erchashu()
{
	
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	erchashu=lian=juhua=tanxin=true;
	scanf("%d%d",&totnode,&needway);
	if(needway!=1) tanxin=false;
	
	int x,y,v;
	for(int i=1;i<=totnode-1;++i)
	{
		scanf("%d%d%d",&x,&y,&v);
		totval+=v;
		if(juhua)
		{
			if(x!=1&&y!=1) juhua=false;
			arr_juhua[max(x,y)]=v;
		}
		if(erchashu)
		{
			fencha[x]++;fencha[y]++;
			if(fencha[x]>3||fencha[y]>3) erchashu=false;
		}
		if(lian&&x-y!=1&&y-x!=1) lian=false;
		add(x,y,v);add(y,x,v);
	}
	
	if(lian)
	{
		sp_lian();
	}
	else
	{
		if(tanxin)
		{
			sp_tanxin();
		}
		else
		{
			if(juhua)
			{
				sp_juhua();
			}
			else
			{
				//cout<<"erebus"<<endl;
				sp_erchashu();
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
/*from:lj*/
//////start
// orz dwjshift
// orz superguymj
// orz lhy
// orz dqa

// dwjshift orz
// superguymj orz
// lhy orz
//////end
// dqa orz
