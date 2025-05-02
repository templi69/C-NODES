#include <iostream>
using namespace std;

struct Node {
    int id;
    char name[50];
    Node* next;
};

// Function to input patients and return the head of the list
Node* inputPatients(int count, const char* type) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < count; i++) {
        Node* newNode = new Node();

        cout << "Enter ID for " << type << " patient " << i + 1 << ": ";
        cin >> newNode->id;

        cout << "Enter name for " << type << " patient " << i + 1 << ": ";
        cin.ignore(); // ignore leftover newline
        cin.getline(newNode->name, 50);

        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Function to print patients list
void printPatients(Node* head, const char* type) {
    cout << "\n" << type << " Patients:\n";
    Node* temp = head;
    while (temp != nullptr) {
        cout << "Patient ID: " << temp->id << ", Name: " << temp->name << endl;
        temp = temp->next;
    }
}

// Function to free memory
void freeList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int emergencyCount, normalCount;

    cout << "Enter number of EMERGENCY patients: ";
    cin >> emergencyCount;
    Node* emergencyHead = inputPatients(emergencyCount, "emergency");

    cout << "\nEnter number of NORMAL patients: ";
    cin >> normalCount;
    Node* normalHead = inputPatients(normalCount, "normal");

    // Print both lists
    printPatients(emergencyHead, "Emergency");
    printPatients(normalHead, "Normal");

    // Free memory
    freeList(emergencyHead);
    freeList(normalHead);

    return 0;
}