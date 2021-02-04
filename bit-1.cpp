/*
  Description: 树状数组，单调修改，区间查询
  Problem:     luogu P3374
  Author:      yemaster
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define RI register int
#define lowbit(x) (x) & (-x)

using namespace std;

int n, m;
int c[500005];

inline void update(int x, int y) {
	for (int i = x; i <= n; i += lowbit(i))
		c[i] += y;	
}

inline int query(int l) {
	int ans = 0;
	for (RI i = l; i; i -= lowbit(i))
		ans += c[i];
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	for (RI i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		update(i, x);
	}
	for (RI i = 1; i <= m; ++i) {
		int tp, x, y;
		scanf("%d%d%d", &tp, &x, &y);
		if (tp == 1) {
			update(x, y);
		}
		else {
			printf("%d\n", query(y) - query(x - 1));
		}
	}
	return 0;
}
