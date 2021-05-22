#ifndef DIALOG_H
#define DIALOG_H
#include "dialog1.h"
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog1* dlg1;
    Dialog2* dlg2;
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_finir_clicked();

    void on_commencer_clicked();

    void on_buttonBox_accepted();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
