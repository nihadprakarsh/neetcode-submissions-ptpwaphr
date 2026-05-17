class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> v1(height.size(), -1), v2(height.size(), -1);

        int mx = -1;

        for(int i = 0; i < height.size(); ++i) {
            v1[i] = mx;
            mx = max(mx, height[i]);
        }

        mx = -1;

        for(int i = height.size() - 1; i >= 0; --i) {
            v2[i] = mx;
            mx = max(mx, height[i]);
        }

        int ans = 0;

        for(int i = 0; i < height.size(); ++i) {
            if(v1[i] > height[i] && v2[i] > height[i]) {
                ans += min(v1[i], v2[i]) - height[i];
            }
        }

        return ans;
    }
};