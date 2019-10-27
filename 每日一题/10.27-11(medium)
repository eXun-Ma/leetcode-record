/*
一开始用了sort函数，效率好高，速度好快，但是代码只有两行8太好意思哈哈哈哈
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //sort(nums.begin(),nums.end());
        //return nums[nums.size()-k];
        int low=0,high=nums.size()-1,mid=0;
        while(low<=high){
            mid=partition(nums,low,high);
            if(mid==nums.size()-k) return nums[mid];
            else if(mid<nums.size()-k) 
                low=mid+1;
            else
                high=mid-1;
        }
        return -1;
    }
    int partition(vector<int>&nums,int low, int high){
        int left=low, right=high;
        int base=nums[low];
        while(left<right){
            while(nums[right]>=base&&left<right) right--;
            if(left<right)
                nums[left]=nums[right];
            while(nums[left]<=base&&left<right) left++;
            if(left<right)
                nums[right]=nums[left];
        }
        nums[left]=base;
        return left;
    }
};
