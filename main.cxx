#include <QApplication>
#include "ReadDICOMSeriesQt.h"

int main(int argc, char** argv) {
    QApplication a(argc, argv);
    ReadDICOMSeriesQt w;
    w.show();

    return a.exec();
}
