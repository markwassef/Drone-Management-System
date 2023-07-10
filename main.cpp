#include <iostream>

using namespace std;

class Drone {
    int range;
    int weight;
    char type;

public:
    Drone() {
        this->range = 0;
        this->weight = 0;
        this->type = '\0';
    }

    void loadData() {
        cout << "Enter range: ";
        cin >> this->range;
        cout << "Enter payload weight: ";
        cin >> this->weight;
        cout << "Enter drone type: ";
        cin >> this->type;
    }

    void display() {
        cout << "Range: " << this->range << endl;
        cout << "Payload weight: " << this->weight << endl;
        cout << "Drone type: " << this->type;
    }
};

class Node {
public:
    Drone drone;
    Node* next;

    Node(Drone drone) {
        this->drone = drone;
        this->next = NULL;
    }
};

class LinkedDrones {
public:
    Node* head;

    LinkedDrones(Node* head) {
        this->head = head;
    }

    void insertDrone(Drone drone) {
        Node* newNode = new Node(drone);
        Node* itr = head;

        // Traverse the list to find the last node
        while (itr->next) {
            itr = itr->next;
        }

        // Insert the new node at the end
        itr->next = newNode;
    }

    void deleteAll() {
        while (this->head != NULL) {
            Node* temp = this->head;
            this->head = this->head->next;
            delete temp;
        }
    }

    void display() {
        Node* itr = this->head;

        if (!itr) {
            cout << "No drones available, sorry." << endl;
        }

        while (itr) {
            itr->drone.display();
            cout << endl;
            itr = itr->next;
        }
    }
};

int main() {
    Drone firstDrone;
    cout << "Enter the first drone. " << endl;

    // Load data for the first drone
    firstDrone.loadData();

    // Create the head node with the first drone
    Node* head = new Node(firstDrone);

    // Create the LinkedDrones object with the head node
    LinkedDrones linkedDrones(head);

    char choice;

    do {
        cout << "Drone Menu" << endl;
        cout << "A. Add a drone" << endl;
        cout << "B. Display all current drones" << endl;
        cout << "C. Deploy all current drones" << endl;
        cout << "D. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        Drone newDrone;

        switch (choice) {
            case 'A':
                // Load data for the new drone and insert it into the list
                newDrone.loadData();
                linkedDrones.insertDrone(newDrone);
                break;
            case 'B':
                // Display all drones in the list
                linkedDrones.display();
                break;
            case 'C':
                // Delete all drones from the list
                linkedDrones.deleteAll();
                break;
            case 'D':
                // Exit the program
                break;
            default:
                cout << "Please enter a valid choice" << endl;
                break;
        }
    } while (choice != 'D');

    return 0;
}