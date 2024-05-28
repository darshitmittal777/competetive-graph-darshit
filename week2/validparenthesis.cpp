class Solution {
public:
    bool isValid(string s) {
        vector<char> cur;
        int l = s.length();
        bool check = 1;
        for(int i=0;i<l;i++)
        {
            if(s[i]=='['||s[i]=='{'||s[i]=='(')
            {
                cur.push_back(s[i]);
            }
            else if(cur.size()==0)
            {
                return 0;
            }
            else if(s[i]=='}')
            {
                if(cur.back()!='{')
                {
                    check=0;
                    break;
                }
                else
                cur.pop_back();
            }
            else if(s[i]==')')
            {
                if(cur.back()!='(')
                {
                    check=0;
                    break;
                }
                else
                cur.pop_back();
            }
            else if(s[i]==']')
            {
                if(cur.back()!='[')
                {
                    check=0;
                    break;
                }
                else
                cur.pop_back();
            }
            cur.shrink_to_fit();
        }
        if(cur.size()!=0)
        check =0;
        return check;
    }
};