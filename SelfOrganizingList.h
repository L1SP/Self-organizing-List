#pragma once
#include <iostream>
template <typename T>
struct Node {
    T data;
    Node* next;
};
template <typename T>
class SelfOrganizingList
{
    Node<T>* head;
    void addAfterNode(Node<T>* node, const T& val);
    void moveToHead(Node<T>* node);
    void deleteAfterNode(Node<T>* node);
public:
    SelfOrganizingList();
    ~SelfOrganizingList();
    bool isEmpty() const;
    void addToHead(const T& val);
    void deleteFromHead();
    void deleteNodesByValue(const T& val);
    bool deleteNodeAt(const int& idx);
    void clear();
    int findElemByVal(const T& val);
    template <typename T>
    friend std::istream& operator>>(std::istream& in, SelfOrganizingList<T>& sol);
    template <typename T>
    friend std::ostream& operator<<(std::ostream& out, const SelfOrganizingList<T>& sol);
    class Iterator
    {
        friend SelfOrganizingList<T>;
        Node<T>* currNode;
    public:
        Iterator() : currNode(nullptr) {};
        Iterator(Node<T>* p) : currNode(p) {};
        ~Iterator() {};
        Iterator& operator++();
        Iterator& operator++(int);
        Iterator& operator=(const Iterator& it) { currNode = it.currNode; return *this; }
        bool operator==(const Iterator& it) const { return currNode == it.currNode; }
        bool operator!=(const Iterator& it) const { return currNode != it.currNode; }
        T& operator*();
    };
    Iterator& begin() const { return *(new Iterator(head)); }
    Iterator& end() const { return *(new Iterator(nullptr)); }
};
#include "SelfOrganizingList.inl"
