//student id:1024030309
//name:parismita thapa batch:2c22
//assignment 5 question 2 solution

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
            temp = temp->next;
        }
        cout << endl;
    }
    
    int countOccurrences(int key) {
        int count = 0;
        Node* temp = head;
        
        while (temp != nullptr) {
            if (temp->data == key) {
                count++;
            }
            temp = temp->next;
        }
        
        return count;
    }
    
    void deleteAllOccurrences(int key) {
        while (head != nullptr && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        
        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->next->data == key) {
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
    }
    
    void processKey(int key) {
        cout << "\nOriginal Linked List: ";
        display();
        
        int count = countOccurrences(key);
        cout << "Count of " << key << ": " << count << endl;
        
        deleteAllOccurrences(key);
        
        cout << "Updated Linked List: ";
        display();
    }
};

int main() {
    LinkedList list;
    int n, value, key;
    
    cout << "COUNT AND DELETE OCCURRENCES PROGRAM" << endl;
    cout << "Sample: 1->2->1->2->1->3->1, key=1 => Count:4, Result:2->2->3" << endl;
    cout << endl;
    
    cout << "Enter number of elements: ";
    cin >> n;
    
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        list.insert(value);
    }
    
    cout << "Enter key to count and delete: ";
    cin >> key;
    
    list.processKey(key);
    
    return 0;
}
