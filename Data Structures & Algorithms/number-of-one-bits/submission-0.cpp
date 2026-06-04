class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            int r = n%2;
            if(r)
                count++;
            n /= 2;
        }
        return count;
    }
};
