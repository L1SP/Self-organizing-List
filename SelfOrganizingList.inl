#pragma warning( disable : 4715 )
#include <iostream>
#include "SelfOrganizingList.h"
///////////////////////////SOL///////////////////////////
template <typename T>
SelfOrganizingList<T>::SelfOrganizingList() {
	head = nullptr;
}
template <typename T>
SelfOrganizingList<T>::~SelfOrganizingList() {
	clear();
}
template <typename T>
bool SelfOrganizingList<T>::isEmpty() const {
	return head == nullptr;
}
template <typename T>
int SelfOrganizingList<T>::findElemByVal(const T& val) {
	if (head) {
		if (head->data == val)
			return 0;
		int counter = 1;
		Node<T>* p = head;
		while (p && p->next) {
			if (p->next->data == val) {
				moveToHead(p);
				return counter;
			}
			++counter;
			p = p->next;
		}
	}
	return -1;
}
template <typename T>
void SelfOrganizingList<T>::addAfterNode(Node<T>* node, const T& val) {
	Node<T>* nn = new Node<T>;
	nn->data = val;
	nn->next = node->next;
	node->next = nn;
}
template <typename T>
void SelfOrganizingList<T>::addToHead(const T& val) {
	Node<T>* nn = new Node<T>;
	nn->data = val;
	nn->next = head;
	head = nn;
}
template <typename T>
void SelfOrganizingList<T>::deleteFromHead() {
	if (head) {
		Node<T>* p = head;
		head = head->next;
		delete p;
	}
}
template <typename T>
void SelfOrganizingList<T>::deleteAfterNode(Node<T>* node) {
	if (node->next) {
		Node<T>* p = node->next;
		node->next = node->next->next;
		delete p;
	}
}
template <typename T>
void SelfOrganizingList<T>::deleteNodesByValue(const T& val) {
	if (!isEmpty()) {
		while (head->data == val) {
			deleteFromHead();
		}
		Node<T>* p = head;
		while (p && p->next) {
			if (p->next->data == val) {
				deleteAfterNode(p);
			}
			p = p->next;
		}
	}	
}
template <typename T>
void SelfOrganizingList<T>::moveToHead(Node<T>* node) {
	if (node->next) {
		Node<T>* p = node->next;
		node->next = node->next->next;
		p->next = head;
		head = p;
	}
}
template <typename T>
bool SelfOrganizingList<T>::deleteNodeAt(const int& idx) {
	if (idx < 0)
		return 0;
	else if (idx == 0) {
		deleteFromHead();
		return 1;
	}
	else {
		int counter = 1;
		Node<T>* p = head;
		while (p && p->next) {
			if (counter == idx) {
				deleteAfterNode(p);
				return 1;
			}
			counter++;
			p = p->next;
		}
		return 0;
	}
}
template <typename T>
void SelfOrganizingList<T>::clear() {
	while (head) {
		deleteFromHead();
	}
}
template <typename T>
std::istream& operator>>(std::istream& in, SelfOrganizingList<T>& sol) {
	T val;
	in >> val;
	sol.addToHead(val);
	Node<T>* p = sol.head;
	while (in>>val) {
		sol.addAfterNode(p, val);
		p = p->next;
	}
	return in;
}
template <typename T>
std::ostream& operator<<(std::ostream& out, const SelfOrganizingList<T>& sol) {
	if (sol.head) {
		typename SelfOrganizingList<T>::Iterator it;
		for (it = sol.begin(); it != sol.end(); it++) {
			out << *it << " ";
		}
	}
	else
		out << "список пуст.";
	return out;
}
///////////////////////////Iterator///////////////////////////
template <typename T>
typename SelfOrganizingList<T>::Iterator& SelfOrganizingList<T>::Iterator::operator++() {
	if (currNode)
	{
		currNode = currNode->next;
		return *this;
	}
}
template <typename T>
typename SelfOrganizingList<T>::Iterator& SelfOrganizingList<T>::Iterator::operator++(int) {
	if (currNode)
	{
		Iterator* tmp = new Iterator(*this);
		currNode = currNode->next;
		return *tmp;
	}
}
template <typename T>
T& SelfOrganizingList<T>::Iterator::operator*() {
	if (currNode)
		return currNode->data;
}