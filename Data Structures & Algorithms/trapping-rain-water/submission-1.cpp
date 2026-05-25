class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lArr(n,0),rArr(n,0);
        int areaOfWater = 0;
        lArr[0] = height[0];
        rArr[n-1] = height[n-1]; 
        for(int i = 1; i < n; i++){
            if(height[i]>lArr[i-1])
                lArr[i] = height[i];
            else
                lArr[i] = lArr[i-1];
        }

        for(int i = n - 2; i >= 0; i--){
            if(height[i]> rArr[i+1])
                rArr[i] = height[i];
            else
                rArr[i] = rArr[i+1];
        }
        
        for(int i = 0; i < n;i++){
            areaOfWater += min(lArr[i],rArr[i]) - height[i];
        }

        return areaOfWater;
    }
};
