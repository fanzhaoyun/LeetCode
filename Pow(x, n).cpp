#include"leetCode.h"

double Solution::myPow(double x, int n) {
	double res = 1.0;
	long long int nn = n;
	int flag = 1;
	if (nn < 0) {
		flag = 0;
		nn *= -1;
	}
	while (nn > 0) {
		double product = x;
		long long int temp = 1;
		while ((temp <<= 1) < nn) {
			product *= product;
		}
		temp >>= 1;
		nn -= temp;
		res *= product;
	}
	if (!flag) res = 1.0 / res;
	return res;
}