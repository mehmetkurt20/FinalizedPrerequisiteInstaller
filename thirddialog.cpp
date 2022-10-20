#include "thirddialog.h"
#include "ui_thirddialog.h"
#include "thirddialog.h"
#include "secdialog.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QListWidget>
#include <filesystem>
#include <iostream>
#include <cassert>
#include <string>
#include <QApplication>

QString file_name;

SecDialog *secdw;


std::string getFileName(std::string filePath, bool withExtension = true, char seperator = '/')
{
    std::size_t dotPos = filePath.rfind('.');
    std::size_t sepPos = filePath.rfind(seperator);
    if(sepPos != std::string::npos)
    {
        return filePath.substr(sepPos + 1, filePath.size() - (withExtension || dotPos != std::string::npos ? 1 : dotPos) );
    }
    return "";
}

ThirdDialog::ThirdDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThirdDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Setup Installation Wizard");
    ui->pushButton->setEnabled(false);

}

ThirdDialog::~ThirdDialog()
{
    delete ui;
}

void ThirdDialog::on_pushButton_3_clicked()
{
   hide();
   secdw = new SecDialog(this);
   secdw -> show();
}

void ThirdDialog::on_pushButton_2_clicked()
{
    close();
}

void ThirdDialog::on_pushButton_5_clicked()
{
    QString file_name_in = QFileDialog::getExistingDirectory(this,"Browse a file",QDir::homePath());
    QMessageBox::information(this,"File selected!",file_name_in);
    ui->textEdit->setText(file_name_in);
    file_name = file_name_in;

}

void ThirdDialog::on_pushButton_4_clicked()
{



    // Get the number of files in the Releasex64
    QString pathcik = "Releasex64";
    QDir dir( pathcik );
    dir.setFilter( QDir::AllEntries | QDir::NoDotAndDotDot );
    int total_files = dir.count();
    //QString baba = QString::number(total_files);
    //ui->textEdit_2->setText(baba);


    std::vector<std::string> paths;
    std::string path = "Releasex64/";
    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        paths.push_back(entry.path().string());
    }
   QString slash = "/";
   QString outputpath = file_name + slash;



    for (int c = 0; c < total_files; c++){

          std::string h = paths[c];
          std::string extension = getFileName(h,false);
          QString qstr = QString::fromStdString(extension);
          QString outputpath2 = outputpath + qstr;
          QFile::copy(QString::fromStdString(h),outputpath2);

    };

    QDir dirr("Releasex64");
    for(const QString &filenamee : dir.entryList(QDir::Files)){

        ui->listWidget->addItem(filenamee);}

    QDir dirrr(outputpath);
    for (const QString &filenameee : dir.entryList(QDir::Files)){

        ui->listWidget_2->addItem(filenameee);}

    ui->pushButton->setEnabled(true);


  }

void ThirdDialog::on_pushButton_clicked()
{
    hide();
    zzfourth = new zfourthDialog(this);
    zzfourth -> show();



}
