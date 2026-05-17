class Solution {
public:
    bool isOpenPara(char c){
        return c == '{' || c == '[' || c == '(';
    }

    bool isClosePara(char c){
        return c == '}' || c == ']' || c == ')';
    }

    char getOpenPara(char c){
        switch(c){
            case ')' :  c='(';
                        break;
            case ']' :  c='[';
                        break;
            case '}' :  c='{';
                        break;

        }
        return c;
    }

    bool isValid(string s) {
        int i=0;
        stack<char> paraStack;
        while(i<s.size()){
            cout<<s[i]<<isOpenPara(s[i])<<endl;
            while(isOpenPara(s[i])){
                paraStack.push(s[i++]);
            }
            cout<<s[i]<<isClosePara(s[i])<<endl;
            if(isClosePara(s[i])){
                // cout<<"inside"<<paraStack.top()<<endl;
                if(paraStack.empty()){
                    return false;
                }
                else{
                    cout<< paraStack.top() << "getOpenPara" <<getOpenPara(s[i])<<endl;
                    if( paraStack.top() != getOpenPara(s[i]))
                        return false;
                    else
                        paraStack.pop();
                }
            }
            i++;
        }
        return paraStack.empty();
    }
};
