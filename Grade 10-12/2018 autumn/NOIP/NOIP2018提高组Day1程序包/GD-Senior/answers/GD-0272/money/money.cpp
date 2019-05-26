#include <bits/stdc++.h>
using namespace std;

int n;
int a[105];

int main()
{
	FILE* fin = fopen("money.in", "rb");
	FILE* fout = fopen("money.out", "wb");
	int T;
	fscanf(fin, "%d", &T);
	while (T--)
	{
		set<int> s;
		memset(a, 0, sizeof(a));
		n = 0;
		
		fscanf(fin, "%d", &n);
		for (int i = 0; i < n; ++i)
			fscanf(fin, "%d", &a[i]);
		if (n == 1)
		{
			fprintf(fout, "%d\n", 1);
			continue;
		}
		if (n == 2)
		{
			if (!(max(a[0], a[1]) % min (a[0], a[1])))
				fprintf(fout, "%d\n", 2);
			else
				fprintf(fout, "%d\n", 1);
			continue;
		}
		
		sort(a, a + n);
		int nowProcessing = 0;
		for (; (a[nowProcessing] < a[0] + a[0]) && (nowProcessing < n); ++nowProcessing)
			s.insert(a[nowProcessing]);
	//	printf("First search is a[%d] = %d.\n", nowProcessing, a[nowProcessing]);
		int firstSearch = nowProcessing;
		
		if (firstSearch >= n)
		{
			fprintf(fout, "%d\n", n);
			continue;
		}
		
		for (int i = firstSearch; i < n; ++i)
			for (int j = 0; j < i; ++j)
				if ((!(a[i] % a[j])) && a[i] > 0 && a[j] > 0)
				{
				//	printf("Setting a[%d] = -1. (Previously %d)\n", i, a[i]);
					a[i] = -1;
				}
	/*
		for (int i = 0; i < n; ++i)
			if (a[i] > 0)
				printf("%d ", a[i]);
		printf("\n");
	*/
	/*
		cout << "Our set now has: ";
		for (set<int>::iterator begin = s.begin(); begin != s.end(); ++begin)
			cout << *begin << ' ';
		cout << endl;
	*/
		for (int i = firstSearch; i < n; ++i)
		{
			if (a[i] < 0)	continue;
		//	printf("Now processing %d.\n", a[i]);
			if (*s.find(a[i]) == a[i])
			{
				a[i] = -1;
				continue;
			}
			
			for (set<int>::iterator nowSearchingA = s.begin(); ((*nowSearchingA + *nowSearchingA <= a[i] + 1) || nowSearchingA == s.end()); ++nowSearchingA)
			{
			//	printf("nowSearchingA1 = %d, nowSearchingA = %d.\n", *nowSearchingA1, *nowSearchingA);
				for (set<int>::iterator nowSearchingB = nowSearchingA; ((*nowSearchingA + *nowSearchingB <= a[i] + 1) || nowSearchingB == s.end()); ++nowSearchingB)
				{
					s.insert(*nowSearchingA + *nowSearchingB);
				//	printf("Comparing (a[i] = %d) & %d + %d.\n", a[i], *nowSearchingA , *nowSearchingB);
					if (*s.find(*nowSearchingA + *nowSearchingB) == a[i])
					{
						a[i] = -1;
						continue;
					}
					s.insert(a[i]);
					/*
					cout << "Our set now has: ";
					for (set<int>::iterator begin = s.begin(); begin != s.end(); ++begin)
						cout << *begin << ' ';
					cout << endl;
					*/
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i)
			if (a[i] > 0)
				++ans;
		fprintf(fout, "%d\n", ans);
		/*
		system("pause");
		putchar('\n');
		*/
	}
	return 0;
}
