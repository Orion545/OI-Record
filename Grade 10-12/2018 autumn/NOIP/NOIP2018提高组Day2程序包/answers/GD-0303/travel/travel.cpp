#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main ()
{
	ifstream fin ("travel.in");
	ofstream fout ("travel.ans", ios::trunc);
	
	int m = 0;
	int n = 0;
	fin >> n >> m;
	
	vector< vector<int> > connectedWith;
	for (int i = 0; i <= n; i++) {
		vector<int> empty;
		connectedWith.push_back(empty);
	}
	
	for (int i = 0; i < n; i++) {
		int u = 0; 
		int v = 0;
		fin >> u >> v;
		
		connectedWith[u].push_back(v);
		connectedWith[v].push_back(u);
	}
	
	for (int i = 1; i <= n; i++) {
		sort (connectedWith[i].begin(), connectedWith[i].end());
	}
	
	vector<int> visited;
	stack<int> pathFromHome;
	int current = 1;
	int last = 1;
	while (visited.size() < n) {
		if (find(visited.begin(), visited.end(), current) == visited.end()) {
			visited.push_back(current);
			pathFromHome.push(current);
		}
		
		last = current;
		
		for (int i = 0; i < connectedWith[current].size(); i++) {
			if (find(visited.begin(), visited.end(), connectedWith[current][i]) == visited.end()) {
				current = connectedWith[current][i];
				break;
			}
		}
		
		if (current == last) {
			pathFromHome.pop ();
			current = pathFromHome.top();
		}
	}
	
	for (int i = 0; i < visited.size(); i++) {
		fout << visited[i] << " ";
	}
	
	return 0;
}
