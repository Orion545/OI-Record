#include<fstream>
#include<string>
#include<set>
using namespace std;
ifstream cin ("travel.in" ,ios::in );
ofstream cout("travel.out",ios::out);

long long n,been[5001]={0};
set<long long> side[5001];
basic_string<long long> go,least;

void dfs(long long start)
{
	if(start>least[go.length()-1])
		return;
	if(go.length()==n&&go<least)
		least=go;
	if(go.length()==n)
		return;
	
	set<long long>::iterator si;
	
	for(si=side[start].begin();si!=side[start].end();++si)
		if(!been[*si])
		{
			been[*si]=start;
			go+=*si;
			dfs(*si);
			go.resize(go.size()-1);
			been[*si]=0;
		}
	if(start!=1&&been[start]>0)
		dfs(been[start]);
	
	return;
}

int main()
{
	long long m,i,a,b;
	cin>>n>>m;
	go.clear();
	least.clear();
	
	for(i=1;i<=n;++i)
		least+=0x7fffffffffffffff;
	for(i=1;i<=m;++i)
		cin>>a>>b,
		side[a].insert(b),
		side[b].insert(a);
	go=been[1]=1;
	dfs(1);
	
	for(basic_string<long long>::iterator si=least.begin();si!=least.end();++si)
		cout<<*si<<' ';
	
	return 0;
}
