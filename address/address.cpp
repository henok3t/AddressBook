#include "address.hpp"
#include <iostream>

using namespace std;


//----------------------------------------------------------------------------------------------------------------
/// constructor
//----------------------------------------------------------------------------------------------------------------
Address::Address()
{
}

//----------------------------------------------------------------------------------------------------------------
/// destructor
//----------------------------------------------------------------------------------------------------------------
Address::~Address()
{
    fields.empty();
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

//----------------------------------------------------------------------------------------------------------------
/// find
//----------------------------------------------------------------------------------------------------------------
bool Address::find(Field* fld, fieldtype type)
{
    //return value
    bool rc;

    Field tmp;
    fields.reset();
    while( fields.next(tmp) == true)
    {
        if(tmp.type == type)
        {
            rc = true;
            fld = &tmp;
            break;
        }
    }

    return rc;
}

//----------------------------------------------------------------------------------------------------------------
/// printA
//----------------------------------------------------------------------------------------------------------------
void Address::printB()
{
    Field fld;
    cout<<endl<<"Dear ";
    this->find(&fld, FIRSTNAME);
    cout<<fld.info<<" ";
    this->find(&fld, LASTNAME);
    cout<<fld.info<<","<<endl<<endl;
    cout<<"Hope your Birthday is really Wonderful and this coming year is the best yet!"<<endl;
    cout<<endl<<"Love, "<<endl<<endl<<"Henok "<<endl;
}



//----------------------------------------------------------------------------------------------------------------
/// printB
//----------------------------------------------------------------------------------------------------------------
void Address::printA()
{
    Field fld;
    cout<<endl<<"Dear ";
    this->find(&fld, FIRSTNAME);
    cout<<fld.info<<" ";
    this->find(&fld, LASTNAME);
    cout<<fld.info<<","<<endl<<endl;
    cout<<"Hope your Annivarsary is really Wonderful and this coming year is the best yet!"<<endl;
    cout<<endl<<"Love, "<<endl<<endl<<"Henok "<<endl;
}
