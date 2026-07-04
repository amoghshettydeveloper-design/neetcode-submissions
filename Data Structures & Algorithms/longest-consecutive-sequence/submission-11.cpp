class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> numSet;
        for(int n: nums){
            numSet.insert(n);
        }
        int mx = 0,count = 0;
        for(int n: nums){
            count = 0;
            if(!numSet.count(n-1)){
                count++;
                while(numSet.count(n+1)){
                    n++;
                    count++;
                }
                mx = max(mx,count);
            }
        }
        return mx;
    }
};
