#include <iostream>
#include <string>

using namespace std;

// Node represents one person in the queue
class Node {
public: 
    string name;
    Node* next; // Pointer to the person behind them in line
    
    Node(string n) {
        name = n; 
        next = nullptr; // When a person joins, no one is behind them yet
    }
};

// Queue manages the line of nodes
class Queue {
public:
    Node* front; // Points to the first person in line
    Node* rear;  // Points to the last person in line

    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // 1. Add a person to the back of the line
    void enqueue(string name) {
        Node* newNode = new Node(name);

        // If the queue is empty, this person is both the front and the rear
        if (rear == nullptr) {
            front = newNode;
            rear = newNode;
            return;
        }

        // Otherwise, link the current last person to the new person
        rear->next = newNode; 
        
        // Update the rear pointer to point to this new last person
        rear = newNode; 
    }

    // 2. Remove the person at the front of the line
    void dequeue() {
        if (front == nullptr) {
            cout << "This queue is empty." << endl;
            return;
        }

        // Temporarily store the person at the front so we can delete them from memory later
        Node* temp = front;
        
        // Move the front of the line to the next person
        front = front->next; 

        cout << temp->name << " has left the queue." << endl;
        delete temp; // Free up the memory

        // If moving the front caused the queue to become completely empty, 
        // we must also reset the rear pointer to nullptr.
        if (front == nullptr) {
            rear = nullptr; 
        } 
    }

    // 3. Display everyone in the queue visually
    void display() {
        if (front == nullptr) {
            cout << "The queue is empty." << endl;
            return;
        }

        Node* current = front;
        cout << "[Front] ";
        
        // Loop through the line and print arrows between people
        while (current != nullptr) {
            cout << current->name;
            if (current->next != nullptr) {
                cout << " -> ";
            }
            current = current->next;
        }
        
        cout << " [Rear]" << endl;
    }
};

// --- MAIN PROGRAM ---

int main() {
   Queue q;

   q.enqueue("Aimar");
   q.enqueue("Ahmad");
   q.enqueue("Anjana");

   cout << "--- Current Queue ---" << endl;
   q.display();

   cout << "\n--- Dequeue (Serve the front person) ---" << endl;
   q.dequeue();

   cout << "\n--- Queue after Dequeue ---" << endl;
   q.display();
   
   return 0;
}