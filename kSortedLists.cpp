#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode* mergeKLists(vector<ListNode*>& lists) {

	//vector<int> indexVector(lists.size(),0);
	ListNode *select = NULL, *begin = NULL, *current = NULL;
	int nullFlag = 0;
	int min = INT_MAX;
	vector<ListNode*>::iterator selectIterator;
	begin = new ListNode(0);
	current = begin;
	while (1)
	{
		nullFlag = 0;
		for (vector<ListNode*>::iterator i = lists.begin(); i < lists.end(); i++)
		{
			if (*i != NULL)
			{
				nullFlag = 1;
				if ((*i)->val < min)
				{
					min = (*i)->val;
					select = (*i);
					selectIterator = i;
				}
			}
			else
			{
				//lists.erase(i);
				swap(*i, lists.back());
				lists.pop_back();
				//if (i + 1 == lists.end())
					i--;
				if (lists.size() == 0)
					break;

			}
		}
		min = INT_MAX;
		current->next = select;
		current = select;
		if(nullFlag == 1)
		(*selectIterator) = (*selectIterator)->next;

		if (nullFlag == 0)
		{
			if(current != NULL)
			current->next = NULL;
			break;

		}
			
	}
	//Run through first elements of k lists until all lists are fully processed
	begin = begin->next;
	return begin;
}

int main()
{
	vector<ListNode*> listsa;
	ListNode* a = NULL,*result= NULL,*b = NULL;

	a = new ListNode(1);
	b = new ListNode(-1);
	b->next = new ListNode(2);
	//a->next = new ListNode(2);

	listsa.push_back(a);
	listsa.push_back(b);
	listsa.push_back(NULL);

	result = mergeKLists(listsa);

	cout << "hello the final linked list is: "<<endl;
	for (ListNode *current = result; current != NULL; current = current->next)
	{
		cout << current->val<<endl;
	}

	getchar();
	return 0;
}

