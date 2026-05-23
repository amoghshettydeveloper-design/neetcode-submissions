class Solution {
   public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        bool deleted = false;
        while (i < j) {
            if (s[i] != s[j]) {
                if (i == j) {
                    return false;
                }
                deleted = true;
                break;
            } else {
                i++;
                j--;
            }
        }
        if (!deleted) return true;
        int ogi = i;
        int ogj = j;
        i++;
        bool flag = true;
        while (i < j) {
            if (s[i++] != s[j--]) {
                flag = false;
                break;
            }
        }
        i = ogi;
        j = ogj - 1;
        if(!flag){
            while (i < j) {
                if (s[i++] != s[j--]) return false;
            }
            return true;
        }
        return flag;
    }
};