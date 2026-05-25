// O(1) space complexity
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int areaOfWater = 0;
        int lMax = 0,rMax = 0;
        int i = 0,j = n-1;
        while(i<j){
            lMax = max(lMax,height[i]);
            rMax = max(rMax,height[j]);
            if(lMax < rMax){
                areaOfWater += lMax - height[i];
                i++;
            }
            else{
                areaOfWater += rMax - height[j];
                j--;
            }
        }
        return areaOfWater;
    }
};
