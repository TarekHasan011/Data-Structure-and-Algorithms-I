#include<iostream>
using namespace std;
struct TreeNode
{
    int value;
    TreeNode* left;
    TreeNode* right;
};
typedef struct TreeNode TreeNode;

TreeNode* createTreeNode(int data)
{
    TreeNode* temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->value = data;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode* Insert(TreeNode* root, int data)
{
    if(root==NULL)
    {
        root = createTreeNode(data);
        return root;
    }

    if(data < root->value)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}

TreeNode* Search(TreeNode* root, int data)
{
    if(root==NULL)
        return root;
    if(root->value == data)
        return root;
    else if(data < root->value)
        return Search(root->left, data);
    else
        return Search(root->right, data);
}

void preorder(TreeNode* root)
{
    if(root!=NULL)
    {
        cout << root->value << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TreeNode* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
    }
}

void postorder(TreeNode* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->value << " ";
    }
}


TreeNode* Delete(TreeNode* root, int data)
{
    if(root==NULL)
        return root;

    if(data<root->value)
        root->left = Delete(root->left, data);
    else if(data>root->value)
        root->right = Delete(root->right, data);
    else
    {
        /// no child
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        /// only left child
        else if(root->left!=NULL && root->right==NULL)
        {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        /// only right child
        else if(root->left==NULL && root->right!=NULL)
        {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        /// two child
        else
        {
            TreeNode* rightLeftMost = root->right;
            while(rightLeftMost->left!=NULL)
            {
                rightLeftMost = rightLeftMost->left;
            }
            root->value = rightLeftMost->value;
            root->right = Delete(root->right, rightLeftMost->value);
        }
    }

    return root;

}
int main()
{
    TreeNode *root = NULL;
    int elements[11] = {5, 2, 8, 1, 3, 7, 19, 10, 20, 0, 4};
    for(int i=0;i<11;i++)
        root = Insert(root, elements[i]);
    inorder(root);
    cout << endl;

    root = Delete(root, 8);
    inorder(root);
    cout << endl;

}
