#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Contact
{
    string name;
    long long int phone_number;
    string email;
    Contact *next;
    Contact *prev;
};

class ContactBook
{
private:

    Contact *head;

public:
    ContactBook();
    void createContact();
    void displayContacts();
    int searchContact();
    int deleteContactBySearch();
    void bubbleSortContacts();
    int editContact();
    void menu();
};

ContactBook::ContactBook()
{
    head = nullptr;
}

void ContactBook::createContact()
{
    Contact *newContact = new Contact;
    cout << "Name of Contact: ";
    cin >> newContact->name;
    cout << "Phone Number: ";
    cin >> newContact->phone_number;
    cout << "Email Address: ";
    cin >> newContact->email;
    newContact->next = nullptr;

    if (head == nullptr)
    {
        newContact->prev = nullptr;
        head = newContact;
    }
    else
    {
        Contact *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newContact;
        newContact->prev = temp;
    }
    cout << "Contact Added" << endl;
}

void ContactBook::displayContacts()
{
    if (head == nullptr)
    {
        cout << "No Contacts... Please Add Some Contacts" << endl;
        cout << "Thanks" << endl;
        return;
    }

    bubbleSortContacts();

    Contact *temp = head;
    int count = 0;

    cout << "Name:       Number:      Email:\n"
         << endl;
    while (temp != nullptr)
    {
        count++;
        cout << temp->name << "   " << temp->phone_number << "   " << temp->email << endl;
        temp = temp->next;
    }
    cout << "Total contacts: " << count << endl;
}

int ContactBook::searchContact()
{
    if (head == nullptr)
    {
        cout << "No Contacts to Search" << endl;
        return 0;
    }

    Contact *temp = head;
    string query;
    long long int numberQuery;

    cout << "1. Search By Name" << endl;
    cout << "2. Search By Number" << endl;
    int command;
    cout << "Enter the Command: ";
    cin >> command;

    if (command == 1)
    {
        cout << "Enter the Name to Search: ";
        cin >> query;
        while (temp != nullptr)
        {
            if (temp->name == query)
            {
                cout << "Name: " << temp->name << endl;
                cout << "Phone Number: " << temp->phone_number << endl;
                return 1;
            }
            temp = temp->next;
        }
    }
    else if (command == 2)
    {
        cout << "Enter the Number to Search: ";
        cin >> numberQuery;
        while (temp != nullptr)
        {
            if (temp->phone_number == numberQuery)
            {
                cout << "Name: " << temp->name << endl;
                cout << "Phone Number: " << temp->phone_number << endl;
                return 1;
            }
            temp = temp->next;
        }
    }
    else
    {
        cout << "Invalid command" << endl;
    }
    cout << "Contact Not Found" << endl;
    return 0;
}


int ContactBook::deleteContactBySearch()
{
    if (head == nullptr)
    {
        cout << "No Contacts to Delete" << endl;
        return 0;
    }

    Contact *temp = head;
    string query;
    long long int numberQuery;

    cout << "1. Delete By Name" << endl;
    cout << "2. Delete By Number" << endl;
    int command;
    cout << "Enter the Command: ";
    cin >> command;

    if (command == 1)
    {
        cout << "Enter the Name to Delete: ";
        cin >> query;
        while (temp != nullptr)
        {
            if (temp->name == query)
            {
                cout << "Name: " << temp->name << endl;
                cout << "Phone Number: " << temp->phone_number << endl;
                cout << "Press 1 to Delete the Contact: ";
                int deleteCommand;
                cin >> deleteCommand;
                if (deleteCommand == 1)
                {
                    if (temp->prev != nullptr)
                    {
                        temp->prev->next = temp->next;
                    }
                    else
                    {
                        head = temp->next;
                    }
                    if (temp->next != nullptr)
                    {
                        temp->next->prev = temp->prev;
                    }
                    delete temp;
                    cout << "Contact Deleted Successfully" << endl;
                    return 1;
                }
            }
            temp = temp->next;
        }
    }
    else if (command == 2)
    {
        cout << "Enter the Number to Delete: ";
        cin >> numberQuery;
        while (temp != nullptr)
        {
            if (temp->phone_number == numberQuery)
            {
                cout << "Name: " << temp->name << endl;
                cout << "Phone Number: " << temp->phone_number << endl;
                cout << "Press 1 to Delete the Contact: ";
                int deleteCommand;
                cin >> deleteCommand;
                if (deleteCommand == 1)
                {
                    if (temp->prev != nullptr)
                    {
                        temp->prev->next = temp->next;
                    }
                    else
                    {
                        head = temp->next;
                    }
                    if (temp->next != nullptr)
                    {
                        temp->next->prev = temp->prev;
                    }
                    delete temp;
                    cout << "Contact Deleted Successfully" << endl;
                    return 1;
                }
            }
            temp = temp->next;
        }
    }
    else
    {
        cout << "Invalid command" << endl;
    }
    cout << "Contact Not Found" << endl;
    return 0;
}

void ContactBook::bubbleSortContacts()
{
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }

    Contact *i, *j;
    string tempName;
    long long int tempNumber;

    for (i = head; i->next != nullptr; i = i->next)
    {
        for (j = i->next; j != nullptr; j = j->next)
        {
            if (i->name > j->name)
            {
                tempName = i->name;
                i->name = j->name;
                j->name = tempName;

                tempNumber = i->phone_number;
                i->phone_number = j->phone_number;
                j->phone_number = tempNumber;
            }
        }
    }
}

int ContactBook::editContact()
{
    if (head == nullptr)
    {
        cout << "No Contacts to Edit" << endl;
        return 0;
    }

    Contact *temp = head;
    string query;
    long long int numberQuery;

    cout << "1. Edit Name" << endl;
    cout << "2. Edit Phone Number" << endl;
    int command;
    cout << "Enter the Command: ";
    cin >> command;

    bool found = false;

    if (command == 1)
    {
        cout << "Enter the Name to Edit: ";
        cin >> query;

        while (temp != nullptr)
        {
            if (temp->name == query)
            {
                found = true;
                break;
            }
            temp = temp->next;
        }
    }
    else if (command == 2)
    {
        cout << "Enter the Number to Edit: ";
        cin >> numberQuery;

        while (temp != nullptr)
        {
            if (temp->phone_number == numberQuery)
            {
                found = true;
                break;
            }
            temp = temp->next;
        }
    }
    else
    {
        cout << "Invalid command" << endl;
        return 0;
    }

    if (found)
    {
        cout << "Name: " << temp->name << endl;
        cout << "Phone Number: " << temp->phone_number << endl;
        cout << "Press 1 to Edit the Contact: ";
        int editCommand;
        cin >> editCommand;

        if (editCommand == 1)
        {
            if (command == 1)
            {
                cout << "Enter New Name: ";
                cin >> temp->name;
            }
            else if (command == 2)
            {
                cout << "Enter New Phone Number: ";
                cin >> temp->phone_number;
            }
            cout << "Contact Edited Successfully" << endl;
            return 1;
        }
    }

    cout << "Contact Not Found" << endl;
    return 0;
}

void ContactBook::menu()
{
    int command;
    do
    {
        cout << "*************" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Update Contact" << endl;
        cout << "3. Delete Contact" << endl;
        cout << "4. Search Contact" << endl;
        cout << "5. Display All Contacts" << endl;
        cout << "6. Exit" << endl;
        cout << "*************" << endl;
        cout << "Enter the Command: ";
        cin >> command;

        switch (command)
        {
        case 1:
            createContact();
            break;
        case 2:
            editContact();
            break;
        case 3:
            deleteContactBySearch();
            break;
        case 4:
            searchContact();
            break;
        case 5:
            displayContacts();
            break;
        case 6:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid command" << endl;
        }
    } while (command != 6);
}

int main()
{
    ContactBook contactBook;

    string name;
    cout << "What is Your Name: ";
    cin >> name;
    cout << "*************" << endl;
    cout << name << "  WELCOME TO CONTACTBOOK" << endl;
    cout << "*************" << endl;

    contactBook.menu();

    return 0;
}
