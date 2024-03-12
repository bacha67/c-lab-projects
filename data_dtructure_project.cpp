/*this is the program that calculate the utility of water by accepting
the name , address, previous reading and current reading from users and 
dispaly the utility payment of users and save informations to file */ 
#include <iostream>
#include <fstream>

using namespace std;

// Define a structure for storing payer information
struct Payer {
    string name;
    
    string address;
    
    int previousReading;
    
    int currentReading;
    
    double utilityPayment;
    
    Payer *next;
};

// Function to save payer information to a file
void savePayerInfo(Payer *head) {
    ofstream file("payer_info.txt");
    Payer *current = head;
    while (current != NULL) {
        file << "Name: " << current->name << endl;
        file << "Address: " << current->address << endl;
        
        file << "Previous Reading: " << current->previousReading << endl;
        
        file << "Current Reading: " << current->currentReading << endl;
        file << "Utility Payment: " << current->utilityPayment << endl;
        file << endl;
        current = current->next;
    }
    file.close();
}

int main() {
    Payer *head = NULL;
    int choice;

    do {
        Payer *newPayer = new Payer;

        cout << "Enter name of the payer: "<<endl;
        cin >> newPayer->name;

        cout << "Enter address of the payer: "<<endl;
        cin >> newPayer->address;

        cout << "Enter previous reading: "<<endl;
        cin >> newPayer->previousReading;

        cout << "Enter current reading: "<<endl;
        cin >> newPayer->currentReading;

        // Calculate utility payment
        newPayer->utilityPayment = (newPayer->currentReading - newPayer->previousReading) * 0.15;
        cout<<" utility payment of\t" <<newPayer->name<< "\tis $"<<newPayer->utilityPayment<<endl;

        // Add new payer to the linked list
        newPayer->next = head;
        head = newPayer;

        cout << "Do you want to add another payer?\n 1. to add another \n 0. to end "<<endl;
        cin >> choice;

    } 
	 while (choice != 0);

    // Save payer information to a file
    
	savePayerInfo(head);

    return 0;
}
