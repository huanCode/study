#include "common.h"

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0)
            return 0;

        return createTree(preorder, inorder, preorder.size() - 1, inorder.size() - 1);
     

    }

    TreeNode* createTree(vector<int>& preorder, vector<int>& inorder,int preBegin,int preEnd,int inBegin,int inEnd)
    {
        if (preBegin > preEnd)
            return 0;


        int indexCenter = 0;
        for (int i = inBegin; i <= inEnd; i++)
        {
            if (inorder[i] == preorder[preBegin])
            {
                indexCenter = i;
                break;
            }
        }

        

        TreeNode* pRoot = new TreeNode(preorder[preBegin]);

        int leftSize = indexCenter - inBegin;

        pRoot->left = createTree(preorder, inorder, preBegin+1, preBegin + leftSize, inBegin, indexCenter -1);

        pRoot->right = createTree(preorder, inorder, preBegin + leftSize + 1, preEnd,indexCenter + 1, inEnd);

        return pRoot;
    }
};