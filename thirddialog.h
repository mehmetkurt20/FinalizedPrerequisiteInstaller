#ifndef THIRDDIALOG_H
#define THIRDDIALOG_H

#include <QDialog>
#include <zfourthdialog.h>

namespace Ui {
class ThirdDialog;
}

class ThirdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ThirdDialog(QWidget *parent = nullptr);
    ~ThirdDialog();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::ThirdDialog *ui;
    ThirdDialog *thirdDialog;
    std::vector<std::string> containerpath;
    zfourthDialog *zzfourth;

};

#endif // THIRDDIALOG_H
