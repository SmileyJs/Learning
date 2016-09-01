#include "contact.h"

Contact::Contact(QWidget *parent)
    : QWidget(parent)
    , email(NULL)
    , emailEdit(NULL)
    , address(NULL)
    , addressEdit(NULL)
    , postCode(NULL)
    , postCodeEdit(NULL)
    , mobilePhone(NULL)
    , mobilePhoneEdit(NULL)
    , telePhone(NULL)
    , telePhoneEdit(NULL)
{
    initContactInfo();
}

void
Contact::initContactInfo()
{

}
