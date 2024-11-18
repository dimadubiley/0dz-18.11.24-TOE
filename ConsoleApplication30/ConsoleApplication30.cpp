#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
    Node* head;

    void clear()
    {
        while (head)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void copyFrom(const LinkedList& other)
    {
        if (!other.head)
        {
            head = nullptr;
            return;
        }

        head = new Node(other.head->data);
        Node* current = head;
        Node* otherCurrent = other.head->next;

        while (otherCurrent)
        {
            current->next = new Node(otherCurrent->data);
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
    }

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList()
    {
        clear();
    }

    LinkedList(const LinkedList& other) : head(nullptr)
    {
        copyFrom(other);
    }

    LinkedList& operator=(const LinkedList& other)
    {
        if (this == &other)
        {
            return *this;
        }

        clear();
        copyFrom(other);

        return *this;
    }

    void push_back(int value)
    {
        if (!head)
        {
            head = new Node(value);
            return;
        }
        Node* current = head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = new Node(value);
    }

    void print() const
    {
        Node* current = head;
        while (current)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr\n";
    }
};

int main()
{
    LinkedList list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    cout << "List 1: ";
    list1.print();

    LinkedList list2 = list1;
    cout << "List 2 after copy: ";
    list2.print();

    list2.push_back(4);
    cout << "List 2 after modification: ";
    list2.print();

    cout << "List 1 unchanged: ";
    list1.print();

    LinkedList list3;
    list3 = list1;
    cout << "List 3 after assignment: ";
    list3.print();

}
