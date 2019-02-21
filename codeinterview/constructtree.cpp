#ifndef CONSTRUCTTREE_H
#define CONSTRUCTTREE_H

/*
 * target:重建二叉树
 * input:vector<int>存储着二叉树的前序/中序/后序遍历的数据
 * output:重建后二叉树的根节点
*/

#include <iostream>
#include <vector>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//前序重建

TreeNode* preorder(const vector<int>& nums, const int& start, const int& end)
{
    if(start > end)
        return NULL;
    if(start == end)
    {
        return new TreeNode(nums[start]);
    }
    int mid = ((end - start) >> 1) + start;
    TreeNode* root = new TreeNode(nums[start]);
    root->left = preorder(nums, start+1, mid);
    root->right = preorder(nums, mid+1, end);

    return root;
}

TreeNode* constructpreorder(const vector<int>& nums)
{
    size_t sz = nums.size();
    if(sz == 0)
    {
        return NULL;
    }

    if(sz == 1)
        return new TreeNode(nums[0]);
    TreeNode* root;
    root = preorder(nums, 0, sz - 1);

    return root;
}

//中序重建

TreeNode* inorder(const vector<int>& nums, const int& start, const int& end)
{
    if(start > end)
    {
        return NULL;
    }
    if(start == end)
    {
        return new TreeNode(nums[start]);
    }
    int mid = ((end - start + 1) >> 1) + start;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = inorder(nums, start, mid - 1);
    root->right = inorder(nums, mid+1, end);

    return root;
}

TreeNode* constructinorder(const vector<int>& nums)
{
    size_t sz = nums.size();
    if(sz == 0)
    {
        return NULL;
    }

    if(sz == 1)
        return new TreeNode(nums[0]);

    TreeNode* root;
    root = inorder(nums, 0, sz - 1);

    return root;
}

//后序重建
TreeNode* postorder(const vector<int>& nums, const int& start, const int& end)
{
    if(start > end)
    {
        return NULL;
    }
    if(start == end)
    {
        return new TreeNode(nums[start]);
    }
    int mid = ((end - start) >> 1) + start;
    TreeNode* root = new TreeNode(nums[end]);
    root->left = postorder(nums, start, mid);
    root->right = postorder(nums, mid+1, end - 1);

    return root;
}

TreeNode* constructpostorder(const vector<int>& nums)
{
    size_t sz = nums.size();
    if(sz == 0)
    {
        return NULL;
    }

    if(sz == 1)
        return new TreeNode(nums[0]);

    TreeNode* root;
    root = postorder(nums, 0, sz - 1);

    return root;
}

#endif // CONSTRUCTTREE_H

