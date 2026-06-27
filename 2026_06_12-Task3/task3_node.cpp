#include <iostream>
#include <string>

using namespace std;

// Node represents one element in the linked list
class Node {
public: 
    string name;
    Node* next; // Pointer to the next node in the list

    // Constructor creates a new node
    Node(string n) {
        name = n;
        next = nullptr; // By default, it doesn't point to anything yet
    }
};

// LinkedList manages the nodes
class LinkedList {
public:
    Node* head; // Points to the very first node

    LinkedList() {
        head = nullptr; // Start with an empty list
    }

    // 1. Add a new node to the end of the list
    void insertEnd(string name) {
        Node* newNode = new Node(name);

        // If list is empty, make this the first node
        if (head == nullptr) {
            head = newNode;
            return;
        }

        // Otherwise, travel to the last node
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        
        // Link the last node to our new node
        current->next = newNode;
    }

    // 2. Insert a new name right after a specific existing name
    void insertAfter(string afterName, string newName) {
        Node* current = head;
        
        // Search for the node we want to insert after
        while (current != nullptr && current->name != afterName) {
            current = current->next;
        }

        // If we reached the end without finding the name
        if (current == nullptr) {
            cout << afterName << " not found." << endl;
            return;
        }

        // Create new node and fix the links
        Node* newNode = new Node(newName);
        newNode->next = current->next; 
        current->next = newNode;       
    }

    // 3. Delete a node by its name
    void deleteByName(string name) {
        if (head == nullptr) return; // List is empty

        // Case A: The node to delete is the first node (head)
        if (head->name == name) {
            Node* temp = head;
            head = head->next; // Move head to the second node
            delete temp;       // Delete the old first node
            return;
        }

        // Case B: The node to delete is somewhere in the middle or end
        Node* current = head;
        while (current->next != nullptr) {
            
            if (current->next->name == name) {
                Node* temp = current->next; 
                current->next = temp->next; // Skip over the deleted node
                delete temp; 
                return;
            }
            
            current = current->next;
        }
    }
    
    // 4. Print all names in the list
    void display() {
        Node* current = head;
        
        if (current == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        // Loop through and print with a visual arrow
        while (current != nullptr) {
            cout << current->name << " -> ";
            current = current->next;
        }
        cout << "nullptr\n"; // Shows the end of the list visually
    }
};

// --- MAIN PROGRAM ---

int main() {
    LinkedList list;

    // Build initial list
    list.insertEnd("Aimar");
    list.insertEnd("Anjana");
    list.insertEnd("Jessy");

    cout << "--- Initial list ---" << endl;
    list.display();

    // Insert Ali after Anjana
    list.insertAfter("Anjana", "Ali");

    // Insert Jane at the end
    list.insertEnd("Jane");

    // Delete Anjana
    list.deleteByName("Anjana"); 

    cout << "\n--- Final list ---" << endl;
    list.display();

    return 0;
}