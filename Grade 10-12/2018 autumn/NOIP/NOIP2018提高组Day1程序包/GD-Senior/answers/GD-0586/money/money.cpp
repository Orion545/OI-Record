#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;

namespace mine
{
	const int MAX_N=110;
	int a[MAX_N];
	const int MAX_NUM=31000;
	bool f[MAX_NUM];
	void main()
	{
		freopen("money.in","r",stdin);
		freopen("money.out","w",stdout);
		
		int T;scanf("%d",&T);
		while(T--)
		{
			int n;scanf("%d",&n);
			for(int i=1;i<=n;i++) scanf("%d",&a[i]);
			sort(a+1,a+n+1);
			
			memset(f,0,sizeof f);
			f[0]=1;
			int tot=0;
			for(int i=1;i<=n;i++)
			{
				int now=a[i];
				if(f[now]==0)
				{
					tot++;
					for(int s=now;s<MAX_NUM;s++) f[s]|=f[s-now];
				}
			}
			printf("%d\n",tot);
		}
	}
}
/*
��Ϊ�Ǹ������ӷ�����С������
��̬ά���ñ���
�����ǰ�ܱ���ǰ��ֱ�ӱ�ʾ����Ȼû��
������Ȼ��ǰ��������±���ʾ����
�ø�С����û���ֵ�����ȥȡ����ǰ�������ᵼ�¶���Ǹ���������Ҳ���� 

ֻ��� ֵ�� �ڽ��б������ɣ���С 
*/
int main()
{
	srand(time(0));
	mine::main();
}
