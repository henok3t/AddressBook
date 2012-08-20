#ifndef ADDRESS_HPP
#define ADDRESS_HPP

#include "linkedlist.h"
#include <string>

class Address
{
public:

    //----------------------------------------------------------------------------------------------------------------
    /// constructor
    //----------------------------------------------------------------------------------------------------------------
    Address();

    //----------------------------------------------------------------------------------------------------------------
    /// destructor
    //----------------------------------------------------------------------------------------------------------------
    ~Address();

    //----------------------------------------------------------------------------------------------------------------
    /// @brief
    /// add a field to address
    /// @param type
    /// the type of the field to add
    /// @param value
    /// the value of the field
    //----------------------------------------------------------------------------------------------------------------
    void addField(fieldtype type, string value);

    //----------------------------------------------------------------------------------------------------------------
    /// @brief
    /// removes the first occurance of the field
    /// @param type
    /// the type of the field to add
    /// @param value
    /// the value of the field
    /// @return
    /// returns true if deleted, false otherwise
    //----------------------------------------------------------------------------------------------------------------
    bool rmField(fieldtype type, string value);

    //----------------------------------------------------------------------------------------------------------------
    /// @brief
    /// finds the first occurance of the field
    /// @param type
    /// the type of the field to find
    /// @return
    /// returns true if found, false otherwise
    //----------------------------------------------------------------------------------------------------------------
    bool find(Field* fld, fieldtype type);

    //----------------------------------------------------------------------------------------------------------------
    /// @brief
    /// list of possible field types for address
    //----------------------------------------------------------------------------------------------------------------
    enum fieldtype {FIRSTNAME, LASTNAME, ADDRESS, PHONE, EMAIL, BIRTHDAY, ANNIVERSARY};

private:
    struct Field
    {
        fieldtype type;
        string info;

        bool operator>(Field f)
        {
            return ( (this->type) > f.type );
        }
    };

    LinkedList<Field> fields;

    friend class AddressList;
};

#endif // ADDRESS_HPP
