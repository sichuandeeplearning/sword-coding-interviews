#ifndef TREE_TRAVERSAL_H
#define TREE_TRAVERSAL_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//前序遍历 递归
vector<int> preorderTraversal_recursive(TreeNode* root)
{
    if(!root)
    {
        return vector<int>();
    }
    vector<int> v_root = {root->val};
    vector<int> v_left = preorderTraversal_recursive(root->left);
    vector<int> v_right = preorderTraversal_recursive(root->right);
    v_root.insert(v_root.end(),v_left.begin(), v_left.end());
    v_root.insert(v_root.end(),v_right.begin(), v_right.end());

    return v_root;
}

//前序遍历 循环
vector<int> preorderTraversal_loop(TreeNode* root)
{
    if(!root)
    {
        return vector<int>();
    }
    vector<int> v_root;
    stack<TreeNode*> sk;
    sk.push(root);
    TreeNode* tmp;

    while(!sk.empty())
    {
        tmp = sk.top();
        sk.pop();
        v_root.push_back(tmp->val);
        if(tmp->right)
        {
            sk.push(tmp->right);
        }
        if(tmp->left)
        {
            sk.push(tmp->left);
        }
    }
    return v_root;
}

//中序遍历 递归
vector<int> inorderTraversal_recursive(TreeNode* root)
{
    if(!root)
    {
        return vector<int>();
    }
    vector<int> v_root = {root->val};
    vector<int> v_left = inorderTraversal_recursive(root->left);
    vector<int> v_right = inorderTraversal_recursive(root->right);
    v_root.insert(v_root.begin(),v_left.begin(), v_left.end());
    v_root.insert(v_root.end(),v_right.begin(), v_right.end());

    return v_root;
}

//中序遍历 循环
vector<int> inorderTraversal_loop(TreeNode* root)
{
    if(!root)
    {
        return vector<int>();
    }
    vector<int> v_root;

    std::stack<TreeNode*> s;
    TreeNode* p = root;
    while(p || !s.empty())
    {
        while(p)
        {
            s.push(p);
            p = p->left;
        }
        if(!s.empty())
        {
            p = s.top();
            v_root.push_back(p->val);
            s.pop();
            p = p->right;
        }
    }

    return v_root;
}

//后序遍历 递归
vector<int> postorderTraversal_recursive(TreeNode* root)
{
    if(!root)
    {
        return vector<int>();
    }
    vector<int> v_root = {root->val};
    vector<int> v_left = postorderTraversal_recursive(root->left);
    vector<int> v_right = postorderTraversal_recursive(root->right);
    v_root.insert(v_root.begin(),v_right.begin(), v_right.end());
    v_root.insert(v_root.begin(),v_left.begin(), v_left.end());

    return v_root;
}

//后序遍历 循环
vector<int> postorderTraversal_loop(TreeNode* root)
{
    if(!root)
    {
        return vector<int>();
    }
    vector<int> v_root;

    stack<TreeNode*> s;
    TreeNode *cur;                      //当前结点
    TreeNode *pre=NULL;                 //前一次访问的结点
    s.push(root);
    while(!s.empty())
    {
        cur=s.top();
        if((cur->left==NULL&&cur->right==NULL)||
           (pre!=NULL&&(pre==cur->left||pre==cur->right)))
        {
            v_root.push_back(cur->val);  //如果当前结点没有孩子结点或者孩子节点都已被访问过
              s.pop();
            pre=cur;
        }
        else
        {
            if(cur->right!=NULL)
                s.push(cur->right);
            if(cur->left!=NULL)
                s.push(cur->left);
        }
    }

    return v_root;
}

//层次遍历
vector<int> levelTraverseTree(TreeNode* root)
{
    if(!root)
    {
        return vector<int>();
    }

    queue<TreeNode*> q;
    q.push(root);
    TreeNode* tmp;
    vector<int> v_root;

    bool l;
    bool r;

    while(!q.empty())
    {
        tmp = q.front();
        q.pop();
        v_root.push_back(tmp->val);

        l = tmp->left;
        r = tmp->right;

        if(l)
        {
            q.push(tmp->left);
        }
        if(r)
        {
            q.push(tmp->right);
        }
    }

    return v_root;
}

#endif // TREE_TRAVERSAL_H

