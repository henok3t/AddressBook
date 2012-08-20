#include <iostream>
#include "addresslist.hpp"

using namespace std;

//----------------------------------------------------------------------------------------------------------------
/// @brief
/// prints menu
//----------------------------------------------------------------------------------------------------------------
void printMenu();

//----------------------------------------------------------------------------------------------------------------
/// @brief
/// prints menu and takes appropriate action
//----------------------------------------------------------------------------------------------------------------
int main(void)
{
    AddressList addresses;
    int choice;
    printMenu();
    cin>>choice;
    while(choice != 6)
    {
        switch (choice)
        {
        case 1:
            addresses.addAddress();
            break;
        case 2:
            addresses.delAddress();
            break;
        case 3:
            addresses.editAddress();
            break;
        case 4:
            addresses.genBcards();
            break;
        case 5:
            addresses.genAcards();
            break;
        default:
            cout<<"invalid input";
            break;
        }
        printMenu();
        cin>>choice;
    }
}

//----------------------------------------------------------------------------------------------------------------
/// printMenu
//----------------------------------------------------------------------------------------------------------------
void printMenu()
{
    cout<<"Menu"<<endl;
    cout<<"1. Enter a new name into the address book"<<endl;
    cout<<"2. Delete a name from the address book"<<endl;
    cout<<"3. Change a name or date in the address book"<<endl;
    cout<<"4. Generate birthday cards"<<endl;
    cout<<"5. Generate Anniversary cards"<<endl;
    cout<<"6. Exit the card program"<<endl;
    cout<<"Please select from menu: ";
}
