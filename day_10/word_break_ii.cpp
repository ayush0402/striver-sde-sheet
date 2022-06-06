bool isPresent(vector<string>& dictionary, string find) {
    for (int i = 0; i < dictionary.size(); i++) {
        if (dictionary[i] == find)return true;
    }
    return false;
}
void recur(vector<string>& ans, string& temp, vector<string>& dictionary, string& s, int index) {
    if (index == s.size()) {
        ans.push_back(temp.substr(0, temp.size() - 1));
        return;
    }
    for (int i = index; i < s.size(); i++) {
        if (isPresent(dictionary, s.substr(index, i - index + 1))) {
            string tempcopy = temp;
            tempcopy += s.substr(index, i - index + 1);
            tempcopy += " ";
            recur(ans, tempcopy, dictionary, s, i + 1);
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string> ans;
    string temp = "";
    recur(ans, temp, dictionary, s, 0);

    return ans;
}
