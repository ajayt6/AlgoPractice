/*
https://leetcode.com/problems/binary-tree-paths/
*/
#include<iostream>
#include<vector>

#include<string>
using namespace std;


class TreeNode
{
public:
	int val;
	TreeNode* left, *right;
	TreeNode(int data)
	{
		this->val = data;
		left = NULL;
		right = NULL;
	}
};

void binaryTreePathsRecur(TreeNode* root, vector<string> &result, string currPath)
{
	if (root == NULL)
		return;
	else if (root->left == NULL && root->right == NULL)
	{
		//This is leaf node
		currPath = currPath + to_string(root->val);
		result.push_back(currPath);
		return;
	}
	else
	{
		//This is inner node
		currPath = currPath + to_string(root->val) + "->";
		binaryTreePathsRecur(root->left, result, currPath);
		binaryTreePathsRecur(root->right, result, currPath);

		return;
	}
}

vector<string> binaryTreePaths(TreeNode* root) {

	vector<string> result;
	
	binaryTreePathsRecur(root,result,"");

	//for (auto i = result.begin(); i < result.end(); i++)
		//cout << *i << endl;
	return result;
}

TreeNode *root = NULL;

int main()
{
	queue<int> tempQ;
	//Initialize the BT
	root = new TreeNode(8);
	TreeNode * temp = root;
	temp->left = new TreeNode(5);
	temp->right = new TreeNode(4);

	temp->left->left = new TreeNode(9);
	temp->left->right = new TreeNode(7);
	temp->left->right->left = new TreeNode(1);
	temp->left->right->right = new TreeNode(12);
	temp->left->right->right->left = new TreeNode(2);

	temp->right->right = new TreeNode(11);
	temp->right->right->left = new TreeNode(3);

	binaryTreePaths(root);

	getchar();
	return 0;
}