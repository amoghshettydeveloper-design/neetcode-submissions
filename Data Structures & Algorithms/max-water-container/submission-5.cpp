class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size() - 1;
        int mx = 0;
        while(i<j){
            mx = max(mx,(min(heights[i],heights[j])) * (j-i));
            if(heights[i]>heights[j])
                j--;
            else
                i++;
        }
        return mx;
    }
};
