class Solution {
public:
    int maxArea(vector<int>& heights) {
        int mx = 0;
        int i = 0, j = heights.size() - 1;
        int mult = 0;
        while(i<j){
            int mult = min(heights[i],heights[j]);
            mx = max(mx,mult*(j-i));
            if(heights[i]>heights[j])
                j--;
            else 
                i++;
        }
        return mx;
    }
};
