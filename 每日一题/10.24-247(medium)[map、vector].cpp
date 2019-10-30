/*
要求时间复杂度为nlog(n),先将数据存到map中，复杂度为O(n)，再对其进行sort，复杂度为log(n)
*/
class Solution{
public:
    bool cmp(const pair<int,int> x, const pair<int,int> y){
        return x.second > y.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> M;
        for(int i=0;i<nums.size();i++){//将数据存储到map中 复杂度O(n)
            map<int,int>::iterator iter=M.find(nums[i]);//迭代器
            if(iter!=M.end())//如果找到的话，将其value+1
                iter->second=iter->second+1;//访问迭代器的second要用->
            else
                M.insert(pair<int,int>(nums[i],1));//插入 pair
        }
        vector<pair<int,int>> vec(M.begin(),M.end());
        //sort(vec.begin(),vec.end(),cmp);//在cmp前面加static的话就可以用
        sort(vec.begin(),vec.end(),[](pair<int, int>& x, pair<int, int>& y){return x.second > y.second; });
        vector<int> result;
        for(int i=0;i<k;i++)
            result.push_back(vec[i].first);//往vector中添加元素
        return result;
    }
};
