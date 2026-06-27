#include <iostream>
#include <string>

using namespace std;

class Stack {
public:
    string arr[100]; // Fixed size of 100
    int top;         // Tracks the index of the highest item

    Stack() {
        top = -1; // -1 means the stack is completely empty
    }

    // 1. Add an item to the top of the stack
    void push(string name) {
        if (top == 99) {
            cout << "The stack is full." << endl;
            return;
        }

        top++;           // Move the top pointer up by one
        arr[top] = name; // Place the new name in that spot
    }

    // 2. Remove the top item from the stack
    void pop() {
        if (top == -1) {
            cout << "The stack is empty." << endl;
            return;
        }

        cout << arr[top] << " was popped off the stack." << endl;
        
        // We don't need to actually delete the string in the array. 
        // Just moving the top pointer down tells the computer to ignore it!
        top--; 
    }

    // 3. Display the stack visually from top to bottom
    void display() {
        if (top == -1) {
            cout << "The stack is empty." << endl;
            return;
        }

        // Print a visual representation of a stack
        cout << "--- TOP ---" << endl;
        for (int i = top; i >= 0; i--) {
            cout << "  " << arr[i] << endl;        
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