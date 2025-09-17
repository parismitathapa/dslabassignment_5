//student id:1024030309
//name:parismita thapa batch:2c22
//assignment 5 question 1 solution

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

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        cout << val << " inserted at beginning" << endl;
    }

    void insertAtEnd(int val) {
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
        cout << val << " inserted at end" << endl;
    }

    void insertBefore(int val, int target) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        if (head->data == target) {
            insertAtBeginning(val);
            return;
        }
        
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != target) {
            temp = temp->next;
        }
        
        if (temp->next == nullptr) {
            cout << "Target " << target << " not found" << endl;
        } else {
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            cout << val << " inserted before " << target << endl;
        }
    }
    
    void insertAfter(int val, int target) {
        Node* temp = head;
        while (temp != nullptr && temp->data != target) {
            temp = temp->next;
        }
        
        if (temp == nullptr) {
            cout << "Target " << target << " not found" << endl;
        } else {
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            cout << val << " inserted after " << target << endl;
        }
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        Node* temp = head;
        head = head->next;
        cout << temp->data << " deleted from beginning" << endl;
        delete temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        if (head->next == nullptr) {
            cout << head->data << " deleted from end" << endl;
            delete head;
            head = nullptr;
            return;
        }
        
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        
        cout << temp->next->data << " deleted from end" << endl;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteSpecific(int val) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        if (head->data == val) {
            deleteFromBeginning();
            return;
        }
        
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val) {
            temp = temp->next;
        }
        
        if (temp->next == nullptr) {
            cout << "Node " << val << " not found" << endl;
        } else {
            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            cout << val << " deleted" << endl;
            delete nodeToDelete;
        }
    }
    
    void search(int val) {
        Node* temp = head;
        int position = 1;
        
        while (temp != nullptr) {
            if (temp->data == val) {
                cout << "Node " << val << " found at position " << position << endl;
                return;
            }
            temp = temp->next;
            position++;
        }
        
        cout << "Node " << val << " not found" << endl;
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
        cout << "NULL" << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int choice, value, target;
    
    do {
        cout << "\nSINGLY LINKED LIST OPERATIONS" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert Before a Value" << endl;
        cout << "4. Insert After a Value" << endl;
        cout << "5. Delete from Beginning" << endl;
        cout << "6. Delete from End" << endl;
        cout << "7. Delete Specific Node" << endl;
        cout << "8. Search Node" << endl;
        cout << "9. Display List" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter target value to insert before: ";
                cin >> target;
                list.insertBefore(value, target);
                break;
            case 4:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter target value to insert after: ";
                cin >> target;
                list.insertAfter(value, target);
                break;
            case 5:
                list.deleteFromBeginning();
                break;
            case 6:
                list.deleteFromEnd();
                break;
            case 7:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteSpecific(value);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;
            case 9:
                list.display();
                break;
            case 10:
                cout << "Exiting program" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 10);
    
    return 0;
}
