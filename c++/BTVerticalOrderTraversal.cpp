/*
Vertical order Binary Tree Traversal
*/
#include<iostream>
#include<vector>
#include<queue>
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
vector<queue<int>> vTvectQ;
vector<queue<int>> vTvectQBack;
vector<queue<int>>::iterator first;
vector<queue<int>>::iterator firstBack;
int start = 0, stop = 0;


void veritcalOrderTraversal(Node* root, int offset)
{
	

	if (root == NULL)
		return;
	
	queue<int> tempQ;

	if (offset>=0 && vTvectQ.size() == 0)
	{
		vTvectQ.push_back(tempQ);
		first = vTvectQ.begin();
		
	}

	if (offset < 0 && vTvectQBack.size() == 0)
	{
		vTvectQBack.push_back(tempQ);
		start = offset;
		firstBack = vTvectQBack.begin();
	}
	

	if (offset < start)
	{
		start = offset;
		vTvectQBack.push_back(tempQ);
	}
	else if (offset > stop)
	{
		stop = offset;
		vTvectQ.push_back(tempQ);

	}
	if(offset>=0)
		vTvectQ[offset].push(root->data);
	else
		vTvectQBack[-(offset+1)].push(root->data);

	veritcalOrderTraversal(root->left, offset - 1);
	veritcalOrderTraversal(root->right, offset + 1);

	return;
}

int main()
{
	queue<int> tempQ;
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

	cout << "Going to print vertical order traversal: ";
	veritcalOrderTraversal(root,0);


	for (auto i = vTvectQBack.end() - 1; i >= vTvectQBack.begin(); i--)
	{
		cout << "Column " <<  (i - vTvectQBack.end() )  << " is: " << endl;
		tempQ = *(i);

		while (tempQ.size() > 0)
		{
			cout << tempQ.front() << " ";
			tempQ.pop();
		}
		cout << endl;
	}

	for (auto i = vTvectQ.begin(); i != vTvectQ.end(); i++)
	{
		cout << "Column "<<i-vTvectQ.begin() <<" is: " << endl;
		tempQ = *(i);

		while (tempQ.size() > 0)
		{
			cout << tempQ.front() <<" ";
			tempQ.pop();
		}
		cout << endl;
	}

	getchar();
	getchar();
	return 0;
}