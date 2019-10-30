
/***
考虑需要向左归约的情况：
1.nums[0]<nums[mid]，在前半段没有发生旋转，若nums[0]<=target<=nums[mid]，向左归约
2.nums[0]>nums[mid]，在前半段发生旋转，若nums[mid]>target表明在前半段中靠后的升序数组中;若nums[0]<target表明在前半段靠前的升序数组中
***/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[0]<=target&&target<=nums[mid])
                right=mid-1;
            else if(nums[mid]<nums[0]&&(nums[mid]>target||nums[0]<=target))
                right=mid-1;
            else left=mid+1;
        }
        return -1;
    }
};
