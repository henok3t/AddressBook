#include "addresslist.hpp"
#include "address.hpp"
#include <iostream>

using namespace std;

//----------------------------------------------------------------------------------------------------------------
/// constructor
//----------------------------------------------------------------------------------------------------------------
AddressList::AddressList()
{
}

//----------------------------------------------------------------------------------------------------------------
/// destructor
//----------------------------------------------------------------------------------------------------------------
AddressList::~AddressList()
{
    addressbook.empty();
}

//----------------------------------------------------------------------------------------------------------------
/// fread
//----------------------------------------------------------------------------------------------------------------
void AddressList::fread(ifstream input)
{
    //TODO
}

//----------------------------------------------------------------------------------------------------------------
/// fwrite
//----------------------------------------------------------------------------------------------------------------
void AddressList::fwrite(ofstream output)
{
    //TODO
}

//----------------------------------------------------------------------------------------------------------------
/// addAddress
//----------------------------------------------------------------------------------------------------------------
void AddressList::addAddress()
{
    string temp;
    Address* newadd = new Address;

    // get first name
    cout<<"Please enter first name: ";
    cin>>temp;
    Address.addField(Address::FIRSTNAME, temp);

    // get last name
    cout<<"Please enter last name: ";
    cin>>temp;
    Address.addField(Address::LASTNAME, temp);

    while(true)
    {
        char choice;
        cout<<"Please choose one of the following options (q to quit)."<<endl;
        cout<<"Enter Address -- 1"<<endl<<"Enter email -- 2"<<endl;
        cout<<"Enter Phone -- 3"<<endl<<"Enter Birthday -- 4"<<endl;
        cout<<"Enter Aniversary Date: "<<endl;
        cin>>choice;
        if(choice == 'q')
        {
            break;
        }
        int ichoice = int(choice) - 48; // convert to integer
        switch (ichoice + 1) // skip first and last name
        {
        case Address::ADDRESS:
            cout<<"Please enter address: "<<endl;
            getline(cin, temp);
            Address.addField(Address::ADDRESS, temp);
            break;
        case Address::EMAIL:
            cout<<"Please enter email: ";
            getline(cin, temp);
            Address.addField(Address::EMAIL, temp);
            break;
        case Address::PHONE:
            cout<<"Please enter phone number: ";
            getline(cin, temp);
            Address.addField(Address::PHONE, temp);
            break;
        case Address::BIRTHDAY:
            cout<<"Please enter Birthday (mm/dd/yyyy): ";
            getline(cin, temp);
            if(checkDay(temp))
            {
                Address.addField(Address::BIRTHDAY, temp);
            }
            else
            {
                cout<<"Wrong Date Format"<<endl;
            }
        case Address::ANNIVERSARY:
            cout<<"Please enter Anniversary date (mm/dd/yyyy): ";
            getline(cin, temp);
            if(checkDay(temp))
            {
                Address.addField(Address::ANNIVERSARY, temp);
            }
            else
            {
                cout<<"Wrong Date Format"<<endl;
            }
        }
    }

}

//----------------------------------------------------------------------------------------------------------------
/// editAddress
//----------------------------------------------------------------------------------------------------------------
void AddressList::editAddress(string firstname, string lastname)
{
    //TODO
}

//----------------------------------------------------------------------------------------------------------------
/// delAddress
//----------------------------------------------------------------------------------------------------------------
void AddressList::delAddress(string firstname, string lastname)
{
    //TODO
}

//----------------------------------------------------------------------------------------------------------------
/// genBcards
//----------------------------------------------------------------------------------------------------------------
void AddressList::genBcards()
{
    //TODO
}

//----------------------------------------------------------------------------------------------------------------
/// genAcards
//----------------------------------------------------------------------------------------------------------------
void AddressList::genAcards()
{
    //TODO
}
