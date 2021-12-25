#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::initializeApp()
{
    scene = new QGraphicsScene(this);
    int width = ui->lineEditWidth->text().toInt();
    int height = ui->lineEditHeight->text().toInt();
    myImage = QImage(width, height, QImage::Format_RGB32);
    on_pushButtonGenerate_clicked();
}//initializeApp

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initializeApp();
}//MainWindow

MainWindow::~MainWindow()
{
    delete ui;
}//MainWindow

void MainWindow::on_pushButtonGenerate_clicked()
{
    QRgb value=0;
    QPixmap pixMap;
    int width = ui->lineEditWidth->text().toInt();
    int height = ui->lineEditHeight->text().toInt();
    myImage = QImage(width, height, QImage::Format_RGB32);

    if(myImage.isNull())
    {
        qDebug() << "NULL Image!";
    }
    else {
        for(int x=0;x<myImage.width();x++){
            for(int y=0;y<myImage.height();y++){
                if(ui->radioButtonColor->isChecked())
                    value=getRandomColor();
                else if(ui->radioButtonGrey->isChecked())
                    value=getRandomGreyScale();
                myImage.setPixel(x,y,value);
            }
        }
        pixMap = QPixmap::fromImage(myImage);
        scene->addPixmap(pixMap);
        scene->setSceneRect(pixMap.rect());
        ui->graphicsView->setScene(scene);
    }
}//on_pushButtonGenerate_clicked

void MainWindow::on_pushButtonSave_clicked()
{
    myImage.save(QFileDialog::getSaveFileName(this, tr("Save File"),
                                              "keyFile",
                                              tr("Images (*.png)")), "PNG");
}//on_pushButtonSave_clicked

qint64 MainWindow::genRand(qint64 max)
{
    qint64 randValue = ranGen.bounded(max);
    return randValue;
}//genRand

QRgb MainWindow::getRandomColor()
{
    return QColor::fromRgb(ranGen.generate()).rgb();
}//getRandomColor

QRgb MainWindow::getRandomGreyScale()
{
    int randomInt = genRand(255);
    return qRgb(randomInt,
                randomInt,
                randomInt);
}//getRandomGreyScale


