#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,m;char ss[1100];
int hf[1100000];
int dp[110000][2];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);scanf("%s",ss+1);
	for (int i=1;i<=n;i++)scanf("%d",&hf[i]);
	for (int i=1;i<=n-1;i++){
		int x,y;scanf("%d%d",&x,&y);
	}
	for (int i=1;i<=m;i++){
		int a,x,b,y;scanf("%d%d%d%d",&a,&x,&b,&y);
		memset(dp,63,sizeof(dp));
		dp[0][1]=0;
		for (int j=1;j<=n;j++){
			dp[j][0]=dp[j-1][1];
			dp[j][1]=min(dp[j-1][0],dp[j-1][1])+hf[j];
			if (j==a){dp[j][1-x]=999999999;}
			if (j==b){dp[j][1-y]=999999999;}
		}
		if (min(dp[n][1],dp[n][0])>=999999999)printf("-1\n");
		else printf("%d\n",min(dp[n][1],dp[n][0]));
	}
	return 0;
}
/*
��1 �а�������������??, ??��һ���ַ���????????���ֱ��ʾ��������Ҫ������������
�͡�????????��һ���ɴ�д��ĸA��B ��C ��һ������1��2��3 ��ɵ��ַ����������԰���
���ò��ַ֡�����ܲ���Ҫ�õ������������������ĺ����ڡ����ݹ�ģ��Լ������
�о����������
��2��n������pi����ʾ���i�ĳ�����פ�����ӵĻ��ѡ�
������n ? 1�У�ÿ������������u, v����ʾ��һ��u��v��˫���·��
������m�У���j���ĸ�����a, x, b, y(a �� b)����ʾ��j��Ҫ�����ڳ���aפ��x֧���ӣ�
�ڳ���bפ��y֧���ӡ����У�x �� y ��ȡֵֻ��0 ��1����x Ϊ0����ʾ����a ����פ
�����ӣ���x Ϊ1����ʾ����a ����פ�����ӣ���y Ϊ0����ʾ����b ����פ�����ӣ�
��y Ϊ1����ʾ����b ����פ�����ӡ�
�����ļ���ÿһ�����ڵ���������֮�����һ���ո�ָ���
*/
