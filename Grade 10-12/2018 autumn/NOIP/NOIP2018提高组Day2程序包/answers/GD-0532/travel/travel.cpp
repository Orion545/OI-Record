#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
	int n,m,a[5011],b[5011],lst[5011],blst[5011],num=0,tmp[5011],vct=1,v[5011];
	vector<int> wy[5011];
void p_adin(const int &add)
{
	++num;
	lst[num]=add;
	v[add]=1;
}
void wrk(int add,int fa)
{
//	printf("INIT:%d %d VCT:%d\n",add,fa,vct);
	p_adin(add);
	int flg=1,i,sz=wy[add].size();
		for(i=0;i<sz;++i)
		if((wy[add][i]!=fa)&& (v[wy[add][i]]!=1))
			vct++,wrk(wy[add][i],add),vct--;
}
int cmp(int a,int b)
{
	return a<b;
}
int srt()
{
	int i,j;
	for(i=1;i<=n;++i)
		{
			int sz=wy[i].size();
			for(j=0;j<sz;++j)
				tmp[j]=wy[i][j];
			sort(tmp,tmp+sz,cmp);
			for(j=0;j<sz;++j)
				wy[i][j]=tmp[j];
		}
}
void rsw()
{
	int i;
	for(i=1;i<=n;++i) wy[i].clear();
}
void update()
{
	int flg=0,i;
		for(i=1;i<=n;++i)
			if(lst[i]!=blst[i])
				{
					flg=(lst[i]<blst[i]);
					break;
				}
		if(flg) memcpy(blst,lst,sizeof(lst));
}
int main()
{
	int i,j;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
		if(m==n-1)
			{
				for(i=1;i<n;++i)
					{
						scanf("%d%d",&a[i],&b[i]);
						wy[a[i]].push_back(b[i]);
						wy[b[i]].push_back(a[i]);
					}
					srt();
					wrk(1,0);
					memcpy(blst,lst,sizeof(lst));
			}
		if(m==n)
			{
				for(i=1;i<=n;++i)
					scanf("%d%d",&a[i],&b[i]),blst[i]=99999;
				for(i=1;i<=n;++i)
					{
						memset(v,0,sizeof(v));
		//				printf("RUN %d\n",i);
						num=0;
						rsw();
						for(j=1;j<=n;++j)
							if(i!=j)
								{
									wy[a[j]].push_back(b[j]);
									wy[b[j]].push_back(a[j]);
								}
							int flg=0;
						for(j=1;j<=n;++j)
							if(wy[i].size()==0)
								{
									flg=1;
									break;
								}
							if(flg) continue;
						srt();
						wrk(1,0);
						update();
					}
			}
		for(i=1;i<n;++i)
			printf("%d ",blst[i]);
		printf("%d\n",blst[n]);
	return 0;
}
