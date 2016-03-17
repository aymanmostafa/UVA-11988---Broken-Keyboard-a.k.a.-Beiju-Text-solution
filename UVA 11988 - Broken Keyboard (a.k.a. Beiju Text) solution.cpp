//============================================================================
// Name        : ayman.cpp
// Author      : Ayman Mostafa
// Email       : ayman93live@hotmail.com
// Version     : v5.0
//============================================================================

#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>

using namespace std;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()

void fastInOut();

//##########################################################################################
//###################################MAIN FUNCTION##########################################
//##########################################################################################
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
//freopen("output.txt", "wt", stdout);
#endif
	fastInOut();
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
// 11988 - Broken Keyboard (a.k.a. Beiju Text)
	string s, d, t;
	stack < string > st;
	bool k = false;
	while (cin >> s) {
		k = false;
		d = "", t = "";
		while (!st.empty())
			st.pop();
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '[')
				k = true;
			if (k) {
				if (s[i] == ']') {
					if (t != "")
						st.push(t);
					t = "";
					k = false;
				} else {
					if (s[i] == '[') {
						if (t != "")
							st.push(t);
						t = "";
						k = true;
					} else
						t += s[i];
				}
			} else
				d += s[i];
		}
		if (k == true)
			st.push(t);
		t = "";
		while (!st.empty()) {
			cout << st.top();
			st.pop();
		}
		for (int m = 0; m < d.size(); m++)
			if (d[m] != ']' && d[m] != '[')
				t += d[m];
		if (t != "")
			cout << t;
		cout << endl;
		t = "", d = "";
	}
}
void fastInOut() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
