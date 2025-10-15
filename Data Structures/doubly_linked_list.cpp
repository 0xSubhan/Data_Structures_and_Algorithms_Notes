#include <string>
#include <string_view>
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* pre;
    Node* next;

    Node(int val)
        : data {val}
        , pre {nullptr}
        , next {nullptr}
    {
    }
};

Node* head = nullptr;

// Insert at front:
void insertAtFront(int val)
{
    Node* newNode = new Node(val);
    // Special Case if list is empty:
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    head->pre = newNode;
    newNode->next = head;
    head = newNode;
}
// Print List:
void printList()
{
    Node* temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << '\n';    
}
// Insert at end:
void insertAtEnd(int val)
{
    Node* newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node* temp1 = head;
    while (temp1->next != nullptr)
    {
        temp1 = temp1->next;
    }
    newNode->pre = temp1;
    temp1->next = newNode; 
} 
// Inserting Node at nth position:
void insertAtN(int val,int n)
{
    Node* newNode = new Node(val);
    if (n == 1)
    {
        newNode->next = head;
        if (head != nullptr)
        {
            head->pre = newNode;
        }
        head = newNode;
        
        return;
    }
    Node* current = head; 
    
    for (size_t i = 1; i < n - 1; i++)
    {
        current = current->next;
    }
    Node* afterN = current->next;
    current->next = newNode;
    newNode->pre = current;
    newNode->next = afterN;
    afterN->pre = newNode;
}
// Print list using Recursion:
void printList_recursion(Node* node = head)
{
    if (node == nullptr)
    {
        return;
    }
    
    cout << node->data << " ";
    printList_recursion(node->next);
}
// Printing Reverse Double Linked list using recursion:
void printReverse_recursion(Node* node = head)
{
    if (node == nullptr)
    {
        return;
    }
    printReverse_recursion(node->next);
    cout << node->data << " ";
}  
// Reversing double linked list using recursion:
void Reverse_list_recursion(Node* node = head)
{
    if (node->next == nullptr)
    {
        node->next = node->pre;
        node->pre = nullptr;
        head = node;
        return;
    }
    Reverse_list_recursion(node->next);
    Node* prevAddress = node->pre;
    node->pre = node->next;
    node->next = prevAddress;
}

int main() {

    insertAtFront(1);
    insertAtFront(2);
    insertAtFront(3);
    insertAtFront(4);
    insertAtFront(5);
    printList();

    // Inserting 15 to our list at the end:
    insertAtEnd(15);
    printList();

    // Implementing Insert at Nth position function:
        // Will be inserting 
    insertAtN(0,6);
    printList(); 
    
    // Printing using Recursion:
    cout << "Recursive Iteration:" << endl;
    printList_recursion();

    // Printing Reverse List Using Recursion:
    cout << "\nReverse Iteration:" << endl;
    printReverse_recursion();
    
    // Reverse the Double linked list using recursion:



    cout << endl;
    return 0;
}