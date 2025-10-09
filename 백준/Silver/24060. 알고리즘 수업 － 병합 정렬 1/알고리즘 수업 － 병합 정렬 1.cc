#include<iostream>
#include<vector>
using namespace std;

long long save_count = 0;
int K;
int result = -1;

void merge(vector<int>& v, int p, int q, int r) {
	int i = p;
	int j = q + 1;
	int t = 1;
	vector<int> tmp;

	while (i <= q && j <= r) {
		if (v[i] <= v[j]) {
			tmp.push_back(v[i]);
			i++;
		}
		else {
			tmp.push_back(v[j]);
			j++;
		}
	}
	while (i <= q) {
		tmp.push_back(v[i]);
		i++;
	}
	while (j <= r) {
		tmp.push_back(v[j]);
		j++;
	}
	i = p;
	t = -1;
	
	for (int k = 0; k < tmp.size(); k++) {
		v[p + k] = tmp[k];
		save_count++;
		if (save_count == K) {
			result = tmp[k];
		}
	}
}

void merge_sort(vector<int>& v, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(v, p, q);
		merge_sort(v, q + 1, r);
		merge(v, p, q, r);
	}
}



int main() {
	int n;
	cin >> n >> K;
	
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	merge_sort(v, 0, n - 1);

	cout << result << "\n";
}