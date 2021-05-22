#include "dialog1.h"
#include "ui_dialog1.h"
#include<QPushButton>
#include<QGraphicsGridLayout>
#include <QGridLayout>
#include <QCheckBox>
#include<string>
#include <vector>
#include<QMessageBox>
Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
    ui->buttonBox->setDisabled(true);
    ui->finir->setDisabled(true);
}
int compteur_ob;
extern bool aleatoire ;
extern int nbr_lignes ;
extern int nbr_colonnes;
extern int nbr_obstacles;
extern std::vector<int> t2;
extern std::vector<std::vector<QCheckBox*>> t1;
extern std::vector<std::vector<QCheckBox*>> t3;
extern int case_initiale;
extern int case_finale;
Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::on_commencer_clicked()
{
    ui->finir->setDisabled(false);
    //QGridLayout *layout = new QGridLayout(this);
    std::vector<QCheckBox*> a;
    for(int i=0;i<nbr_lignes;i++){
        for(int j=0;j<nbr_colonnes;++j){
            QString s=QString("(%1,%2)").arg(i).arg(j);
            QCheckBox *checkbox = new QCheckBox(s, this);
            a.push_back(checkbox);
        }
         t1.push_back(a);
         a.clear();
    }
for(int i=0;i<nbr_lignes;i++){
    for(int j=0;j<nbr_colonnes;j++){
        ui->gridLayout->addWidget(t1[i][j],i,j);
    }
}
}

void Dialog1::on_finir_clicked()
{
    ui->buttonBox->setDisabled(false);
    t2.clear();
    compteur_ob=0;
    if(aleatoire==false){
    for(int i=0;i<nbr_lignes;i++){
        for(int j=0;j<nbr_colonnes;j++){

        if (t1[i][j]->isChecked()==true){
            t2.push_back(i*nbr_colonnes+j);
            compteur_ob++;
        }
        }
    }
    }
}


void Dialog1::on_buttonBox_accepted()
{
    if(compteur_ob==nbr_obstacles){
    dlg2=new Dialog2(this);
    dlg2->show();
    }
    else{
        QMessageBox::warning(this,"error","réessayer");
        this->show();
    }
}
