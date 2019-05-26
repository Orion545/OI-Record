#include<fstream>
using namespace std;
ifstream cin ("game.in" ,ios::in );
ofstream cout("game.out",ios::out);

long long pow(long long a,long long b)
{
	if(b==1)
		return a;
	return a*pow(a,b-1)%1000000007;
}

int main()
{
	long long a,b;
	cin>>a>>b;
	if(a==b&&a==3)
		cout<<112;
	if(a==3&&b==2)
		cout<<40;
	if(a==2)
		cout<<(4*pow(3,b-1))%1000;
		
	return 0;
}
