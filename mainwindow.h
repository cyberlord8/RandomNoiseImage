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
    /**
    * @brief on_pushButtonGenerate_clicked
    * @details Generates an image with random colored pixels*/
    void on_pushButtonGenerate_clicked();
    /**
     * @brief on_pushButtonSave_clicked
     * @details Saves image to a png file
     */
    void on_pushButtonSave_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QImage myImage;
    /**
     * @brief ranGen
     * @details Creates a cryptographically secure random number generator\n
     * using QRandomGenerator::system() and securely seeding it.
     */
    QRandomGenerator ranGen = QRandomGenerator::securelySeeded();

    /**
     * @brief initializeApp
     * @details Initializes the application, draws the initial image
     */
    void initializeApp();
    /**
     * @brief genRand
     * @param max max number to generate
     * @return qint64 random number
     * @details Generates a random number between 0 and max
     */
    qint64 genRand(qint64 max);
    /**
     * @brief getRandomColor
     * @return QRgb random color
     * @details Generates a Qrgb random color object
     */
    QRgb getRandomColor();
    /**
     * @brief getRandomGreyScale
     * @return Qrgb random grey color object
     * @details Generates a QRgb random grey object
     */
    QRgb getRandomGreyScale();
};
#endif // MAINWINDOW_H
