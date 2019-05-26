#include<bits/stdc++.h>
using namespace std;//70 pts
long long typedef LL;
const int MAXN=1E5+5,inf=1e4+5;
int n;
LL Tree[MAXN];
struct wyy
{
	int num,id;
}St[MAXN];
struct each
{
	int lef,rig,id,num;
	int ori;
}A[MAXN];
LL ans;
void Read()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	
	{
		scanf("%d",&A[i].num);
		A[i].id=i;
		A[i].ori=A[i].num;
	}
	A[n+1].num=0;
}
void CalcSim()
{
	while(1)
	{
		int mina=inf,last=1,ok=0;
		//在n+1处增添哨兵：防止最后一段没有更新。 
		for(int i=1;i<=n+1;i++)
		{
			if(A[i].num==0)
			{
				if(mina!=inf)	
				{
					for(int j=last;j<i;j++)	A[i].num-=mina;	
					ans+=mina;//区间减多少，答案加多少。
					ok=1; 						
				}
				last=i+1;//last永远在0之后。 	
				mina=inf;//遇到0，mina要还原成 inf
			}
			else	mina=min(mina,A[i].num);
		}
		if(ok==0)	break;
	}
	printf("%lld\n",ans);
}
void CalcLefRig()
{
	int tail=0;
	for(int i=1;i<=n;i++)
	{
		while(tail>0&&St[tail].num>=A[i].num)	tail--;
		if(tail==0)	A[i].lef=1;
		else	A[i].lef=St[tail].id+1;
		St[++tail].id=i;St[tail].num=A[i].num;
	}
	tail=0;
	for(int i=n;i>=1;i--)
	{
		while(tail>0&&St[tail].num>=A[i].num)	tail--;
		if(tail==0)	A[i].rig=n;
		else	A[i].rig=St[tail].id-1;
		St[++tail].id=i;St[tail].num=A[i].num;
	}
}
void Debug()
{
	for(int i=1;i<=n;i++)
	{
		printf("%d: %d %d\n",i,A[i].lef,A[i].rig);
	}
}
void Add(int x,LL y)
{
	if(x==0)	return;
	for(;x<=n;x+=x&-x)	Tree[x]+=y;
}
LL Query(int x)
{
	LL nowAns=0;
	for(;x;x-=x&-x)	nowAns+=Tree[x];
	return nowAns;
}
bool cmp(each a,each b)
{
	return a.num<b.num;
}
void Get()
{
	//for(int i=1;i<=n;i++)	Add(i,A[i].num);//树状数组初始化 
	//for(int i=1;i<=n;i++)	printf("%d ",Query(i));
    //没排序之前，就是原本的id. 
	sort(A+1,A+1+n,cmp);
	//Debug
	/*for(int i=1;i<=n;i++)
	{
		printf("%d :%d %d %d %d\n",i,A[i].id,A[i].num,A[i].lef,A[i].rig);
	}*/
	for(int i=1;i<=n;i++)
	{
		//树状数组中，用原始的位置进行维护。 
		int nowId=A[i].id,nowL=A[i].lef,nowR=A[i].rig;
		//LL now=Query(nowId)-Query(nowId-1);//差分思想求nowId位置现在的值。 
		LL now=A[i].ori+Query(nowId);
		if(now!=0)//现在不为0，需要修改。 
		{
			ans+=now;
			Add(nowL,-now);
			Add(nowR+1,now);
			//Add(nowR,-1*LL(now)*nowR);//[L,R]区间加：相当于[1,R]区间加上R*add,[1,L-1]减去(L-1)*add 
			//Add(nowL-1,LL(now)*(nowL-1)); 
		}
	}
}
void CalcDif()
{
	CalcLefRig();
	//Debug();//记得删除 
	Get();
	printf("%lld\n",ans);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	Read();
	//if(n<=1000)	CalcSim();
	//else	
	CalcDif();
	return 0;
}
