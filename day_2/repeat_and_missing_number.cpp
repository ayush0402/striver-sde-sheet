vector<int> Solution::repeatedNumber(const vector<int> &A) {
	int n = A.size();
	long long int expectedsum = (n * (n + 1)) / 2;
	long long int expectedsquaresum = (n * (n + 1) * (2 * n + 1)) / 6;

	for (int i = 0; i < n; i++) {
		expectedsum -= (long long int)A[i];
		expectedsquaresum -= (long long int)A[i] * (long long int)A[i];
	}

	long long int bminuisa = expectedsum;

	long long int bsqminusasq = expectedsquaresum;

	long long int bplusa = bsqminusasq / bminuisa;

	long long int b = (bplusa + bminuisa) / 2;
	long long int a = bplusa - b;

	vector <int> ans;
	ans.push_back(a);
	ans.push_back(b);
	return ans;
}
