class Solution {
public:
    int maxArea(vector<int>& heights) {
        int mx = 0;
        int i=0,j=heights.size()-1;
        while(i<j){
            mx = max(mx,min(heights[i],heights[j])*(j-i));
            if(heights[i]<heights[j])
                i++;
            else if(heights[i]>heights[j])
                j--;
            else{
                i++;
                j--;
            }
        }
        return mx;
    }
};
