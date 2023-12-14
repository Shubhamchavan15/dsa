#include <iostream>
using namespace std;

class PizzaParlor {
private:
    static const int MAX_ORDERS = 5; 
    int circularQueue[MAX_ORDERS];
    int front, rear;

public:
    PizzaParlor() {
        front = -1;
        rear = -1;
    }

    
    bool isEmpty() {
        return front == -1;
    }

    
    bool isFull() {
        return (front == 0 && rear == MAX_ORDERS - 1) || (front == rear + 1);
    }

  
    void enqueue(int order) {
        if (isFull()) {
            cout << "Pizza parlor is full. Cannot accept more orders at the moment." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_ORDERS;
        }

        circularQueue[rear] = order;
        cout << "Order " << order << " placed successfully." << endl;
    }

   
    void dequeue() {
        if (isEmpty()) {
            cout << "No orders to serve. Pizza parlor is currently empty." << endl;
            return;
        }

        cout << "Order " << circularQueue[front] << " served." << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_ORDERS;
        }
    }

    
    void displayOrders() {
        if (isEmpty()) {
            cout << "No orders in the queue. Pizza parlor is currently empty." << endl;
            return;
        }

        cout << "Current Orders in the Queue: ";
        int i = front;
        do {
            cout << circularQueue[i] << " ";
            i = (i + 1) % MAX_ORDERS;
        } while (i != (rear + 1) % MAX_ORDERS);
        cout << endl;
    }
};

int main() {
    PizzaParlor pizzaParlor;
    int choice, order;

    do {
        cout << "\nPizza Parlor Menu:\n";
        cout << "1. Place an Order\n";
        cout << "2. Serve an Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the order number: ";
                cin >> order;
                pizzaParlor.enqueue(order);
                break;
            case 2:
                pizzaParlor.dequeue();
                break;
            case 3:
                pizzaParlor.displayOrders();
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
