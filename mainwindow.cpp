#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QString>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QDebug>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/img/simsoftfoto.jfif");
    ui->labelpic->setPixmap(pix.scaled(200,400,Qt::KeepAspectRatio));
    this->setWindowTitle("Setup Installation Wizard");

    //Intro ve Yazilim Bilgisi XML Parsing İslemleri-->>

    QDomDocument xmlBOM;
    QFile f("ayardosyasi.xml");
    xmlBOM.setContent(&f);
    f.close();

    QDomElement root  = xmlBOM.documentElement();
    QDomElement Parent=root.firstChild().toElement();

    QString softwareintro = Parent.firstChildElement("software_intro_text").text();
    ui->textEdit_2->setText(softwareintro);

    QString Softwareinfotext = Parent.firstChildElement("software_info_text").text();
    ui->textEdit->setText(Softwareinfotext);

}

MainWindow::~MainWindow()

{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
//    SecDialog secdialog;
//    secdialog.setModal(true);
//    secdialog.exec();

      hide();
      secDialog = new SecDialog(this);
      secDialog -> show();
}

void MainWindow::on_pushButton_2_clicked()
{
    close();
}
