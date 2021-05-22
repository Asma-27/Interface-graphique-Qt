#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H
#include "dialog.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class firstwindow; }
QT_END_NAMESPACE

class firstwindow : public QMainWindow
{
    Q_OBJECT

public:
    Dialog *dlg;
    firstwindow(QWidget *parent = nullptr);
    ~firstwindow();

private slots:
    void on_essayer_clicked();

    void on_passer_clicked();

    void on_dimensions_clicked();

private:
    Ui::firstwindow *ui;
};
#endif // FIRSTWINDOW_H
