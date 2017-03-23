#include"leetCode.h"

/*
c++的unordered_map并不熟悉。实现的过程比较死板，算是纯粹的模拟吧！时间复杂度比较高，里面可能有比较多的无用代码。继续改进
*/
vector<int> Solution::findSubstring(string s, vector<string>& words) {
	vector<int> res;
	unordered_map<string, int> findstr;
	unordered_map<string, int>::iterator it;
	int start = 0;
	int len = words.size();
	int wordlen = 0;
	if (len != 0) wordlen = words[0].length();
	int *flag = new int[len + 1];
	int *count = new int[len + 1];
	memset(count, 0, sizeof(int)*(len + 1));
	for (int i = 0; i < len; i++) {
		if (findstr[words[i]] == 0){
			findstr[words[i]] = i + 1;
			count[i + 1] = 1;
		}
		else {
			count[findstr[words[i]]] += 1;
		}
	}
	for (int i = 0; i < s.length();i++ ) {
		string temp = s.substr(i, wordlen);
		it = findstr.find(temp);
		if (it != findstr.end()){
			memset(flag, 0, sizeof(int)*(len+1));
			if (s.length() - i < len * wordlen) break;
			else {
				flag[findstr[temp]] = 1;
				//cout << flag[findstr[temp]] << endl;
				int j = wordlen;
				for (; j < len * wordlen; j += wordlen) {
					temp = s.substr(i + j, wordlen);
					if (findstr.find(temp) == findstr.end()) break;
					else {
						flag[findstr[temp]]++;
						if (flag[findstr[temp]] > count[findstr[temp]]) break;
					}
				}
				if (j == len * wordlen) {
					int k = 1;
					for (;k <= len; k++) {
						if (flag[k] != count[k]) break;
					}
					if(k > len)
						res.push_back(i);
					
				}
			}
		}
	}
	return res;
}