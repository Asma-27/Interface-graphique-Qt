#include "dialog.h"
#include "ui_dialog.h"
#include<QPushButton>
#include<QGraphicsGridLayout>
#include <QGridLayout>
#include <QCheckBox>
#include<string>
#include <vector>
#include<QMessageBox>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->finir->setDisabled(true);
    ui->buttonBox->setDisabled(true);
}
int compteur;
extern bool aleatoire;
extern int nbr_lignes ;
extern int nbr_colonnes;
extern int nbr_obstacles;
extern std::vector<int> t2;
extern std::vector<std::vector<QCheckBox*>> t1;
extern std::vector<std::vector<QCheckBox*>> t3;
int case_initiale;
int case_finale;
Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{

}


void Dialog::on_pushButton_2_clicked()
{

}


void Dialog::on_finir_clicked()
{
    ui->buttonBox->setDisabled(false);
    compteur=0;
    std::vector<int> aux;
    for(int i=0;i<nbr_lignes;i++){
        for(int j=0;j<nbr_colonnes;j++){
             if (t3[i][j]->isChecked()==true){
                 aux.push_back(i*nbr_colonnes+j);
                 compteur++;
             }
        }
    }
    case_initiale = aux[0];
    case_finale = aux[1];
}


void Dialog::on_commencer_clicked()
{
    ui->finir->setDisabled(false);
    t3.clear();
    for(int i=0;i<nbr_lignes;i++){
        std::vector<QCheckBox*> a;
        for(int j=0;j<nbr_colonnes;++j){
            QString s=QString("(%1,%2)").arg(i).arg(j);
            QCheckBox *checkbox = new QCheckBox(s, this);
            a.push_back(checkbox);
        }
        t3.push_back(a);
    }
    for (int i=0;i<nbr_lignes;i++){
        for(int j=0;j<nbr_colonnes;j++){
            ui->gridLayout->addWidget(t3[i][j],i,j);
        }
    }
}


void Dialog::on_buttonBox_accepted()
{
    if(aleatoire==false){
    if(compteur==2){
        dlg1=new Dialog1(this);
        dlg1->show();
    }
    else{
        QMessageBox::warning(this,"error","réessayer");
        this->show();
    }
    }
    else{
        dlg2=new Dialog2(this);
        dlg2->show();
    }
}

