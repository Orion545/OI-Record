#include<fstream>
#include<algorithm>
using namespace std;
ifstream cin ("money.in" ,ios::in );
ofstream cout("money.out",ios::out);

int main()
{
	long long *a,n,i,j,maxn,answer,big_for,T,start;
	bool *flag;
	cin>>T;
	
  for(big_for=1;big_for<=T;++big_for)
  {
  	maxn=-1;
  	answer=0;
  	
	cin>>n;
	a=new long long[n+1];
	for(i=1;i<=n;++i)
		cin>>a[i],
		maxn=max(maxn,a[i]);
	flag=new bool[maxn+1];
	for(i=1;i<=maxn;++i)
		flag[i]=false;
	sort(a+1,a+n+1);//from small to large
	
	start=a[1];
	for(i=1;i<=n;++i)
		if(!flag[a[i]])
		{
			flag[a[i]]=true;
			if(a[i]>start)
				start=a[i]+1;
			while(flag[start]==true)
				++start;
			for(j=start;j<=maxn;++j)
				if(flag[j-a[i]]==true)
					flag[j]=true;
			++answer;
		}
	
	cout<<answer<<'\n';
	delete []a;
	delete []flag;
  }
	
	cin.close(),cout.close();
	return 0;
}
