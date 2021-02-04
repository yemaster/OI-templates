/*
 * Description: Miller_Rabin素数测试
 * Problem:     
 * Author:      yemaster
 *.
#include<cstdio>
#include<cstring>
#include<algorithm>

#define RI register int

using namespace std;

int prime[21]= {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 79};

inline int Quick_Multiply(int a,int b,int c) {
	long long ans = 0, res = a;
	while (b) {
		if (b & 1)
			ans = (ans + res) % c;
		res = (res + res) % c;
		b >>= 1;
	}
	return (int)ans;
}
int Quick_Power(int a, int b, int c) {
	int ans= 1, res = a;
	while (b) {
		if(b & 1)
			ans = Quick_Multiply(ans, res, c);
		res = Quick_Multiply(res, res, c);
		b >>= 1;
	}
	return ans;
}
bool Miller_Rabin(int x) {
	int s = 0, t = x - 1, k;
	if (x==2) 
		return 1;
	if (x < 2 || !(x & 1))
		return 0;
	while(!(t & 1)) {
		s++;
		t >>= 1;
	}
	for(RI i = 0; i < 4 && prime[i] < x; ++i) {
		int a = prime[i];
		int b = Quick_Power(a, t, x);
		for(RI j = 1; j <= s; ++j) {
			k = Quick_Multiply(b, b, x);
			if (k == 1 && b != 1 && b != x - 1)
				return 0;
			b = k;
		}
		if(b != 1)
			return 0;
	}
	return 1;
}
int main() {
	int x;
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d", &x);
		if(Miller_Rabin(x)) 
			printf("Yes\n");
		else 
			printf("No\n");
	}
	return 0;
}
