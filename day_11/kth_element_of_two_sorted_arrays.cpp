// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
	int lessThanEqualTo(int arr[], int key, int sz) {
		int lo = 0;
		int hi = sz - 1;
		int mid = lo - (lo - hi) / 2;
		while (lo <= hi) {
			mid = lo - (lo - hi) / 2;
			if (arr[mid] <= key) {
				lo = mid + 1;
			}
			else {
				hi = mid - 1;
			}
		}
		return lo;
	}

	int kthElement(int arr1[], int arr2[], int n, int m, int k)
	{
		long long int lo = 1;
		long long int hi = INT_MAX;
		long long int mid = lo - (lo - hi) / 2;
		while (lo <= hi) {
			mid = lo - (lo - hi) / 2;
			long long int ind = lessThanEqualTo(arr1, mid, n);
			ind += lessThanEqualTo(arr2, mid, m);

			if (ind >= k) {
				hi = mid - 1;
			}
			else {
				lo = mid + 1;
			}
		}
		return lo;
	}
};

// { Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		int arr1[n], arr2[m];
		for (int i = 0; i < n; i++)
			cin >> arr1[i];
		for (int i = 0; i < m; i++)
			cin >> arr2[i];

		Solution ob;
		cout << ob.kthElement(arr1, arr2, n, m, k) << endl;
	}
	return 0;
}  // } Driver Code Ends
