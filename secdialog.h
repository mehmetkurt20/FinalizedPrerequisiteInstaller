#ifndef SECDIALOG_H
#define SECDIALOG_H
#include <string>
#include <QDialog>
#include <thirddialog.h>

namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog(QWidget *parent = nullptr);
    ~SecDialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();



    void on_pushButton_4_clicked();

private:
    Ui::SecDialog *ui;
    int itemsnumber;
    //const char* exelinks[];
    void setupinitiator();
    //std::string stringArray[100];
    std::vector<std::string> container;
    ThirdDialog *thirdDialog;



};

#endif // SECDIALOG_H
