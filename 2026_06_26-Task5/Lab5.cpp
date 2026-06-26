#include <iostream>
#include <string>

using namespace std;


class Node {
public:
    string name;
    Node* next;

    Node(string n) {
        name = n;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(string name) {
        Node* newNode = new Node(name);
        newNode->next = top;
        top = newNode;       
        cout << name << " pushed to stack." << endl;
    }


    void pop() {
        if (top == NULL) {
            cout << "Stack is empty! Nothing to pop." << endl;
            return;
        }
        Node* temp = top;    
        top = top->next;    
        cout << temp->name << " popped from stack." << endl;
        delete temp;      
    }

  
    void display_list() {
        if (top == NULL) {
            cout << "Stack is empty!" << endl;
            return;
        }
        
        Node* display_node = top;
        cout << "\n--- Current Stack (Top to Bottom) ---" << endl;
        while (display_node != NULL) {
            cout << display_node->name << endl;
            display_node = display_node->next;
        }
        cout << "-----------------------------------" << endl;
    }
};

int main() {
    Stack myStack;

    myStack.push("Aiman");
    myStack.push("Ahmad");
    myStack.push("Anjana");
    myStack.push("Jessy");
    myStack.push("Ali");


    myStack.display_list();

    
    cout << "\nLet's remove the top element:" << endl;
    myStack.pop();

    myStack.display_list();

    return 0;
}