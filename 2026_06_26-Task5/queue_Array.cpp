#include <iostream>
#include <string>

using namespace std;

class Queue {
public:
    string arr[100]; // Fixed size of 100
    int front; // Points to the first person in line
    int rear;  // Points to the next empty spot in the back

    Queue() {
        front = 0;
        rear = 0;
    }

    // 1. Add a person to the back of the line
    void enqueue(string name) {
        if (rear == 100) {
            cout << "The queue is full." << endl;
            return;
        }

        arr[rear] = name; // Put them in the empty spot
        rear++;           // Shift the empty spot back by one
    }

    // 2. Remove the person at the front of the line
    void dequeue() {
        if (front == rear) { // If front caught up to rear, the line is empty
            cout << "This queue is empty." << endl;
            return;
        }

        cout << arr[front] << " left the queue." << endl;
        front++; // The front of the line moves back one spot
        
        // Bonus cleanup: If the line is completely empty now, reset both to 0
        if (front == rear) {
            front = 0;
            rear = 0;
        }
    }

    // 3. Show everyone currently in line
    void display() {
        if (front == rear) {
            cout << "This queue is empty." << endl;
            return;
        }
        
        // Print from the front of the line to the back
        for (int i = front; i < rear; i++) {
            cout << arr[i];
            
            // Print a visual arrow between names (but not after the last name)
            if (i < rear - 1) {
                cout << " <- "; 
            }
        }
        cout << endl;
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

   cout << "\n--- Dequeue (Serve first person) ---" << endl;
   q.dequeue();

   cout << "\n--- Queue after Dequeue ---" << endl;
   q.display();

   return 0;
}