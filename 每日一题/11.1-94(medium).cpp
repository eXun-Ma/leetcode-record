/***
中序遍历二叉树：非空进栈向左走，为空退栈向右走
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
                p=p->right;//一开始这里我写了判断 if(p->right) p=p->right; 这样错了，因为不这样做直接出栈之后向右即可，之后发现p为NULL不会对p进行向左访问，直接从栈中取值。若这样做之后会一直在循环，因为p一直不为null
            }
        }
        return res;
    }
};
