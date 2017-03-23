#include"leetCode.h"

/*
算是二分的思想。先不断的让除数变为原来的两倍直到大于被除数为止，记录下大于被除数之前的值，然后用被除数减去该值再用相同的方法进行，
直到新得到的被除数小于原来的除数为止
*/

int Solution::divide(int dividend, int divisor) {
	long long int res = 0;
	long long int divid = dividend, divis = divisor;
	if (divisor == 0) return INT_MAX;
	int a = (dividend > 0 && divisor > 0) ? 1 : -1;
	int b = (dividend < 0 && divisor < 0) ? 1 : -1;
	int sign = (a == 1 || b == 1) ? 1 : -1;
	if (dividend < 0) divid = -divid;
	if (divisor < 0) divis = -divis;
	while (divid >= divis) {
		long long int midtem = 1,tempdivi = divis;
		while (divid >= (tempdivi << 1)) {
			midtem <<= 1;
			tempdivi <<= 1;
		}
		divid -= tempdivi;
		res += midtem;
	}
	if (res > INT_MAX && sign == 1) res = INT_MAX;
	return sign * res;
}