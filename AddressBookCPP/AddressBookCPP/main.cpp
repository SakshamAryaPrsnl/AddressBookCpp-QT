#include "stdafx.h"
#include "addressbookcpp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    AddressBookCPP window;
    window.show();
    return app.exec();
}
