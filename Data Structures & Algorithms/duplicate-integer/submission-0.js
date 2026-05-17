class Solution {
    /**
     * @param {number[]} nums
     * @return {boolean}
     */
    hasDuplicate(nums) {
        const numSet = new Set();

        for(const n of  nums){
            
            if(numSet.has(n))
                return true;
            numSet.add(n);
        }
        return false;
    }
}
