class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> mySet;

        for(int n:nums){
            cout<<mySet.count(n)<<endl;
            if(mySet.count(n) != 0)
                return true;
            mySet.insert(n);
        }
        
        return false;
    }
};