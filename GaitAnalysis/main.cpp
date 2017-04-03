#include "tabdialog.h"


#include <QApplication>
#include <QMainWindow>
#include <QtDataVisualization>
using namespace QtDataVisualization;

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>




int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


        TabDialog tabdialog;


        tabdialog.show();



      return app.exec();
}




