#ifndef ReadDICOMSeriesQt_H
#define ReadDICOMSeriesQt_H

#include <QMainWindow>
#include <vtkSmartPointer.h>
#include <vtkImageViewer2.h>
#include <vtkDICOMImageReader.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>

namespace Ui {
    class ReadDICOMSeriesQt;
}

class ReadDICOMSeriesQt : public QMainWindow {
    Q_OBJECT

public:
    explicit ReadDICOMSeriesQt(QWidget *parent = 0);
    ~ReadDICOMSeriesQt();

private slots:
    void openDICOMFolder();
    void drawDICOMSeries(std::string folderDICOM);
    void on_buttonOpenFolder_clicked();
    void on_sliderSlices_sliderMoved(int posicion);

private:
    Ui::ReadDICOMSeriesQt *ui;
    vtkSmartPointer<vtkDICOMImageReader> reader;
    vtkSmartPointer<vtkImageViewer2> viewer;
    int minSlice;
    int maxSlice;
};

#endif // ReadDICOMSeriesQt_H
