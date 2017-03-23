#include"leetCode.h"

int Solution::strStr(string haystack, string needle) {
	int h = 0, n = 0;
	int index = -1;
	if (needle.length() == 0) return 0;
	if (needle.length() > haystack.length()) return index;
	while (h < haystack.length()) {
		if (haystack[h] == needle[n]) {
			index = h;
			if ((haystack.length() - h) >= needle.length()) {
				n++, h++;
				while (n < needle.length() && haystack[h] == needle[n]) {
					n++;
					h++;
				}
			}
			if (n == needle.length()) {
				break;
			}
			else {
				n = 0;
				h = index;
				index = -1;
			}	
		}
		h++;
	}
	return index;
}