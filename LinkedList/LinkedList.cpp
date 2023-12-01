#include <iostream>

// Node class to represent individual elements in the linked list
class Node {
    public:
        int data;
        Node* next;
    public:
        // constructor
        Node(int value) 
            : data(value), next(nullptr) {}
};

// LinkedList class to manage the linked list operations
class LinkedList {
    private:
        Node* head;
    public:
        // constructor
        LinkedList();
        // Destructor to free the allocated memory
        ~LinkedList();
        // Function to display the elements of the linked list
        void display();
        // Function to add a new node to the end of the list
        void append(int value);
};

int main(int argc, char const *argv[])
{
    /* code */
    // Create a linked list and add elements
    LinkedList myList;
    myList.append(100);
    myList.append(20);
    myList.append(300);
    myList.append(30);
    myList.append(500);

    // Display the linked list
    std::cout << "Linked List: ";
    myList.display();

    std::cout << std::endl;
    return 0;
}

LinkedList::LinkedList() : head(nullptr) {}
LinkedList::~LinkedList() {
    Node* current = head;
    while(current != nullptr) {
        current = current->next;
        delete head;
        head = current;
    }
}

void LinkedList::display() {
    Node* current = head;
    while(current->next != nullptr) {
        std::cout << current->data << ", ";
        current = current->next;
    }
    std::cout << current->data 
                << std::endl;
}

void LinkedList::append(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }
    
    Node* current = head;
    while(current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}