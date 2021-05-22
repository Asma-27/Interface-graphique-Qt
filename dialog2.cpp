#include "dialog2.h"
#include "ui_dialog2.h"
#include "resolution.h"
#include<QPushButton>
#include<QGraphicsGridLayout>
#include <QGridLayout>
#include <QCheckBox>
#include<string>
#include <vector>
#include<QPalette>
#include<QMessageBox>
Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
  // resolution r=resolution(nbr_lignes,nbr_colonnes,nbr_obstacles,case_initiale,case_finale,t2,true);
}
extern bool aleatoire;
extern int nbr_lignes ;
extern int nbr_colonnes;
extern int nbr_obstacles;
extern std::vector<int> t2;
extern std::vector<std::vector<QCheckBox*>> t1;
extern std::vector<std::vector<QCheckBox*>> t3;
extern int case_initiale;
extern int case_finale;
//extern std::vector<int> liste;
bool existe(std::vector<int> a, int k) {
    int j = 0;

    for (int i = 0;i < a.size();i++) {
        if (k == a[i]) {
            j++;
        }
    }
    if (j == 0) { return(false); }
    else { return(true); }
}
Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::on_display_clicked()
{
    resolution r=resolution(nbr_lignes,nbr_colonnes,nbr_obstacles,case_initiale,case_finale,t2,true);
    std::vector<int> liste;
    liste=r.pcc();
    if (liste.size()>1){
    //int* aux1 =new int[nbr_lignes*nbr_colonnes];
   // std::vector<int> aux1=test;
    int z;
    QString g;
    for(int i=0;i<nbr_lignes;i++){
        for(int j=0;j<nbr_colonnes;j++){
             z=i*nbr_colonnes+j;
            QPushButton* button7;
            //QPalette palette;
            if(existe(t2,z)){
                g=QString::number(0);
                button7 = new QPushButton("obstacle", this);
               // palette= button7->palette();
                button7->setStyleSheet(
                "QPushButton {"
                            "margin: 3px;"
                            "border-color: #0c457e;"
                            "border-style: outset;"
                            "border-radius: 3px;"
                            "border-width: 1px;"
                            "color: black;"
                            "background: solid #EC7063 ;"
                             );
               // ui->resize
                //palette.setColor(QPalette::Background, QColor("#00FF00");
              //  button7.setPalette(palette);

        }
            else if(existe(liste,z)) {
                 g=QString::number(1);
                 button7 = new QPushButton("PCC", this);
                // palette= button7->palette();
                 button7->setStyleSheet(
                 "QPushButton {"
                             "margin: 3px;"
                             "border-color: #0c457e;"
                             "border-style: outset;"
                             "border-radius: 3px;"
                             "border-width: 1px;"
                             "color: black;"
                             "background: solid #A9CCE3 ;"
                              );

            }
            else if(z==case_initiale){
                 g=QString::number(3);
                 button7 = new QPushButton("initiale", this);
                 button7->setStyleSheet(
                 "QPushButton {"
                             "margin: 3px;"
                             "border-color: #0c457e;"
                             "border-style: outset;"
                             "border-radius: 3px;"
                             "border-width: 1px;"
                             "color: black;"
                             "background: solid #2471A3;"
                              );
                // palette= button7->palette();

            }
            else if(z==case_finale)
            {
                 g=QString::number(4);
                 button7 = new QPushButton("finale", this);
                 button7->setStyleSheet(
                 "QPushButton {"
                             "margin: 3px;"
                             "border-color: #0c457e;"
                             "border-style: outset;"
                             "border-radius: 3px;"
                             "border-width: 1px;"
                             "color: black;"
                             "background: solid #2471A3;"
                              );
               //  palette= button7->palette();

            }
            else{
                         button7 = new QPushButton("vide", this);
                         button7->setStyleSheet(
                         "QPushButton {"
                                     "margin: 3px;"
                                     "border-color: #0c457e;"
                                     "border-style: outset;"
                                     "border-radius: 3px;"
                                     "border-width: 1px;"
                                     "color: black;"
                                     "background: solid #FDFEFE;"
                                      );
                       //  palette= button7->palette();

            }
            //QPushButton *button7;
             //QString g=QString::number(r.positions_obstacles[z]);
             //QString g=QString::number(t2[1]);
            // button7 = new QPushButton(g);

         ui->gridLayout->addWidget(button7,i,j);
}
}
    }
    else{
        QMessageBox::information(this,"résultat","il n'ya pas de plus court chemin pour ce cas ");
        this->show();
    }
}

