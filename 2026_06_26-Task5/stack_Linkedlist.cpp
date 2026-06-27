#include <iostream>
#include <string>

using namespace std;

// Node represents one item in the stack
class Node {
public: 
    string name;
    Node* next; // Pointer to the item below this one
    
    Node(string n) {
        name = n; 
        next = nullptr; 
    }
};

// Stack manages the tower of nodes
class Stack {
public:
    Node* top; // Points to the very top item in the stack

    Stack() {
        top = nullptr; // Start with an empty stack
    }

    // 1. Add an item to the top of the stack
    void push(string name) {
        Node* newNode = new Node(name);
        
        // The new node is placed on top, so it points DOWN to the old top
        newNode->next = top; 
        
        // Update the top pointer to look at this new node
        top = newNode; 
    }

    // 2. Remove the top item from the stack
    void pop() {
        if (top == nullptr) {
            cout << "The stack is empty." << endl;
            return; // CRITICAL FIX: You must return here so the code below doesn't crash!
        }
        
        // Save the top node temporarily so we can delete it later
        Node* temp = top; 
        
        // Move the top pointer down to the next node in the stack
        top = top->next; 
        
        cout << temp->name << " was popped off the stack." << endl;
        delete temp; // Free up the memory
    }

    // 3. Display the stack visually from top to bottom
    void display() {
        if (top == nullptr) {
            cout << "The stack is empty." << endl;
            return;
        }

        Node* current = top;
        
        cout << "--- TOP ---" << endl;
        while (current != nullptr) {
            cout << "  " << current->name << endl;
            current = current->next;
        }
        cout << "--- BOTTOM ---\n" << endl;
    }
};

// --- MAIN PROGRAM ---

int main() {
   Stack s;

   s.push("Aimar");
   s.push("Ahmad");
   s.push("Anjana");

   cout << "Current Stack:" << endl;
   s.display();

   cout << "Action: Popping the top element...\n" << endl;
   s.pop();

   cout << "\nStack after pop:" << endl;
   s.display();
   
   return 0;
}