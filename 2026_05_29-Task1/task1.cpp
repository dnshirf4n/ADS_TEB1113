#include <iostream>
#include <string>

using namespace std;

// Structure to store student information
struct Student {
    int id;
    string name;
    string course;
    int age;
};

int main() {
    Student students[5];

    cout << "--- Enter Details for 5 Students ---\n";
    for (int i = 0; i < 5; i++) {
        cout << "\nStudent " << i + 1 << "\n";
        
        cout << "ID: ";
        cin >> students[i].id;
        
        cin.ignore(); 

        cout << "Name: ";
        getline(cin, students[i].name);

        cout << "Course: ";
        getline(cin, students[i].course);

        cout << "Age: ";
        cin >> students[i].age;
    }

    cout << "\n--- All Students ---\n";
    for (int i = 0; i < 5; i++) {
        cout << "ID: " << students[i].id 
             << " | Name: " << students[i].name 
             << " | Course: " << students[i].course 
             << " | Age: " << students[i].age << "\n";
    }

    cout << "\n--- Search for a Student ---\n";
    int searchID;
    cout << "Enter ID to search: ";
    cin >> searchID;

    bool found = false;
    for (int i = 0; i < 5; i++) {
        if (students[i].id == searchID) {
            cout << "Student Found! Name: " << students[i].name << "\n";
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "Student not found.\n";
    }

    cout << "\n--- Update Student Records ---\n";
    while (true) {
        int updateID;
        
        cout << "\nEnter ID to update (or type 0 to quit): ";
        cin >> updateID;

        if (updateID == 0) {
            cout << "Exiting program. Goodbye!\n";
            break;
        }
        
        int studentIndex = -1;
        for (int i = 0; i < 5; i++) {
            if (students[i].id == updateID) {
                studentIndex = i; // Save where we found them
                break;
            }
        }

        if (studentIndex == -1) {
            cout << "Student not found.\n";
            continue; 
        }

        // Ask what to change
        string change;
        cout << "What to change? (id/name/course/age): ";
        cin >> change;
        
        cin.ignore(); // Clear the buffer before getting new input

        if (change == "id") {
            cout << "Enter new ID: ";
            cin >> students[studentIndex].id;
            cout << "ID updated!\n";
        } 
        else if (change == "name") {
            cout << "Enter new name: ";
            getline(cin, students[studentIndex].name);
            cout << "Name updated!\n";
        } 
        else if (change == "course") {
            cout << "Enter new course: ";
            getline(cin, students[studentIndex].course);
            cout << "Course updated!\n";
        } 
        else if (change == "age") {
            cout << "Enter new age: ";
            cin >> students[studentIndex].age;
            cout << "Age updated!\n";
        } 
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}