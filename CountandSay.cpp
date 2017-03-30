#include"leetCode.h"

string Solution::countAndSay(int n) {
	string res = "";
	if (n == 0) return res;
	res = res + "1";
	if (n == 1) return res;
	for (int i = 2; i <= n; i++) {
		string tempstr = res;
		res = "";
		int count = 1;
		for (int j = 0; j < tempstr.length() - 1; j++) {
			if (tempstr[j] == tempstr[j + 1]) count++;
			else {
				char str[15];
				sprintf(str, "%d", count);
				string temp = string(str);
				res += temp;
				res += tempstr[j];
				count = 1;
			}
		}
		char str[15];
		sprintf(str, "%d", count);
		string temp = string(str);
		res += temp;
		res += tempstr[tempstr.length() - 1];
	}
	return res;
}