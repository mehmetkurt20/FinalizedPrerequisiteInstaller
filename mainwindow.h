#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "secdialog.h"
#include <QtCore>
#include <QtGui>
#include <QtXml>
#include <QDebug>
#include <QFile>

class QLineEdit;
class QPushButton;

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:

    Ui::MainWindow *ui;
    QStandardItemModel *model;
    SecDialog *secDialog;
    QString Filename;


//    QLineEdit *line1;
//    QLineEdit *line2;
//    QLineEdit *line3;
//    QLineEdit *line4;

};
#endif // MAINWINDOW_H
