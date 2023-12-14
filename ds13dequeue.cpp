#include <iostream>
using namespace std;

class Deque {
private:
    static const int MAX_SIZE = 10; // Maximum size of the deque
    int deque[MAX_SIZE];
    int front, rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

    // Function to check if the deque is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to check if the deque is full
    bool isFull() {
        return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
    }

    // Function to add an element to the front of the deque
    void addFront(int element) {
        if (isFull()) {
            cout << "Deque is full. Cannot add more elements." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = MAX_SIZE - 1;
        } else {
            front--;
        }

        deque[front] = element;
        cout << "Element " << element << " added to the front of the deque." << endl;
    }

    // Function to add an element to the rear of the deque
    void addRear(int element) {
        if (isFull()) {
            cout << "Deque is full. Cannot add more elements." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == MAX_SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }

        deque[rear] = element;
        cout << "Element " << element << " added to the rear of the deque." << endl;
    }

    // Function to delete an element from the front of the deque
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. No elements to delete." << endl;
            return;
        }

        cout << "Element " << deque[front] << " deleted from the front of the deque." << endl;

        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX_SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    // Function to delete an element from the rear of the deque
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. No elements to delete." << endl;
            return;
        }

        cout << "Element " << deque[rear] << " deleted from the rear of the deque." << endl;

        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX_SIZE - 1;
        } else {
            rear--;
        }
    }

    // Function to display the elements in the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }

        cout << "Elements in the deque: ";
        int i = front;
        do {
            cout << deque[i] << " ";
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        cout << endl;
    }
};

int main() {
    Deque deque;
    int choice, element;

    do {
        cout << "\nDeque Menu:\n";
        cout << "1. Add to Front\n";
        cout << "2. Add to Rear\n";
        cout << "3. Delete from Front\n";
        cout << "4. Delete from Rear\n";
        cout << "5. Display Deque\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to add to the front: ";
                cin >> element;
                deque.addFront(element);
                break;
            case 2:
                cout << "Enter the element to add to the rear: ";
                cin >> element;
                deque.addRear(element);
                break;
            case 3:
                deque.deleteFront();
                break;
            case 4:
                deque.deleteRear();
                break;
            case 5:
                deque.display();
                break;
            case 6:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
