#ifndef ADDRESS_HPP
#define ADDRESS_HPP

#include "linkedlist.h"
#include <string>

class Address
{
public:
    Address();

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
    // returns true if deleted, false otherwise
    //----------------------------------------------------------------------------------------------------------------
    bool rmField(fieldtype type, string value);

    //----------------------------------------------------------------------------------------------------------------
    /// @brief
    /// list of possible field types for address
    //----------------------------------------------------------------------------------------------------------------
    enum fieldtype {NAME, ADDRESS, PHONE, EMAIL, BIRTHDAY, ANNIVERSARY};

private:
    struct Field
    {
        fieldtype type;
        string info;

        bool operator>(Field f)
        {
            return ( (this->type) > f.type);
        }
    };

    LinkedList<Field> fields;

};

#endif // ADDRESS_HPP
