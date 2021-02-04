/*
 * Description: 欧拉线性筛素数
 * Problem:     洛谷P3912
 * Author:      yemaster
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define RI register int

using namespace std;

int main() {
	int n, q;
	bool IsP[100000005];
	vector<int> Primes;
	scanf("%d", &n);
	memset(IsP, 1, sizeof(IsP));
	for (RI i = 2; i <= n; ++i) {
		if (IsP[i]) {
			Primes.push_back(i);
		}
		for (RI j = 0; j < Primes.size(); ++j) {
			if (i * Primes[j] > n)
				break;
			IsP[i * Primes[j]] = 0;
			if (i % Primes[j] == 0)
				break;
		}
	}
	printf("%d\n", Primes.size());
	return 0;
}
