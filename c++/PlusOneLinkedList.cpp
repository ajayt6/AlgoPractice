/*
Plus One Linked List from LeetCode
*/

#include<iostream>
using namespace std;

class Node
{
public:
	int value;
	Node * next;

	Node(int num=0)
	{
		value = num;
		next = NULL;
	}

};

Node* buildNumList(int num)
{
	int newNum = 0;
	Node * head = NULL, *temp = NULL;
	head = new Node();
	//temp = head;
	while (num != 0)
	{
		//head = new Node();
		temp = new Node(num % 10);
		temp->next = head->next;
		head->next = temp;
		num = num / 10;


	}
	return head->next;
	/*while (num != 0)
	{
		newNum = newNum * 10;

		newNum = num % 10 + newNum;
		num = num / 10;
	}
	while (newNum != 0)
	{
		temp->next = new Node(newNum % 10);
		temp = temp->next;
		newNum = newNum / 10;
	}

	return head->next;
	*/
}

int addOneToListRecursive(Node * current)
{
	int ans = 0,rem=0;
	if (current->next != NULL)
	{
		rem = addOneToListRecursive(current->next);
		if (rem > 0)
		{
			ans = current->value + rem;
			current->value = ans % 10;
			return ans / 10;
		}
		else
			return 0;
	}
	else
	{
		//Do the addition part
		ans = current->value + 1;
		current->value = ans % 10;
		return ans / 10;

	}
}

Node * addOneToList(Node * head)
{
	Node * temp = NULL;
	int rem = 0;
	rem = addOneToListRecursive(head);
	if (rem > 0)
	{
		temp = new Node(rem);
		temp->next = head;
		head = temp;
	}
	return head;
}


int main()
{
	int n;
	Node * head = NULL;
	cout << "Enter a number: ";
	cin >> n;
	head = buildNumList(n);
	cout << "The linked list after adding one is: "<<endl;
	head = addOneToList(head);

	for (Node * temp = head; temp != NULL; temp = temp->next)
	{
		cout << temp->value;
		if (temp->next != NULL)
			cout << "->";
	}
	getchar();
	getchar();
	return 0;
}