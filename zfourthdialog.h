#ifndef ZFOURTHDIALOG_H
#define ZFOURTHDIALOG_H

#include <QDialog>
#include <QListWidget>
namespace Ui {
class zfourthDialog;
}

class zfourthDialog : public QDialog
{
    Q_OBJECT

public:
    explicit zfourthDialog(QWidget *parent = nullptr);
    ~zfourthDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::zfourthDialog *ui;
    int itemsnumber4;
    std::vector<std::string> container4;
    std::vector<std::string> container5;
};

#endif // ZFOURTHDIALOG_H
