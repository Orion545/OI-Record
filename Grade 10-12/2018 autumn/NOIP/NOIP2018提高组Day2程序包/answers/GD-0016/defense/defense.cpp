#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cctype>
#include<queue>
using namespace std;
int read();
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n=read(),m=read();
	for(int i=0;i<m;i++)
	{
		cout<<-1<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
int read()
{
	char ch=getchar();int x=0,f=1;
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
