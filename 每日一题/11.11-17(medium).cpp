class Solution {
public:
    map<char,string> M={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> res;
        
        int length=0;
        string s="";
        helper(res,digits,s,length);
        return res;
    }
    void helper(vector<string>& res,string digits,string s,int length){
        if(s.length()==digits.length()){
            res.push_back(s);
            return;
        }
        for(int i=length;i<digits.size();i++){
            for(int j=0;j<M[digits[i]].size();j++){
                s=s+M[digits[i]][j];
                helper(res,digits,s,i+1);
                s.pop_back();
            }
        }
    }
};
