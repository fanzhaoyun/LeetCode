#include"leetCode.h"

/*
���Ƕ��ֵ�˼�롣�Ȳ��ϵ��ó�����Ϊԭ��������ֱ�����ڱ�����Ϊֹ����¼�´��ڱ�����֮ǰ��ֵ��Ȼ���ñ�������ȥ��ֵ������ͬ�ķ������У�
ֱ���µõ��ı�����С��ԭ���ĳ���Ϊֹ
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