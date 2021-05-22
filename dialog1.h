#ifndef DIALOG1_H
#define DIALOG1_H
#include "dialog2.h"
#include <QDialog>

namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    Dialog2* dlg2;
    explicit Dialog1(QWidget *parent = nullptr);
    ~Dialog1();

private slots:
    void on_commencer_clicked();

    void on_finir_clicked();

    void on_buttonBox_accepted();

private:
    Ui::Dialog1 *ui;
};

#endif // DIALOG1_H
