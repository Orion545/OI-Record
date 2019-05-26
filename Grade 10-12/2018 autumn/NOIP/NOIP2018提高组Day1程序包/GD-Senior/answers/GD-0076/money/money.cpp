#include<cstdio>
#include<algorithm>
using namespace std;
int T,a[101],n;
int ok[25001],shu[101],kk[101],maxx;
int read()
{
	int rt=0,f=1;	char ch=getchar();
	while(ch<'0'||ch>'9'){	if(ch=='-')	f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){rt=rt*10+ch-48;ch=getchar();}
	return f*rt;
}
bool cmp(int a,int b){return a<b;}
void chushihua()
{
	for(int i=1;i<=maxx;i++)	ok[i]=0;
	for(int i=1;i<=100;i++){
		shu[i]=0;kk[i]=0;
	}	
	maxx=0;
}
void shuru()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>maxx)	maxx=a[i];
	}	
	sort(a+1,a+n+1,cmp);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		chushihua();
		shuru();
		if(a[1]==1)	{printf("1\n");	continue;}//最小的为1 
		if(n==1){	printf("1\n");	continue;}	
		for(int i=1;i<n;i++)//删倍数 
		{
			if(kk[i]==1)	continue;//a[i]被干了，则倍数一样 
			for(int j=i+1;j<=n;j++){
				if(kk[j]==1)	continue;//等于1表示被删掉,判断比运算快	
				if(a[j]%a[i]==0){
					kk[j]=1;
				}			
			}
		}
		int cnt=0,tag=1;
		for(int i=1;i<=n;i++){
			if(kk[i]==0){
				tag*=a[i];
				cnt++;
				if(cnt==2)	break;
			}
		}
		if(cnt==1){
			printf("1\n");
			continue;
		}	
		cnt=0;
		for(int i=1;i<=n;i++){//大于a*b的不要 
			if(kk[i]==1||a[i]>=tag)continue;
			shu[++cnt]=a[i];
		}//shu是筛选两轮后剩下的
		int ans=0;
		for(int i=1;i<=cnt;i++){
			int now=shu[i];
			if(ok[now]==0)	ans++;
			for(int j=now;j<=maxx;j+=now){	ok[j]=1;}//倍数 
			for(int j=1;j<=maxx;j++){
				if(ok[j]==1&&j+now<=maxx)	ok[j+now]=1;
			}
		}
		printf("%d\n",ans);
	}
	
	
	
}
