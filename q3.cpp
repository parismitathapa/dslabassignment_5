//student id:1024030309
//name:parismita thapa batch:2c22
//assignment 5 question 3 solution

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
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }

    int findMiddleTwoPointers() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return -1;
        }
        
        Node* slow = head;
        Node* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow->data;
    }

    int findMiddleByCount() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return -1;
        }

        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        int middle = count / 2;
        temp = head;
        for (int i = 0; i < middle; i++) {
            temp = temp->next;
        }
        
        return temp->data;
    }
};

int main() {
    LinkedList list;
    int n, value;
    
    cout << "FIND MIDDLE OF LINKED LIST" << endl;
    cout << "Sample: 1->2->3->4->5 => Middle: 3" << endl;
    cout << endl;
    
    cout << "Enter number of elements: ";
    cin >> n;
    
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        list.insert(value);
    }
    
    list.display();
    
    cout << "\nFinding middle using two methods:" << endl;
    
    int middle1 = list.findMiddleTwoPointers();
    cout << "Method 1 (Two Pointers): " << middle1 << endl;
    
    int middle2 = list.findMiddleByCount();
    cout << "Method 2 (Count and Traverse): " << middle2 << endl;
    
    return 0;
}
