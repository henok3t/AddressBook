#ifndef ADDRESSLIST_HPP
#define ADDRESSLIST_HPP

#include "linkedlist.hpp"
#include "address.hpp"

class AddressList
{
public:

    //----------------------------------------------------------------------------------------------------------------
    /// constructor
    //----------------------------------------------------------------------------------------------------------------
    AddressList();

    //----------------------------------------------------------------------------------------------------------------
    /// destructor
    //----------------------------------------------------------------------------------------------------------------
    ~AddressList();

    //----------------------------------------------------------------------------------------------------------------
    /// @brief
    /// adds an address from user through standard input
    //----------------------------------------------------------------------------------------------------------------
    void addAddress();

    //----------------------------------------------------------------------------------------------------------------
    /// @brief
    /// edits the specified address
    /// firstname and lastname is asked from user through standard input
    //----------------------------------------------------------------------------------------------------------------
    void editAddress();

    //----------------------------------------------------------------------------------------------------------------
    /// @brief
    /// deletes the specified address
    /// firstname and lastname is asked from user through standard input
    //----------------------------------------------------------------------------------------------------------------
    void delAddress();

    //----------------------------------------------------------------------------------------------------------------
    /// @brief
    /// generates birthday cards for today
    //----------------------------------------------------------------------------------------------------------------
    void genBcards();

    //----------------------------------------------------------------------------------------------------------------
    /// @brief
    /// generates aniversary cards for today
    //----------------------------------------------------------------------------------------------------------------
    void genAcards();

private:

    LinkedList<Address> addressbook;
};

#endif // ADDRESSLIST_HPP
/// constructor
//----------------------------------------------------------------------------------------------------------------
AddressList::AddressList()
{/// constructor
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

}

//----------------------------------------------------------------------------------------------------------------
/// destructor
//----------------------------------------------------------------------------------------------------------------
AddressList::~AddressList()
{
    addressbook.empty();
}
