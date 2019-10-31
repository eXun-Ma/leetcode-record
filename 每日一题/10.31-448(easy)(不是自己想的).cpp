/***
找到消失的数字，并且时间复杂度为o(n)，不使用额外空间。
思路：遍历元素，每个元素找到以该元素为下标的数字将其+n；最后再遍历一次元素，如果该元素小于等于n说明该元素所在下标为消失的数字。
***/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if(nums.size()==0) return nums;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            int index=(nums[i]-1)%nums.size();//因为该元素可能已经加上n了，要获取该元素对应的下标需要进行%运算
            nums[index]+=nums.size();
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=nums.size())
                result.push_back(i+1);
        }
        return result;
    }
};
