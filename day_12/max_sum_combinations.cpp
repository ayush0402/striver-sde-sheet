vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    priority_queue<pair<int, pair<int, int>>> pq;
    set <pair<int, int>> st;
    int i = A.size() - 1;
    int j = i;
    pq.push({A[i] + A[j], {i, j}});
    st.insert({i, j});
    vector <int> ans;
    while (C--) {
        ans.push_back(pq.top().first);

        i = pq.top().second.first;
        j = pq.top().second.second;

        pq.pop();
        if (st.find({i - 1, j}) == st.end()) {
            pq.push({A[i - 1] + B[j], {i - 1, j}});
            st.insert({i - 1, j});
        }
        if (st.find({i, j - 1}) == st.end()) {
            pq.push({A[i] + B[j - 1], {i, j - 1}});
            st.insert({i, j - 1});
        }
    }
    return ans;
}
