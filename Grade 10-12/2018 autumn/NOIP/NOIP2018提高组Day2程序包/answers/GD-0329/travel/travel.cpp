#include <bits/stdc++.h>
#include <vector>
#include <queue>

using namespace std;

struct node{
	int vis;
	int visby;
	int deep;
};
queue <int> sx;
node city[5005];
vector <int>road[5005];
queue <int> q;

int n=0;
int m=0;

int stacky[500005];
int top = 0;

void walk(int inow){
	//while (!sx.empty())sx.pop();
	//sx.push(1);
	//int inow = 1;
	//sx.push (inow);
	city[inow].vis = 1;
	printf ("%d ", inow);
	for (int i = 0; i < road[inow].size(); i++){
		int nxt = road[inow][i];
		if (city[nxt].deep > city[inow].deep && city[nxt].vis == 0){
			stacky[top] = nxt;
			top++;
		}
	}

	if (top == 0)return;
	
	int iofmax = top-1;
	int minval = stacky[top-1];
	int maxdeep = city[stacky[top-1]].deep;
	for (int i = top-1; i >= 0; i--){
		if (city[stacky[i]].deep < maxdeep)break;
		if (stacky[i] < minval){
			minval = stacky[i];
			iofmax = i;
		}
	}

	int nt = stacky[iofmax];

	for (int i = iofmax; i <= top-2; i++){
		stacky[i] = stacky[i+1];
	}

	top--;

	walk(nt);
}

void setdeep(){
	while (!q.empty()){
		int inow = q.front();
		for (int i = 0; i < road[inow].size(); i++){
			int nxt = road[inow][i];
			if (m == n-1){
				if (city[nxt].deep != -1)continue;
				city[nxt].deep = city[inow].deep+1;
				q.push (nxt);
			}else{
				if (city[nxt].deep != -1 && city[inow].visby != nxt){
					if (city[nxt].deep > city[inow].deep){
						q.push (nxt);
						city[nxt].deep = inow;
					}else if (city[nxt].deep < city[inow].deep){
						q.push (inow);
						city[inow].deep = city[nxt].deep;
					}
				}else if (city[nxt].deep == -1){
					city[nxt].deep = city[inow].deep+1;
					q.push (nxt);
				}
			}
		}
		q.pop();
	}
}

int main (){
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < m; i++){
		int a=0,b=0;
		scanf ("%d %d", &a, &b);
		road[a].push_back(b);
		road[b].push_back(a);
		city[a].vis = 0;
		city[b].vis = 0;
		city[a].visby = -1;
		city[b].visby = -1;
		city[a].deep = -1;
		city[b].deep = -1;
	}
	city[1].deep = 1;
	while (!q.empty())q.pop();
	q.push (1);
	setdeep();
	walk (1);
	fclose (stdin);
	fclose (stdout);
	return 0;
}
