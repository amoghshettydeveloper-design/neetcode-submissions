// Unoptimized solution
class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> numMap;
        vector<bool> resArr(nums.size(), false);
        for (int i = 0; i < nums.size(); i++) {
            numMap[nums[i]] = i;
        }
        int mx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(resArr[i] == false){
                int c = 1;
                int nextNum = nums[i] + 1;
                resArr[i] = true;
                while(numMap.count(nextNum)){
                    int idx = numMap[nextNum];
                    resArr[idx] = true;
                    c++;
                    nextNum++;
                }
                mx = max(mx,c);
            }
        }
        return mx;
    }
};
