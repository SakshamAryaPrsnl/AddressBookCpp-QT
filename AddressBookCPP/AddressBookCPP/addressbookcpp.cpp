#include "stdafx.h"
#include "addressbookcpp.h"
#include "adddialog.h"

AddressBookCPP::AddressBookCPP(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
}

AddressBookCPP::~AddressBookCPP()
{}

void AddressBookCPP::on_addButton_clicked()
{
    AddDialog dialog(this);

    if (dialog.exec()) {
        QString name = dialog.nameEdit->text();
        QString email = dialog.emailEdit ->text();

        if (!name.isEmpty() && !email.isEmpty()) {
            QListWidgetItem* item = new QListWidgetItem(name, ui.addressList);
            item->setData(Qt::UserRole, email);
            ui.addressList->setCurrentItem(item);
        }
    }
}

void AddressBookCPP::on_addressList_currentItemChanged()
{
    QListWidgetItem* curItem = ui.addressList->currentItem();

    if (curItem) {
        ui.nameLabel->setText("Name: " + curItem->text());
        ui.emailLabel->setText("Email: " + curItem->data(Qt::UserRole).toString());
    }
    else {
        ui.nameLabel->setText("<No item selected>");
        ui.emailLabel->clear();
    }
}

void AddressBookCPP::on_deleteButton_clicked()
{
    QListWidgetItem *curItem = ui.addressList->currentItem();

    if (curItem) {
        int row = ui.addressList->row(curItem);
        ui.addressList->takeItem(row);
        delete curItem;

        if (ui.addressList->count() > 0)
            ui.addressList->setCurrentRow(0);
        else
            on_addressList_currentItemChanged();
    }
}