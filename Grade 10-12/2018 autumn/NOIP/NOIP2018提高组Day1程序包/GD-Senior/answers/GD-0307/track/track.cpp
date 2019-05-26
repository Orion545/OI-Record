#include <bits/stdc++.h>

using namespace std;

int n, m, a[50002], left_ = 0, right_ = 0, middle, input_a, input_b, input_l;

bool is_ok();

int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);

	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 1; i < n; ++i) {
		scanf("%d %d %d", &input_a, &input_b, &input_l);
		if (input_a > input_b)
			swap(input_a, input_b);
		if (a[input_a] < input_l)
			a[input_a] = input_l;
		right_ += input_l;
	}
	while (left_ < right_) {
		middle = (left_ + right_ + 1) >> 1;
		if (is_ok())
			left_ = middle;
		else
			right_ = middle - 1;
	}
	printf("%d", left_);

	fclose(stdin);
	fclose(stdout);
	return 0;
}

bool is_ok() {
	int temp = 0, road_ok = 0;
	for (int i = 1; i < n; ++i) {
		temp += a[i];
		if (temp >= middle) {
			++road_ok;
			temp = 0;
		}
	}
	return road_ok >= m;
}
