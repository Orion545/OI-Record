#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct s {
	int a;
	int b;
};

int min (int * d, int from, int to)
{
	int min = d[from];
	
	for (int i = from; i <= to; i++) {
		if (d[i] < min) {
			min = d[i];
		}
	}
	
	return min;
}

vector<s> segs (int * d, int l)
{
	vector<s> segs;
	
	int start = 0;
	int end = 0;
	int pos = 0;
	
	while (pos < l) {
		start = pos;
		while (d[pos]) {
			pos++;
		} // find end of current seg
		end = pos;
		while (!d[pos]) {
			pos++;
		} // skip to start of next seg
		
		s seg;
		seg.a = start;
		seg.b = end - 1;
		segs.push_back(seg);
	}
	
	return segs;
}

int main ()
{
	int d[100000];
	
	ifstream fin ("road.in");
	ofstream fout ("road.ans", ios::trunc);
	
	int l = 0; // length
	fin >> l;
	
	for (int i = 0; i < l; i++) {
		fin >> d[i];
	}
	
	int daysNeeded = 0;
	do {
		vector<s> segments = segs(d, l);
		for (int i = 0; i < segments.size(); i++) {
			//fout << i << " [" << segments.at(i).a << ", " << segments.at(i).b << "] " << endl;
		}
		if (segments.size() == 1 && segments.at(0).a == 0 && segments.at(0).b == -1) {
			break;
		}
		
		for (int i = 0; i < segments.size(); i++) {
			int daysNeededThisSeg = min(d, segments.at(i).a, segments.at(i).b);
			//fout << "Days needed for seg " << i << ": " << daysNeededThisSeg << endl;
			daysNeeded += daysNeededThisSeg;
			
			for (int j = segments.at(i).a; j <= segments.at(i).b; j++) {
				d[j] -= daysNeededThisSeg;
			}
		}
	} while (true);
	
	fout << daysNeeded << endl;
	
	return 0;
}

