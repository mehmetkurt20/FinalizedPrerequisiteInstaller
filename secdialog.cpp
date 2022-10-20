#include "secdialog.h"
#include "ui_secdialog.h"
#include "mainwindow.h"
#include <QtXml>
#include <QFile>
#include <QString>
#include <QListWidget>
#include <QTextEdit>
#include <QProcess>
#include <fstream>
#include <iostream>
using namespace std;

MainWindow *mainw;
SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Setup Installation Wizard");

    QDomDocument xmlBOM3;
    QFile f3("ayardosyasi.xml");
    xmlBOM3.setContent(&f3);
    f3.close();
    QDomElement root3 = xmlBOM3.documentElement();
    QDomElement Parent3=root3.firstChild().toElement();
    QDomNodeList items = Parent3.elementsByTagName("software_text");
    itemsnumber = items.count();
    int lengthInner;

    for(int i =0;i< itemsnumber;i++){
        QDomNode itemnode = items.at(i);

        if(itemnode.isElement()){
            QString Softwaretext3;
            Softwaretext3 = itemnode.firstChild().toText().data();
            QListWidgetItem *item = new QListWidgetItem(Softwaretext3);
            ui->listWidget->addItem(item);
        }

        auto node = items.at(i);
        auto map = node.attributes();
        lengthInner = map.length();
        for(int j = 0; j< lengthInner; j++){
            auto mapItem = map.item(j);
            auto attribute = mapItem.toAttr();
            auto attributevalue = attribute.value();

            std::string svse;
            svse = attributevalue.toStdString();
            container.push_back(svse);
            QListWidgetItem *item2 = new QListWidgetItem(attributevalue);
            ui->listWidget_2->addItem(item2);
        }
}

}

SecDialog::~SecDialog()
{
    delete ui;
}

void SecDialog::on_pushButton_2_clicked()
{
    close();
}

void SecDialog::on_pushButton_3_clicked()
{
  hide();
  mainw = new MainWindow(this);
  mainw->show();
}

void SecDialog::on_pushButton_clicked() // This is, installation button
{
    std::ofstream myfile;
    myfile.open("installationbashfile.bat");
    for(int a=0;a<itemsnumber;a++){
    std::string s = container[a];
    char b = s.back();

    if (b == 'i'){
    myfile <<"msiexec /i \""<< container[a]<<"\" /qn /norestart"<< endl;
   }
    else if (b == 'e'){
    myfile <<"\""<< container[a]<<"\" /S /norestart"<< endl;
  }
    else{
        break;
    }

   //myfile <<"msiexec /i \""<< container[a]<<"\" /qn /norestart"<< endl;
}

    myfile.close();
    WinExec("installationbashfile.bat",SW_HIDE);
}

void SecDialog::on_pushButton_4_clicked()
{
    hide();
    thirdDialog = new ThirdDialog(this);
    thirdDialog -> show();
}

//Comments
//        std::vector<std::string> ArrayWithWords(10);
//        size_t d = 5; // something between 0 and 9

//        std::string word;
//        ArrayWithWords[i] = word;
//        d++;

    //Programs exe will be started in sequence.

/*
    QDomDocument xmlBOM4;
    //Load xml file as raw data
    QFile f("C:/Users/MehmetKurt/Desktop/XMLs/prerequi.xml");

    //Set data into the QDomDocument before processing
    xmlBOM4.setContent(&f);
    f.close();

    QDomElement root4 = xmlBOM4.documentElement();
    QDomElement parent4 = root4.firstChild().toElement();
    QDomElement child4 = parent4.firstChild().toElement();
    while(child4.isNull()== false){
        for(int g=0;g<itemsnumber;g++){
            QDomNodeList start = xmlBOM3.elementsByTagName("software_text");
            int length = start.length();
            int lengthInner;
            for (int i = 0; i < length; i++)
            {
                auto node = start.at(i);
                auto map = node.attributes();

                lengthInner = map.length();
                for (int j = 0; j < lengthInner; j++)
                {
                    auto mapItem = map.item(j);
                    auto attribute = mapItem.toAttr();
                    QString wff = attribute.value();

                    QListWidgetItem *item = new QListWidgetItem(wff);
                    ui->listWidget->addItem(item);
          }
//            QDomNode attributenode = attributes.at
//            QString exepath = child4.attribute("exe");
//            exepath = child4.firstChild().toText().data();
//            exelinks[0] = exepath.toLatin1();
    }
  }
}
    //WinExec("C:/Users/MehmetKurt/Desktop/setupexes/directx_Jun2010_redist",SW_HIDE);
    //std::string baba = container[0];
    //QProcess *process = new QProcess(this);
    //system(baba);
    //QProcess *pro = new QProcess;
    //QString qs = QString::fromStdString(s);
    //pro->start(qs);
    // if(s.back() == "\i"){
    //    myfile <<container[a]<<" /qn /norestart"<< endl;
    // }
    //  if(s.back()== "\e")
*/
