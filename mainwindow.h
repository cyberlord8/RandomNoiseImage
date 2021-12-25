#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QDateTime>
#include <QFile>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonGenerate_clicked();
    void on_pushButtonSave_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QPixmap pixMap;
    QImage myImage;
    QRandomGenerator ranGen = QRandomGenerator::securelySeeded();

    void initializeApp();
    qint64 genRand(qint64 max);
    QRgb getRandomColor();
    QRgb getRandomGreyScale();
};
#endif // MAINWINDOW_H
