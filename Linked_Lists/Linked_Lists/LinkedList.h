#pragma once

#include<iostream>

using namespace std;

template<class T>
class LinkedList
{
public:
	class Node
	{
	public:
		Node(T data, Node* next = nullptr)
			: next(next),
			data(data)
		{
			//this->next = next;
			//this->data = data;
		}

		//private:
		T data;
		Node* next;
	};

	//has to be defined explicitly because we defined a copy constructor down below
	LinkedList()
	{

	}

	~LinkedList()
	{
		//delete all nodes
		Node* temp, * temp2;
		temp2 = temp = head;

		while (temp != nullptr)
		{
			temp2 = temp->next;
			delete temp;
			temp = temp2;
		}
	}

	//= delete means do not automatically provide this function
	LinkedList(LinkedList& otherList) = delete;
	LinkedList& operator=(LinkedList& otherList) = delete;

	void Display() const
	{
		if (IsEmpty())
			cout << "list is empty" << endl;
		else
		{
			//cout << head->next->next->data << endl;

			Node* temp = head;
			while (temp != nullptr)//loop through all nodes
			{
				cout << temp->data << " -> ";
				temp = temp->next;//move to the next node (by assigning its address to temp)
			}
			cout << "nullptr" << endl;
		}
	}

	//For testing and making sure when you implement something (like for assignment 8) you 
	//haven't messed up what head and tail point to.
	void GetTailValue()
	{
		if (IsEmpty())
			cout << "tail is nullptr" << endl;
		else
			cout << "tail: " << tail->data << endl;
	}

	void GetHeadValue()
	{
		if (IsEmpty())
			cout << "head is nullptr" << endl;
		else
			cout << "head: " << head->data << endl;
	}

	//Purpose: Append a value to the beginning of the list
	//Precondtions: what needs to be setup/true before this can run (otherwise it may break): none
	//Postconditions: The new value should be at the front of the list
	void PushFront(T data)
	{
		if (IsEmpty())
			head = tail = new Node(data, head);
		else
			head = new Node(data, head);
		size++;
	}

	void PushBack(T data)
	{
		//With Tail pointer
		if (IsEmpty())
			head = tail = new Node(data, head);
		else
		{
			tail->next = new Node(data);
			tail = tail->next;
		}

		//Without Tail pointer
		/*if (IsEmpty())
			PushFront(data);
		else
		{
			Node* temp = head;
			while (temp->next != nullptr)//loop until we find the last node
				temp = temp->next;
			temp->next = new Node(data);
		}*/
		size++;
	}

	//Add an element anywhere in the linked list. Pass a value to insert and one to search for
	void Insert(const T& insertVal, const T& searchVal)
	{
		//I got the structure for this function from our text book: section 17-4b
		//Declare pointers
		Node* current; //pointer to traverse the list
		Node* trailCurrent = nullptr; //pointer just before current
		Node* newNode;//pointer to create inserted node

		bool found = false;
		newNode = new Node(insertVal, nullptr);//Create new node to store data and link

		//Case 1
		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
			size++;
		}
		else
		{
			current = head;//set current to point to the first node in list
			while (current != nullptr && !found)//Search the list
			{
				if (current->data == searchVal)
					found = true;
				else
				{
					trailCurrent = current;
					current = current->next;
				}
			}
			if (current == head)//Case 2
			{
				newNode->next = head;
				head = newNode;
				size++;
			}
			else//Case 3 for 
			{
				trailCurrent->next = newNode;
				newNode->next = current;

				if (current == nullptr)
					tail = newNode;

				size++;
			}
		}
	}

	void Remove(const T& searchVal)
	{
		//Declare pointers
		Node* current = nullptr; //pointer to traverse the list
		Node* trailCurrent = nullptr; //pointer just before current

		bool found = false;

		if (head == nullptr)//Empty linked list case
			cout << "Cannot delete from empty linked list." << endl;
		else
		{
			current = head;

			//Search for value
			while (current != nullptr && !found)
			{
				if (current->data == searchVal)
					found = true;
				else
				{
					trailCurrent = current;
					current = current->next;
				}
				if (current == nullptr)//If item isn't found by end of list
					cout << "The item you wish to remove is not in the linked list." << endl;
				else
					if (current->data == searchVal)//If it is found
					{
						found = true;

						if (head == current)//If the item is the first in the list,
						{
							head = head->next;//Create a new 'first' in list

							if (head == nullptr)
								tail = nullptr;

							delete current;
						}
						else//Case 3
						{
							trailCurrent->next = current->next;
							if (tail == current)
                                tail = trailCurrent;

							delete current;
						}
						size--;
					}
			}
		}

	}

	void PopFront()
	{
		if (IsEmpty())//Case 1: List is Empty
			return;

		if (head == tail)
		{
			//Case 2: List has 1 node
			delete head;
			head = tail = nullptr;
		}
		else
		{
			//Case 3: list has multiple nodes
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		size--;
	}

	void PopBack()
	{
		if (IsEmpty())//Case 1: List is Empty
			return;

		if (head == tail)
		{
			//Case 2: List has 1 node
			delete head;
			head = tail = nullptr;
		}
		else//Case 3: List has multiple nodes
		{
			Node* temp = head;
			while (temp->next != tail)//loop until we find the 2nd to last node.
				temp = temp->next;

			temp->next = nullptr;
			delete tail;
			tail = temp;
		}
		size--;
	}

	int Size() const
	{
		return size;
	}

	bool IsEmpty() const
	{
		return head == nullptr;
		return size == 0;
	}

    //Iterate over string to find encapsulating characters. Push them to stack
    string CharacterMatch(string& str)
    {
        //Declare stack
        stack<char> charMatch;
        //Get size of soon to be char array
        auto size = str.length();
        //Declare character array
        char charArray[size];
        //Message to return to user
        string message;
        
        //Copy string into character array
        strcpy(charArray, str.c_str());
        
        //Iterate over characters and push to stack if appropriate character
        for(int i = 0; i < size; ++i)
        {
            if(charArray[i] == '{' || charArray[i] == '(' || charArray[i] == '[')
                charMatch.push(charArray[i]);
            if(charArray[i] == '}' && charMatch.top() != '{')
                message = "Missing or out of place '{}' character: " + str + " <- Here";
            else if(charArray[i] == ')' && charMatch.top() != '(')
                message = "Missing or out of place '()' character: " + str + " <- Here";
            else if(charArray[i] == ']' && charMatch.top() != ']')
                message = "Missing or out of place '[]' character: " + str + " <- Here";
            else
                message = "True: " + str;
        }
        
        return message;
    }

private:
	Node* head = nullptr;
	Node* tail = nullptr;
	int size = 0;
};
