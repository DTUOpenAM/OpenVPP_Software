#include <QApplication>
#include <QMessageBox>
#include "mainwindow.h"
#include "../../../common/dln_generic.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DLN_RESULT result = DlnConnect("localhost", DLN_DEFAULT_SERVER_PORT);
    if (!DLN_SUCCEEDED(result))
    {
        QMessageBox::warning(NULL, QObject::tr("DLN Server Connection Error"),
                             QObject::tr("Failed to connect to local DLN server."));
        return -1;
    }

    MainWindow w;
    w.show();

    int exitCode = a.exec();
    DlnDisconnectAll();
    return exitCode;
}
