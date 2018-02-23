/*
http://www.geeksforgeeks.org/subtree-given-sum-binary-tree/
*/

#include<iostream>
using namespace std;


class Node
{
public:
	int data;
	Node* left, *right;
	Node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};


Node * root = NULL;

int sumSubtreeUtil(struct Node *ptr, int sum, bool &absTruth)
{

	if (absTruth)
		return sum;
	else if (ptr == NULL)
		return 0;
	else
	{
		int leftSum = 0, rightSum = 0, totSum = 0;
		leftSum = sumSubtreeUtil(ptr->left, sum, absTruth);
		rightSum = sumSubtreeUtil(ptr->right, sum, absTruth);
		totSum = leftSum + rightSum + ptr->data;
		if (totSum == sum)
		{
			absTruth = true;
			return sum;
		}
		else
			return totSum;
	}
}
int main()
{
	bool absTruth = false;
	int sum = 0;
	//Initialize the BT
	root = new Node(8);
	Node * temp = root;
	temp->left = new Node(5);
	temp->right = new Node(4);

	temp->left->left = new Node(9);
	temp->left->right = new Node(7);
	temp->left->right->left = new Node(1);
	temp->left->right->right = new Node(12);
	temp->left->right->right->left = new Node(2);

	temp->right->right = new Node(11);
	temp->right->right->left = new Node(3);

	cout << "Enter sum: "<<endl;
	cin >> sum;

	sumSubtreeUtil(root, sum, absTruth);
	
	if (absTruth)
		cout << "Yes";
	else
		cout << "No";
	getchar();
	getchar();
	return 0;
}