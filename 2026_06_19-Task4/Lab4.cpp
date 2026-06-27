#include <iostream>
#include <string>

using namespace std;

class Node {
public: 
    string name;
    Node* next; 
    Node* prev;

    Node(string n) {
        name = n; 
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList {
public:
    Node* head; 

    LinkedList() {
        head = nullptr; 
    }

    // 1. Insert at the end of the circular list
    void insertEnd(string name) { 
        Node* newNode = new Node(name);

        // If list is empty, the first node points to itself in both directions
        if (head == nullptr) {
            head = newNode;
            head->next = head;  
            head->prev = head;
            return;
        }

        // In a circular list, the node right before the head is always the tail!
        Node* tail = head->prev;  

        // 4-way connection: connect the old tail and head to the new node
        tail->next = newNode;     // old tail goes forward to new node
        newNode->prev = tail;     // new node goes backward to old tail
        newNode->next = head;     // new node goes forward to head
        head->prev = newNode;     // head goes backward to new node
    }

    // 2. Insert after a specific name
    void insertAfter(string afterName, string newName) {
        if (head == nullptr) return;

        Node* current = head;
        
        // Loop through the circle to find the name
        do {
            if (current->name == afterName) {
                Node* newNode = new Node(newName);
                Node* nextNode = current->next; // The node currently sitting after "current"

                // Insert newNode exactly between current and nextNode
                current->next = newNode;
                newNode->prev = current;
                
                newNode->next = nextNode;
                nextNode->prev = newNode;
                
                return;
            }
            current = current->next;
        } while (current != head); // Stop if we make a full circle

        cout << afterName << " not found." << endl;
    }

    // 3. Delete a node by name
    void deleteByName(string name) {
        if (head == nullptr) return;

        Node* current = head;

        do {
            if (current->name == name) {
                
                // Case A: It's the only node in the entire list
                if (current->next == current) {
                    head = nullptr;
                } 
                // Case B: There are multiple nodes
                else {
                    // Link the left node directly to the right node, skipping "current"
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    
                    // If we happen to be deleting the head, shift the head label over
                    if (current == head) {
                        head = current->next;
                    }
                }
                
                delete current; // Free the memory
                return;
            }
            current = current->next;
        } while (current != head);

        cout << name << " not found." << endl;
    }
    
    // 4. Display the list forward
    void display() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->name << " <-> ";
            current = current->next;
        } while (current != head);
        
        cout << "(back to " << head->name << ")" << endl; 
    }

    // 5. Display the list backward
    void displayReverse() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* tail = head->prev; // Start at the end
        Node* current = tail;
        
        do {
            cout << current->name << " <-> ";
            current = current->prev; // Move backward
        } while (current != tail);
        
        cout << "(back to " << tail->name << ")" << endl;
    }
};

// --- MAIN PROGRAM ---

int main() {
    LinkedList list;

    list.insertEnd("Aimar");
    list.insertEnd("Anjana");
    list.insertEnd("Jessy");

    cout << "--- Initial list ---" << endl;
    list.display();

    cout << "\n--- After inserting Ali after Anjana ---" << endl;
    list.insertAfter("Anjana", "Ali");
    list.display();

    cout << "\n--- After inserting Jane at the end ---" << endl;
    list.insertEnd("Jane");
    list.display();    

    cout << "\n--- After deleting Jessy ---" << endl;
    list.deleteByName("Jessy");
    list.display();

    cout << "\n--- Reverse linked list ---" << endl;
    list.displayReverse();

    return 0;
}