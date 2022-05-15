class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //atmost 2 majority elements that appear more than [n/3] times
        int candidate1 = -1;
        int candidate2 = -1;
        int count1 = 0;
        int count2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == candidate1) {
                count1++;
            }
            else if (nums[i] == candidate2) {
                count2++;
            }
            else if (count1 == 0) {
                candidate1 = nums[i];
                count1++;
            }
            else if (count2 == 0) {
                candidate2 = nums[i];
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }

        vector <int> ans;
        count1 = 0;
        for (int num : nums) {
            if (num == candidate1)count1++;
        }

        count2 = 0;
        for (int num : nums) {
            if (num == candidate2)count2++;
        }
        if (count1 > nums.size() / 3)ans.push_back(candidate1);
        if (count2 > nums.size() / 3)ans.push_back(candidate2);

        if (ans.size() > 1) {
            if (ans[0] == ans[1])ans.pop_back();
        }
        return ans;
    }

};
