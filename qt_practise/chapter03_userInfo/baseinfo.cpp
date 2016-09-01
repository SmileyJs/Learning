#include "baseinfo.h"

#include <QTextEdit>
#include <QLabel>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>

BaseInfo::BaseInfo(QWidget *parent)
    : QWidget(parent)
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

void
BaseInfo::initUserInfo()
{
    // Left layout.
    userName = new QLabel("user name: ");
    userNameEdit = new QTextEdit;

    name = new QLabel("name: ");
    nameEdit = new QTextEdit;

    sex = new QLabel("sex: ");
    sexBox = new QComboBox;
    sexBox->addItem("male");
    sexBox->addItem("female");

    department = new QLabel("department: ");
    departmentEdit = new QTextEdit;

    age = new QLabel("age: ");
    ageEdit = new QTextEdit;

    remark = new QLabel("remark: ");
    remark->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    leftLayout = new QGridLayout;

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
    headIcon = new QLabel;
    QPixmap icon("P24_MAP_2100.png");
    headIcon->setPixmap(icon);
    headIcon->resize(icon.width(), icon.height());
    updateButton = new QPushButton("update");

    topRightLayout = new QHBoxLayout;
    topRightLayout->setSpacing(20);
    topRightLayout->addWidget(head);
    topRightLayout->addWidget(headIcon);
    topRightLayout->addWidget(updateButton);

    description = new QLabel("Personal Description");
    descriptionEdit = new QTextEdit;

    rightLayout = new QVBoxLayout;
    rightLayout->setMargin(10);
    rightLayout->addLayout(topRightLayout);
    rightLayout->addWidget(description);
    rightLayout->addWidget(descriptionEdit);

    // Bottom layout
    okButton = new QPushButton("OK");
    cancleButton = new QPushButton("Cancle");

    bottomLayout = new QHBoxLayout;
    bottomLayout->addStretch();
    bottomLayout->addWidget(okButton);
    bottomLayout->addWidget(cancleButton);

    // Main layout
    mainLayout = new QGridLayout(this);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    mainLayout->addLayout(leftLayout, 0, 0);
    mainLayout->addLayout(rightLayout, 0 ,1);
    mainLayout->addLayout(bottomLayout, 1, 0, 1, 2);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
}
