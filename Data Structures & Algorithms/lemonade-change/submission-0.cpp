class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0, twentys = 0;

        for(int n:bills){
            if(n == 5)
                fives++;
            else if(n == 10){
                if(fives){
                    fives--;
                    tens++;
                }
                else
                    return false;
            }
            else if(n == 20){
                if(fives && tens){
                    fives--;
                    tens--;
                }
                else if(fives>=3){
                    fives -= 3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};