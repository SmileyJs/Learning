#include "dialog.h"

#include <QTextEdit>
#include <QLabel>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , userName(NULL)
    , userNameEdit(NULL)
    , name(NULL)
    , nameEdit(NULL)
    , sex(NULL)
    , sexBox(NULL)
    , department(NULL)
    , departmentEdit(NULL)
    , age(NULL)
    , ageEdit(NULL)
    , remark(NULL)
    , leftLayout(NULL)
    , head(NULL)
    , headIcon(NULL)
    , updateButton(NULL)
    , description(NULL)
    , descriptionEdit(NULL)
    , rightLayout(NULL)
    , mainLayout(NULL)
{
    initUserInfo();
}

Dialog::~Dialog()
{

}

void
Dialog::initUserInfo()
{
    // Left layout.
    userName = new QLabel("user name: ", this);
    userNameEdit = new QTextEdit(this);

    name = new QLabel("name: ", this);
    nameEdit = new QTextEdit(this);

    sex = new QLabel("sex: ", this);
    sexBox = new QComboBox(this);
    sexBox->addItem("male");
    sexBox->addItem("female");

    department = new QLabel("department: ", this);
    departmentEdit = new QTextEdit(this);

    age = new QLabel("age: ");
    ageEdit = new QTextEdit(this);

    remark = new QLabel("remark", this);
    remark->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    leftLayout = new QGridLayout();

    leftLayout->addWidget(userName, 0, 0);
    leftLayout->addWidget(userNameEdit, 0, 1);

    leftLayout->addWidget(name, 1, 0);
    leftLayout->addWidget(nameEdit, 1, 1);

    leftLayout->addWidget(sex, 2, 0);
    leftLayout->addWidget(sexBox, 2, 1);

    leftLayout->addWidget(department, 3, 0);
    leftLayout->addWidget(departmentEdit, 3, 1);

    leftLayout->addWidget(age, 4, 0);
    leftLayout->addWidget(ageEdit, 4, 1);

    leftLayout->setColumnStretch(0, 1);
    leftLayout->setColumnStretch(1, 3);

    leftLayout->addWidget(remark, 5, 0, 1, 2);

    // Right layout
    head = new QLabel("portrait");
    headIcon = new QLabel(this);
    updateButton = new QPushButton("update", this);

    description = new QLabel("Personal Description", this);
    descriptionEdit = new QTextEdit(this);

    rightLayout = new QVBoxLayout();

    rightLayout->addWidget(head);
    rightLayout->addWidget(headIcon);
    rightLayout->addWidget(updateButton);
    rightLayout->addWidget(description);
    rightLayout->addWidget(descriptionEdit);

    // Main layout
    mainLayout = new QGridLayout(this);
    mainLayout->addLayout(leftLayout, 0, 0);
    mainLayout->addLayout(rightLayout, 0 ,1);
}
