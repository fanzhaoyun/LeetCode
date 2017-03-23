#include"leetCode.h"

int Solution::romanToInt(string s) {
	int number = 0;
	int a[25] = { 0 };
	a['I' - 'A'] = 1;
	a['V' - 'A'] = 5;
	a['X' - 'A'] = 10;
	a['L' - 'A'] = 50;
	a['C' - 'A'] = 100;
	a['D' - 'A'] = 500;
	a['M' - 'A'] = 1000;
	if (s.length() != 0)
		number = a[s[0] - 'A'];
	for (int i = 1; i < s.length(); i++) {
		number += a[s[i] - 'A'];
		if (s[i] == 'V' && s[i - 1] == 'I' || s[i] == 'X' && s[i - 1] == 'I') {
			number -= 2;
			continue;
		}
		if (s[i] == 'L' && s[i - 1] == 'X' || s[i] == 'C' && s[i - 1] == 'X') {
			number -= 20;
			continue;
		}
		if (s[i] == 'D' && s[i - 1] == 'C' || s[i] == 'M' && s[i - 1] == 'C') {
			number -= 200;
			continue;
		}
	}
	return number;
}
