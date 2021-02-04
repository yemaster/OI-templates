#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

inline double sqrt_newton(double n) {
	const double eps = 1E-15;
	double x = 1;
	while (1) {
		double nx = (x + n / x) / 2;
		if (abs(x - nx) < eps) 
			break;
		x = nx;
	}
	return x;
}

int main() {
	double n;
	scanf("%lf", &n);
	printf("%.12lf", sqrt_newton(n));
	return 0;
}
