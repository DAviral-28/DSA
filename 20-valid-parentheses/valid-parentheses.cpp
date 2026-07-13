class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char>ss;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            ss.push(s[i]);
            else if(s[i]=='{')
            ss.push(s[i]);
            else if(s[i]=='[')
            ss.push(s[i]);
            else
            {
                char k=s[i];
                if(!ss.empty() && ((k==')' && ss.top()!='(') || (k=='}' && ss.top()!='{') || (k==']' && ss.top()!='[')))
                return false;
                else if(!ss.empty())
                ss.pop();
                else return false;
            }
        }
        return ss.empty();
    }
};