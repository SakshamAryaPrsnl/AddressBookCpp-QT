#pragma once

#include <QtWidgets/QWidget>
#include "ui_addressbookcpp.h"

class AddressBookCPP : public QWidget
{
    Q_OBJECT

public:
    AddressBookCPP(QWidget *parent = nullptr);
    ~AddressBookCPP();

private:
    Ui::AddressBookCPPClass ui;

private slots:
    void on_addButton_clicked();
    void on_addressList_currentItemChanged();
    void on_deleteButton_clicked();

};

