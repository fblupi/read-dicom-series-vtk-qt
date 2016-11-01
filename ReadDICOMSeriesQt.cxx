#include "ReadDICOMSeriesQt.h"
#include "ui_ReadDICOMSeriesQt.h"

#include <QFileDialog>

ReadDICOMSeriesQt::ReadDICOMSeriesQt(QWidget *parent) : QMainWindow(parent), ui(new Ui::ReadDICOMSeriesQt) {
    ui->setupUi(this);
    reader = vtkSmartPointer<vtkDICOMImageReader>::New();
    viewer = vtkSmartPointer<vtkImageViewer2>::New();
}

ReadDICOMSeriesQt::~ReadDICOMSeriesQt() {
    delete ui;
}

void ReadDICOMSeriesQt::openDICOMFolder() {
    QString folderNameDICOM = QFileDialog::getExistingDirectory(this, tr("Open DICOM Folder"), QDir::currentPath(), QFileDialog::ShowDirsOnly);
    drawDICOMSeries(folderNameDICOM.toUtf8().constData());
}

void ReadDICOMSeriesQt::drawDICOMSeries(std::string folderDICOM) {
    // Asigna carpeta de donde obtener las imágenes DICOM
    reader->SetDirectoryName(folderDICOM.c_str());
    reader->Update();

    // Enlaza el input del viewer al output del reader
    viewer->SetInputConnection(reader->GetOutputPort());

    // Enlaza el widget con el viewer
    ui->qvtkWidget->SetRenderWindow(viewer->GetRenderWindow());

    // Añade interactor al viewer
    viewer->SetupInteractor(ui->qvtkWidget->GetInteractor());

    // Inicializa
    viewer->Render();

    // Obtiene el número de slices
    minSlice = viewer->GetSliceMin();
    maxSlice = viewer->GetSliceMax();

    // Actualiza labels de la GUI
    ui->sliderSlices->setMinimum(minSlice);
    ui->sliderSlices->setMaximum(maxSlice);
    ui->labelSlicesNumber->setText(QString::number(maxSlice - minSlice));
    ui->labelFolderName->setText(QString::fromStdString(folderDICOM));
}

void ReadDICOMSeriesQt::on_buttonOpenFolder_clicked() {
    openDICOMFolder();
}

void ReadDICOMSeriesQt::on_sliderSlices_sliderMoved(int position) {
    viewer->SetSlice(position);
    viewer->Render();
}
