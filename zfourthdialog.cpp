#include "zfourthdialog.h"
#include "qobjectdefs.h"
#include "ui_zfourthdialog.h"
#include "thirddialog.h"
#include <QFile>
#include <QtXml>
#include <QProgressBar>

ThirdDialog *thirddw;

std::string getFileName2(std::string filePath, bool withExtension = true, char seperator = '/')
{
    std::size_t dotPos = filePath.rfind('.');
    std::size_t sepPos = filePath.rfind(seperator);
    if(sepPos != std::string::npos)
    {
        return filePath.substr(sepPos + 1, filePath.size() - (withExtension || dotPos != std::string::npos ? 1 : dotPos) );
    }
    return "";
}

zfourthDialog::zfourthDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::zfourthDialog)
{
    ui->setupUi(this);

}

zfourthDialog::~zfourthDialog()
{

    delete ui;
}

void zfourthDialog::on_pushButton_clicked()
{

    QDomDocument xmlBOM5;
    QFile f5("ayardosyasi.xml");
    xmlBOM5.setContent(&f5);
    f5.close();
    QDomElement root3 = xmlBOM5.documentElement();
    QDomElement Parent3=root3.firstChild().toElement();
    QDomNodeList items4 = Parent3.elementsByTagName("releasex64fileid1");
    itemsnumber4 = items4.count();
    int lengthInner;

    for(int i =0;i< itemsnumber4;i++){

        auto node4 = items4.at(i);
        auto map4 = node4.attributes();
        lengthInner = map4.length();
        for(int j = 0; j< lengthInner; j++){
            auto mapItem4 = map4.item(j);
            auto attribute4 = mapItem4.toAttr();
            auto attributevalue4 = attribute4.value();

            std::string svse2;
            svse2 = attributevalue4.toStdString();
            container5.push_back(svse2);
            //stringArray[j] = string(attributevalue);
            //ArrayWithWords[j] = attributevalue;
            //QListWidgetItem *item4 = new QListWidgetItem(attributevalue4);
            //ui->listWidget->addItem(item4);

        }

}
    QString outputpath4 = "C:/Users/MehmetKurt/Desktop/";

    //QString slash4 = "/";
    //QString outputpath7 = outputpath4 + slash4;



    for(int y = 0;y<itemsnumber4; y++){

        std::string nobody = container5[y];
        std::string extension4 = getFileName2(nobody,false);
        QString qstr4 = QString::fromStdString(extension4);
        QString outputpath5 = outputpath4 + qstr4;
        //ui->textEdit->setText(outputpath5);
        QFile::copy(QString::fromStdString(nobody),outputpath5);
    }
    ui->progressBar->setValue(100);

}

void zfourthDialog::on_pushButton_2_clicked()
{
    QDomDocument xmlBOM4;
    QFile f4("ayardosyasi.xml");
    xmlBOM4.setContent(&f4);
    f4.close();
    QDomElement root3 = xmlBOM4.documentElement();
    QDomElement Parent3=root3.firstChild().toElement();
    QDomNodeList items4 = Parent3.elementsByTagName("releasex64fileid0");
    itemsnumber4 = items4.count();
    int lengthInner;

    for(int i =0;i< itemsnumber4;i++){

        auto node4 = items4.at(i);
        auto map4 = node4.attributes();
        lengthInner = map4.length();
        for(int j = 0; j< lengthInner; j++){
            auto mapItem4 = map4.item(j);
            auto attribute4 = mapItem4.toAttr();
            auto attributevalue4 = attribute4.value();

            std::string svse2;
            svse2 = attributevalue4.toStdString();
            container4.push_back(svse2);
            //stringArray[j] = string(attributevalue);
            //ArrayWithWords[j] = attributevalue;
            //QListWidgetItem *item4 = new QListWidgetItem(attributevalue4);
            //ui->listWidget->addItem(item4);


        }

}
    QString outputpath4 = "C:/Users/MehmetKurt/AppData/Roaming/Microsoft/Windows/Start Menu/Programs/Startup/";

    QString slash4 = "/";
    QString outputpath7 = outputpath4 + slash4;


    for(int y = 0;y<itemsnumber4; y++){

        std::string nobody = container4[y];
        std::string extension4 = getFileName2(nobody,false);
        QString qstr4 = QString::fromStdString(extension4);
        QString outputpath5 = outputpath4 + qstr4;
        //ui->textEdit->setText(outputpath5);
        QFile::copy(QString::fromStdString(nobody),outputpath5);

    }
    ui->progressBar_2->setValue(100);

}

void zfourthDialog::on_pushButton_3_clicked()
{
    close();
}


void zfourthDialog::on_pushButton_4_clicked()
{
    hide();
    thirddw = new ThirdDialog(this);
    thirddw -> show();
}

