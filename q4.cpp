//student id:1024030309
//name:parismita thapa batch:2c22
//assignment 5 question 4 solution

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }
    
    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << "->";
            else cout << "->NULL";
            temp = temp->next;
        }
        cout << endl;
    }
 
    void reverseIterative() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        
        while (current != nullptr) {
            next = current->next;  
            current->next = prev;  
            prev = current;        
            current = next;        
        }
        
        head = prev;  
    }

    Node* reverseRecursiveHelper(Node* node) {
        if (node == nullptr || node->next == nullptr) {
            return node;
        }

        Node* newHead = reverseRecursiveHelper(node->next);

        node->next->next = node;
        node->next = nullptr;
        
        return newHead;
    }
    
    void reverseRecursive() {
        head = reverseRecursiveHelper(head);
    }
    LinkedList copy() {
        LinkedList newList;
        Node* temp = head;
        while (temp != nullptr) {
            newList.insert(temp->data);
            temp = temp->next;
        }
        return newList;
    }
};

int main() {
    LinkedList list;
    int n, value;
    
    cout << "REVERSE LINKED LIST PROGRAM" << endl;
    cout << "Sample: 1->2->3->4->NULL => 4->3->2->1->NULL" << endl;
    cout << endl;
    
    cout << "Enter number of elements: ";
    cin >> n;
    
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        list.insert(value);
    }
    
    cout << "\nOriginal List: ";
    list.display();

    LinkedList list1 = list.copy();
    list1.reverseIterative();
    cout << "Reversed (Iterative): ";
    list1.display();

    LinkedList list2 = list.copy();
    list2.reverseRecursive();
    cout << "Reversed (Recursive): ";
    list2.display();
    
    return 0;
}
