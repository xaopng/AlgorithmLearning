/*
 * @lc app=leetcode.cn id=1130 lang=cpp
 *
 * [1130] 叶值的最小代价生成树
 */

// @lc code=start
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int res = 0;
        vector<int> st;
        st.push_back(INT_MAX);
        for (int i = 0; i < arr.size(); i++) {
            while (arr[i] >= st.back()) {
                int m = st.back();
                st.pop_back();
                res += m * min(arr[i], st.back());
            }
            st.push_back(arr[i]);
        }
        for (int i = 2; i < st.size(); i++) 
            res += st[i] * st[i - 1];
        return res;
    }
};
// @lc code=end


/* 
3 2 1

8 6
8 6 2 
8 6 9
9
*/
