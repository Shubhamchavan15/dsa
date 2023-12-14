#include <iostream>
using namespace std;

class JobQueue {
private:
    static const int MAX_SIZE = 10; 
    int queue[MAX_SIZE];
    int front, rear;

public:
    JobQueue() {
        front = -1;
        rear = -1;
    }

 
    bool isEmpty() {
        return front == -1;
    }

   
    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    
    void enqueue(int job) {
        if (isFull()) {
            cout << "Queue is full. Cannot add more jobs." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }

        queue[rear] = job;
        cout << "Job " << job << " added to the queue." << endl;
    }

 
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No jobs to delete." << endl;
            return;
        }

        cout << "Job " << queue[front] << " deleted from the queue." << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Jobs in the queue: ";
        int i = front;
        do {
            cout << queue[i] << " ";
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        cout << endl;
    }
};

int main() {
    JobQueue jobQueue;
    int choice, job;

    do {
        cout << "\nJob Queue Menu:\n";
        cout << "1. Add Job\n";
        cout << "2. Delete Job\n";
        cout << "3. Display Jobs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the job number: ";
                cin >> job;
                jobQueue.enqueue(job);
                break;
            case 2:
                jobQueue.dequeue();
                break;
            case 3:
                jobQueue.display();
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
