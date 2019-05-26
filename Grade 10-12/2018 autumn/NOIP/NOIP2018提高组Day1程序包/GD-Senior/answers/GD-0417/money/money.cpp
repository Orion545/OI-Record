#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t, n, i,temp1,temp2;
	cin >> t;
	while(t--){
		cin >> n;
		if(n == 2){
			cin >> temp1;
			cin >> temp2;
			if(temp1>=temp2)
				if((temp1%temp2)==0)
					cout << "1";
				else cout << "2";
			if(temp1<temp2)
				if((temp2%temp1)==0)
					cout << "1";
				else cout << "2";
			continue;
		}
		for(i=1;i<=n;i++)
			cin >>temp1;
		n--;
		cout << n << endl;
	}
	return 0;
}
