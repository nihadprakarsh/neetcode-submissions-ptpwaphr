class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (auto &i : asteroids) {
            bool flag = true;

            while (!st.empty() && i < 0 && st.top() > 0) {
                if (st.top() == abs(i)) {
                    st.pop();
                    flag = false;
                    break;
                }
                else if (st.top() < abs(i)) {
                    st.pop();
                }
                else {
                    flag = false;   
                    break;
                }
            }

            if (flag) {
                st.push(i);
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};