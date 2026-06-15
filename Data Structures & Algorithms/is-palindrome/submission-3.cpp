class Solution {
public:
    bool isAlphanumeric(char c){
        char lower = tolower(c);
        bool is = (lower >= 'a' && lower <= 'b') || (lower >= '1' && lower<='9');
        return (lower >= 'a' && lower <= 'z') || (lower >= '0' && lower<='9');
    }
    bool isPalindrome(string s) {
        for(int i=0,j=s.length()-1;i<j;i++,j--){
            while(i<j && !isAlphanumeric(s[i]))
                i++;
            while(i<j && !isAlphanumeric(s[j]))
                j--;
            if(tolower(s[i]) != tolower(s[j]))
                return false;
        }
        return true;
    }
};
