





#include <iostream>
using namespace std;

// Define a node structure
struct Node {
    int data;         // Data part
    Node* next;       // Pointer to the next node
};

int main() {
    // Create a new node manually
    Node* head = new Node();  // allocate memory for the node
    head->data = 10;          // assign data
    head->next = nullptr;     // this is the only node, so next is null
    // creating my node after first node
    // 
      
    Node* next = new Node();  // allocate memory for the node
    next->data = 11;          // assign data
    next->next = nullptr;     // this is the only node, so next is null
    // 
    // 
    head->next = next;
    // Print the value

    cout << "Data in the node: " << head->data << endl;
    cout << "Data in the node: " << head->next->data << endl;

    // Free memory
    delete head;

    return 0;
}