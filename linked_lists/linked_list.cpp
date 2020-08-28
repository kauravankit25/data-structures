#include <bits/stdc++.h>
using namespace std;


class node {
public:
	int data;
	node* next;

	node(int value) {
		data = value;
		next = NULL;
	}
};


class LinkedList {
private:
	node* head;
	node* tail;
	int length;

public:

	LinkedList() {

		head = NULL;
		tail = NULL;
		length = 0;
	}

	void append(int value) {

		node *newNode = new node(value);

		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		length++;
	}

	void display() {

		node *current = head;
		while (current != NULL) {
			cout << current->data << " ";
			current = current->next;
		}
	}


	node* findNode(int index) {

		node *current = head;
		int count = 0;
		while (count < index) {

			current = current->next;
			count++;
		}
		return current;
	}


	void prepend(int value) {

		node *newNode = new node(value);
		newNode->next = head;
		head = newNode;
		length++;
	}


	void insert(int index, int value) {

		if (index > length)
			append(value);

		else if (index <= 0)
			prepend(value);

		else {
			node *newNode = new node(value);
			node *leader = findNode(index - 1);

			newNode->next = leader->next;
			leader->next = newNode;
			length++;
		}

	}


	void remove(int index) {

		if (index >= length) {
			index = length;
		}

		if (index <= 0) {
			head = head->next;
			length--;
		}
		else {
			node *leader = findNode(index - 1);
			leader->next = leader->next->next;
			length--;
		}
	}

	int size() {
		return length;
	}

	node* begin() {
		return head;
	}


	node* end() {
		return tail;
	}
};

int main()
{
	LinkedList arr;

	arr.append(5);
	arr.append(10);
	arr.append(16);

	arr.insert(2, 99);
	arr.insert(20, 17);
	arr.insert(0, 22);
	arr.display();
	cout << endl << arr.findNode(4)->data << endl;
	arr.remove(0);
	arr.display();
	cout << endl << arr.size();

	cout << endl << arr.begin()->data << " " << arr.end()->data;
	return 0;
}