// 시간복잡도: 트리 내 노드의 갯수를 n이라 하면 모든 노드를 순회해야 함 O(n)
// 공간복잡도: 재귀호출이 일어나 스택을 사용함. 이때는 트리의 높이(h)에 따라 결정됨 O(h)
// * 균형 이진트리인 경우 O(log(n))
// ** 모든 노드가 한쪽만 자식을 가지는 경우 O(n)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr)
            return true;
        else if(p != nullptr && q == nullptr)
            return false;
        else if(p == nullptr && q != nullptr)
            return false;
        else if(p->val != q->val)
            return false;
        // else : p != nullptr && q != nullptr && p->val == q->val
        
        bool isLeftSame = isSameTree(p->left, q->left);
        bool isRightSame = isSameTree(p->right, q->right);
        return isLeftSame & isRightSame;
    }
};
