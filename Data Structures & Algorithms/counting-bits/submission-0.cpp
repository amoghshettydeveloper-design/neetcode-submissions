class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);
        int i = 1;
        while(i<=n){
            res[i] = res[i>>1] + (i & 1);
            i++;
        }
        return res;
    }
};
