//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long arr[], long long lo, long long mid, long long hi, long long& inversions) {
        vector <long long> temp;
        int i = lo; int j = mid + 1;
        while (i <= mid && j <= hi) {
            if (arr[i] <= arr[j])temp.push_back(arr[i]), i++;
            else {
                temp.push_back(arr[j]), j++;
                inversions += mid - i + 1;
            }
        }
        while (i <= mid)temp.push_back(arr[i]), i++;
        while (j <= hi)temp.push_back(arr[j]), j++;

        for (int k = 0; k < temp.size(); k++) {
            arr[lo + k] = temp[k];
        }
    }
    void mergeSort(long long arr[], long long lo, long long hi, long long& inversions) {
        if (lo < hi) {
            long long mid = (lo + hi) / 2;
            mergeSort(arr, lo, mid, inversions);
            mergeSort(arr, mid + 1, hi, inversions);
            merge(arr, lo, mid, hi, inversions);
        }
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long inversions = 0;
        mergeSort(arr, 0, N - 1, inversions);
        return inversions;
    }

};

//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while (T--) {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends
