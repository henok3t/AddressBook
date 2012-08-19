#include "address.hpp"

Address::Address()
{
}

void Address::addField(fieldtype type, string value)
{
    Field temp;
    temp.type = type;
    temp.info = value;
    fields.put(temp);
}

bool Address::rmField(fieldtype type, string value)
{
   Field temp;
   temp.type = type;
}
