class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res,"",0,0,n);
        return res;
    }
    void helper(vector<string>& res, string s,int open,int close, int max){
        if(s.length()==2*max){
            res.push_back(s);
            return;
        }
        if(open<max)
            helper(res,s+'(',open+1,close,max);
        if(close<open)
            helper(res,s+')',open,close+1,max);
    }
};
