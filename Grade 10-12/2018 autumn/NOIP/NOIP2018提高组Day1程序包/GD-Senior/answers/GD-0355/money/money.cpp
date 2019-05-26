#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxv = 25002;
const int maxn = 102;
int n, T;
int a[maxn];
bool bucket[maxv];
vector<int> rcrd;

void solve() {
	cin >>n;
	int maxi = -1;
	for (int i=1; i<=n; i++) {
		cin >>a[i];
		//maxi = max(maxi, a[i]);
	}
	vector<int>().swap(rcrd);
	rcrd.push_back(0);
	
	sort(a+1, a+n+1);
	maxi = a[n];
	//for (int i=1; i<=n; i++) cout <<a[i]<<" ";
	//cout <<endl;/////////
	
	memset(bucket, 0, sizeof(bucket));
	
	
	
	int needed = n;
	int lpos = 0;
	for (int i=1; i<=n; i++) if (!bucket[a[i]]){
		int curmoney = a[i];
		int mems = 0;
		while (curmoney<=maxi) {
			bucket[curmoney] = true;
			rcrd.push_back(curmoney);
			mems++;
			curmoney +=a[i];
		}
		
		//cout <<"when i = "<<i<<" a[i]=" <<a[i] <<":"<<endl;
		//for (int i=0; i<rcrd.size(); i++) cout <<rcrd[i]<<" ";
		//cout <<endl;///////
		
		//if (i==-1) //////
		//printf("#lL:%d, lR:%d#\n", 1, lpos-1);
		//printf("#L:%d, R:%d#\n", lpos, lpos+mems);
		/*if (i!=1)*/ for (int j=lpos; j<=lpos+mems; j++) {
			int pos = 1;
			curmoney = 0;
			while (pos<=lpos-1) {
				curmoney = rcrd[j] + rcrd[pos];
				if (curmoney <= maxi){
					bucket[curmoney] = true;
					rcrd.push_back(curmoney);	
				}
				pos++;
			}
		}
		
		//cout <<"when i = "<<i<<" a[i]=" <<a[i] <<":"<<endl;
		//for (int i=0; i<rcrd.size(); i++) cout <<rcrd[i]<<" ";
		//cout <<endl;///////

		lpos = rcrd.size();
	} else {
		needed--;
	}
	cout<<needed<<endl;
	
	return;
};

int main () {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	
	cin >>T;
	for (int i=1; i<=T; i++) solve();
	
	return 0;
}
