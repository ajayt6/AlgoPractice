/*
https://leetcode.com/problems/lru-cache/
*/
#include<iostream>
#include<map>
using namespace std;


class DoubleNode
{
public:
	int key, value;;
	DoubleNode* next, *prev;
	DoubleNode(int key,int value)
	{
		this->key = key;
		this->value = value;
		next = NULL;
		prev = NULL;
	}
};



class LRUCache {
	map<int, DoubleNode*> lruMap;
	DoubleNode *head, *tail;
	int capacity,count;
public:
	LRUCache(int capacity) {

		//Create dummy node to be used as head
		head = new DoubleNode(0,0);
		tail = NULL;
		this->capacity = capacity;
		count = 0;
	}

	//Define destructor
	~LRUCache()
	{
		DoubleNode *temp = head->next,*del = NULL;
		tail = NULL;
		head = NULL;
		while (temp != NULL)
		{
			del = temp->prev;
			delete del;
			
			if (temp->next == NULL)
			{
				delete temp;
				temp = NULL;
				del = NULL;
				break;
			}
			temp = temp->next;
		}
		
	}

	int get(int key) {

		DoubleNode *temp = NULL;
		int value;

		if (lruMap.find(key) == lruMap.end())
			return -1;
		temp = lruMap[key];

		if (count > 1)
		{
			//Remove this node from current postion and put it at the end which is most crecently used place
			if (temp->prev != NULL)
				temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;

			//Now put at end
			tail->next = temp;
			tail->next->prev = tail;
			tail->next->next = NULL;
			tail = tail->next;
		}
		

		value = temp->value;
		temp = NULL;

		return value;
	}

	void set(int key, int value) {
		DoubleNode *temp = NULL;

		if (count == capacity)
		{
			if (count == 1)
			{
				head->next = NULL;
				lruMap.erase(tail->key);
				delete tail;
				tail = NULL;
			}
			else{
				//Do steps to remove LRU node
				temp = head->next;
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;

				//Now do actual deletion from list as well as map
				lruMap.erase(temp->key);
				delete temp;
				temp = NULL;
				count--;
			}
			
		}

		//Increase the count
		count++;

		//Insert into list first
		
		if (tail == NULL)
		{
			tail = new DoubleNode(key, value);
			head->next = tail;
			tail->prev = head;
			//Insert to map
			lruMap.insert(pair<int,DoubleNode*> (key, tail));
		}
		else
		{
			//Check if already in map
			if (lruMap.find(key) != lruMap.end())
			{
				temp = lruMap[key];

				//Remove this node from current postion and put it at the end which is most crecently used place
				if (temp->prev != NULL)
				temp->prev->next = temp->next;
				if (temp->next != NULL)
				temp->next->prev = temp->prev;

				//Now put at end
				tail->next = temp;
				tail->next->prev = tail;
				tail->next->next = NULL;
				tail = tail->next;

				//Now change value of key in node
				temp->value = value;
			}
			else
			{
				tail->next = new DoubleNode(key, value);
				tail->next->prev = tail;
				tail = tail->next;

				//Insert to map
				lruMap.insert(pair<int, DoubleNode*>(key, tail));
			}
			
		}
		

	}
};

int main()
{
	int key=0, value=0,choice=1,capacity=0;
	cout << "Enter capacity: ";
	cin >> capacity;

	LRUCache cache(capacity);

	cout << "Entering loop" << endl;
	do
	{
		cout << "1)Insert element\n2)Get element\nEnter choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter key: ";
			cin >> key;
			cout << "Enter value: ";
			cin >> value;
			cache.set(key, value);
			break;
		case 2:
			cout << "Enter key of value to be retrieved: ";
			cin >> key;
			cout << endl << "The value is: " << cache.get(key)<<endl;
			break;
		case 3:
			break;
		default:
			cout << "Wring choice!" << endl;
			break;

		}

		

	} while (choice != 3);
	
	

	getchar();
	return 0;
}