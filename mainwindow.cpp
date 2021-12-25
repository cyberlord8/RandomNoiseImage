#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::initializeApp()
{
    //create a new qgraphicsscene
    scene = new QGraphicsScene(this);
    //generate and display the random image
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
    //get width and height of image
    int width = ui->lineEditWidth->text().toInt();
    int height = ui->lineEditHeight->text().toInt();
    //create image of specified size
    myImage = QImage(width, height, QImage::Format_RGB32);

    if(myImage.isNull())
    {
        qDebug() << "NULL Image!";
    }//if we have a bad image dont do anything
    else {
        for(int x=0;x<myImage.width();x++){
            for(int y=0;y<myImage.height();y++){
                if(ui->radioButtonColor->isChecked()){
                    //get random color
                    value=getRandomColor();
                }//if color
                else if(ui->radioButtonGrey->isChecked()){
                    //get random grey
                    value=getRandomGreyScale();
                }//else if grey
                myImage.setPixel(x,y,value);
            }//for every y pixel
        }//for every x pixel
        //create pixmap from image
        pixMap = QPixmap::fromImage(myImage);
        //add pixmap to scene
        scene->addPixmap(pixMap);
        //set the scene size to match size
        scene->setSceneRect(pixMap.rect());
        //display scene in graphicsview
        ui->graphicsView->setScene(scene);
    }//else we have a valid image
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
    //grescale is done differently, all rgb values must be the same
    int randomInt = genRand(255);
    return qRgb(randomInt,
                randomInt,
                randomInt);
}//getRandomGreyScale


