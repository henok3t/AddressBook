#include "addresslist.hpp"
#include "address.hpp"
#include <ctype.h>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

//----------------------------------------------------------------------------------------------------------------
/// @brief
/// global function that checks the date format of mm/dd/yyyy
//----------------------------------------------------------------------------------------------------------------
bool checkDay(string date);


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
        cout<<"Enter Aniversary Date -- 5 "<<endl;
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
            cout<<"Please enter Birthday (mm/dd/yy): ";
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
    Address Addr;
    addressbook.reset();
    bool found = false;
    while( addressbook.next(Addr) == true)
    {
        // declare first and last name fields
        Address::Field fn, ln;

        // find firstname
        Addr.find(&fn, Address::FIRSTNAME);
        if(firstname.compare(fn.info) == 0)
        {
            Addr.find(&ln, Address::LASTNAME);
            if(lastname.compare(ln.info) == 0)
            {
                found = true;
                break;
            }
        }
    }
    if(found)
    {
        int choice;
        cout<<"Please choose what field you want to edit: "<<endl;
        cout<<"Address -- 1"<<endl<<"Email -- 2"<<endl;
        cout<<"Phone -- 3"<<endl<<"Birthday -- 4"<<endl;
        cout<<"Aniversary Date -- 5 "<<endl;
        cin>>choice;

        Address::Field fld;
        if( Addr.find(&fld, choice + 1) )
        {
            string input;
            cout<<"Please enter value of field: ";
            getline(cin, input);
            if( (fld.type == Address::BIRTHDAY) || (fld.type == Address::ANNIVERSARY))
            {
                if( checkDay(input) )
                {
                    fld.info = input;
                }
                else
                {
                    cout<<"Invalid Input"<<endl;
                }
            }
            else
            {
                fld.info = input;
            }
        }
    }
    else
    {
        cout<<"The name you entered was not found."<<endl;
    }
}

//----------------------------------------------------------------------------------------------------------------
/// delAddress
//----------------------------------------------------------------------------------------------------------------
void AddressList::delAddress(string firstname, string lastname)
{
    Address Addr;
    addressbook.reset();
    bool found = false;
    while( addressbook.next(Addr) == true)
    {
        // declare first and last name fields
        Address::Field fn, ln;

        // find firstname
        Addr.find(&fn, Address::FIRSTNAME);
        if(firstname.compare(fn.info) == 0)
        {
            Addr.find(&ln, Address::LASTNAME);
            if(lastname.compare(ln.info) == 0)
            {
                found = true;
                break;
            }
        }
    }
    if(found)
    {
        if ( addressbook.del(Addr) )
        {
            cout<<"Address Has Been Deleted !!"<<endl;
        }
        else
        {
            cout<<"Error While deleting"<<endl;
        }
    }
    else
    {
        cout<<"Could find person with that name."<<endl;
    }
}

//----------------------------------------------------------------------------------------------------------------
/// genBcards
//----------------------------------------------------------------------------------------------------------------
void AddressList::genBcards()
{
    char date[9];
    _strdate(date);
    string sdate = date;
    Address Addr;
    while(addressbook.next(Addr) == true)
    {
        Address::Field fld;
        if(Addr.find(&fld, Address::BIRTHDAY))
        {
            if(fld.info == sdate)
            {
                Addr.printB();
            }
        }
    }

}

//----------------------------------------------------------------------------------------------------------------
/// genAcards
//----------------------------------------------------------------------------------------------------------------
void AddressList::genAcards()
{
    char date[9];
    _strdate(date);
    string sdate = date;
    Address Addr;
    while(addressbook.next(Addr) == true)
    {
        Address::Field fld;
        if(Addr.find(&fld, Address::ANNIVERSARY))
        {
            if(fld.info == sdate)
            {
                Addr.printA();
            }
        }
    }
}

//----------------------------------------------------------------------------------------------------------------
/// checkDay
//----------------------------------------------------------------------------------------------------------------
bool checkDay(string date)
{
    //return value
    bool rv = true;

    for(int i=0; i<8; ++i)
    {
        if( (i != 2) && (i != 5) )
        {
            if( isdigit(date[i]) == 0 )
            {
                rv = false;
                break;
            }
        }
        else
        {
            if( date[i] != '/')
            {
                rv = false;
                break;
            }
        }
    }

    return rv;
}
