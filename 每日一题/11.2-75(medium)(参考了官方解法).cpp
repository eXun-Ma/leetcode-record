/***
输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]
思路：
设置3个指针，一个p0指向0元素最右下标，p2指向2元素最左下标，cur指向当前遍历元素下标，如果：
1.nums[cur]==0，则跟nums[p0]交换，并将cur、p0指针右移；
2.nums[cur]==2，则跟nums[p2]交换，并将p2指针左移；
3.nums[cur]==1，则cur指针右移
***/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        TreeNode *p=root;
        vector<int> res;
        while(!S.empty()||p){
            while(p){
                S.push(p);
                p=p->left;
            }
            if(!S.empty()){
                p=S.top();
                S.pop();
                res.push_back(p->val);
                p=p->right;
            }
        }
        return res;
    }
};
