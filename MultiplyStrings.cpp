#include"leetCode.h"

//把进位直接给下一个
string add(char addres[][10][2], string s1, string s2) {
	string sum;
	char temp = '0',lasttemp='0';
	if (s1.size() < s2.size()) {
		string te = s1;
		s1 = s2;
		s2 = te;
	}
	int m = s1.size() - s2.size();
	for (int i = 0; i < m; i++) {
		s2 = '0' + s2;
	}
	for (int i = s2.size() - 1, j = s1.size() - 1; i >= 0; i--,j--) {
		temp = addres[s1[j] - '0'][s2[i] - '0'][0];
		s1[j] = addres[s1[j]-'0'][s2[i]-'0'][1];
		temp = addres[temp - '0'][addres[s1[j] - '0'][lasttemp - '0'][0] - '0'][1];
		s1[j] = addres[s1[j] - '0'][lasttemp - '0'][1];
		lasttemp = temp;
	}
	return temp + s1;
}

/*
string add(char addres[][10][2], string s1, string s2) {
string sum;
string temp = "0";
if (s1.size() < s2.size()) {
string te = s1;
s1 = s2;
s2 = te;
}
for (int i = s2.size() - 1, j = s1.size() - 1; i >= 0; i--,j--) {
temp = addres[s1[j] - '0'][s2[i] - '0'][0] + temp;
s1[j] = addres[s1[j]-'0'][s2[i]-'0'][1];
}
s2 = temp;
for (int i = s2.size() - 1, j = s1.size() - 1; i >= 0; i--, j--) {
s1[j] = addres[s1[j] - '0'][s2[i] - '0'][1];
}
return s1;
}
*/
string Solution::multiply(string num1, string num2) {
	char pudc[10][10][2];
	char addres[10][10][2];
	string res, tempres;
	int m = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			pudc[i][j][0] = (i*j) / 10 + '0';
			pudc[i][j][1] = (i*j) % 10 + '0';
			addres[i][j][0] = (i+j) / 10 + '0';
			addres[i][j][1] = (i+j) % 10 + '0';
		}
	}
	if (num1.size() > num2.size()) {
		string te = num1;
		num1 = num2;
		num2 = te;
	}
	for (int i = num1.size() - 1; i >=0 ; i--) {
		string s1="", s2;
		for (int k = 0; k < m; k++) {
			s1 += '0';
		}
		s2 = s1 + '0';
		for (int j = num2.size()-1; j >= 0; j--) {
			s1 = pudc[num1[i] - '0'][num2[j] - '0'][1] + s1;
			s2 = pudc[num1[i] - '0'][num2[j] - '0'][0] + s2;
		}
		tempres = add(addres, s1, s2);
		res = add(addres, res, tempres);
		m++;
	}
	int i = 0;
	while (res[i] == '0') {
		i++;
	}
	if (i == res.size()) res = "0";
	else res = res.substr(i);
	return res;
}