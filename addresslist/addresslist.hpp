#ifndef ADDRESSLIST_HPP
#define ADDRESSLIST_HPP

#include "linkedlist.hpp"

class AddressList
{
public:
    AddressList();

    ~AddressList();

    void fread(ifstream input);

    void fwrite(ofstream output);

private:
    struct address
    {
        string name;
        string add;
        string email;
        string phone;
        string birthday;
        string aniversary;
    };

    LinkedList<address> addressbook;
};

#endif // ADDRESSLIST_HPP
