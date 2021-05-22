#include "firstwindow.h"
#include "ui_firstwindow.h"
#include <QCheckBox>
#include<QGraphicsGridLayout>
#include <QGridLayout>
#include <vector>
#include <QSpinBox>
#include <QLabel>
firstwindow::firstwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::firstwindow)
{
    ui->setupUi(this);
    ui->essayer->setDisabled(true);
    ui->passer->setDisabled(true);
}

firstwindow::~firstwindow()
{
    delete ui;
}
bool aleatoire;
int nbr_lignes ;
int nbr_colonnes;
int nbr_obstacles;
std::vector<int> t2;
std::vector<std::vector<QCheckBox*>> t1;
std::vector<std::vector<QCheckBox*>> t3;

void firstwindow::on_essayer_clicked()

{
    ui->passer->setDisabled(false);
    nbr_lignes= ui->spin_nbr_lignes->value();
    nbr_colonnes= ui->spin_nbr_colonnes->value();
    nbr_obstacles= ui->spin_nbr_obstacles->value();
     if (ui->aleatoirement->isChecked()==true){
         aleatoire=true;
     }
     else{
        aleatoire=false;
     }
}


void firstwindow::on_passer_clicked()
{
    dlg=new Dialog(this);
    dlg->show();
}


void firstwindow::on_dimensions_clicked()
{
    ui->essayer->setDisabled(false);
    nbr_lignes= ui->spin_nbr_lignes->value();
    nbr_colonnes= ui->spin_nbr_colonnes->value();
    ui->spin_nbr_obstacles->setRange(0,nbr_lignes*nbr_colonnes-2);
}

