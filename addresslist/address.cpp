#include "address.hpp"

Address::Address()
{
}

//----------------------------------------------------------------------------------------------------------------
/// addField
//----------------------------------------------------------------------------------------------------------------
void Address::addField(fieldtype type, string value)
{
    Field temp;
    temp.type = type;
    temp.info = value;
    fields.put(temp);
}

//----------------------------------------------------------------------------------------------------------------
/// rmField
//----------------------------------------------------------------------------------------------------------------
bool Address::rmField(fieldtype type, string value)
{
   Field temp;
   temp.type = type;
   temp.info = value;
   fields.del(temp);
}
