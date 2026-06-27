class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> x = nums;
        nums.insert(nums.end(), x.begin(), x.end());  

        int n = x.size();
        vector<int> ans(n, -1);                      
        vector<int> st;                               

        st.push_back(0);

        for (int i = 1; i < nums.size(); i++) {

            while (!st.empty() && nums[i] > nums[st.back()]) {
                if (st.back() < n)                  
                    ans[st.back()] = nums[i];
                st.pop_back();
            }

            if (i < n)
                st.push_back(i);
        }

        return ans;
    }
};