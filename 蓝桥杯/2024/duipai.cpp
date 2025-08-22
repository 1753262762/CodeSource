#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;

int n;
int h[N];

vector<int> v[N];

signed main() {
	freopen("a.in","r",stdin);
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	
	sort(h + 1, h + 1 + n);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j * j <= h[i]; j++) {
			if (h[i] % j == 0) {
				if (v[i].size() < 3) {
					v[j].push_back(h[i]);
				}
				
				if (j * j < h[i] && v[h[i] / j].size() < 3) {
					v[h[i] / j].push_back(h[i]);
				}
			}
		}
	}
	
	for (int i = 1e5; i; i--) {
		if (v[i].size() >= 3 && __gcd(v[i].at(0), __gcd(v[i].at(1), v[i].at(2))) == i) {
			cout << v[i].at(0) << ' ' << v[i].at(1) << ' ' << v[i].at(2) << endl;
			break;
		}
	}
	
	return 0;
}