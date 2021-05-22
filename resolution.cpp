
/**************************************************/
#include "resolution.h"
#include <iostream>
#include <vector>
using namespace std;
resolution::resolution()
{}
resolution::resolution(const resolution& r) {
    this->nombre_lignes = r.nombre_lignes;
    this->nombre_colonnes = r.nombre_colonnes;
    this->position_initiale = r.position_initiale;
    this->position_finale = r.position_finale;
    this->alea = r.alea;
    this->matrice_adj = r.matrice_adj;
    this->positions_obstacles = r.positions_obstacles;
    this->matrice = r.matrice;
}
resolution::~resolution()
{
}
int find_ind(int e, int* t, int n) {
    int res = -1;
    for (int i = 0;i < n;i++) {
        if (e == *(t + i)) {
            res = i;
        }
    }
    return(res);
}
int minimum(int* t, int n) {
    int m = *t;
    for (int i = 0;i < n;i++) {
        if (*(t + i) < m) {
            m = *(t + i);
        }
    }
    int res;
    for (int i = 0;i < n;i++) {
        if (*(t + i) == m) {
            res = i;
        }
    }
    return(res);
}
bool exist_pas(int e, int* s, int n) {
    int res = 0;
    for (int i = 0;i < n;i++) {
        if (*(s + i) == e) {
            res++;
        }
    }
    if (res == 0) {
        return(true);
    }
    else {
        return(false);
    }
}
bool exist(std::vector<int> a, int k) {
    int j = 0;

    for (int i = 0;i < a.size();i++) {
        if (k == a[i]) {
            j++;
        }
    }
    if (j == 0) { return(false); }
    else { return(true); }
}
std::vector<int> a;
resolution::resolution(int lignes, int colonnes, int nombre_obstacles, int initial , int final , std::vector<int> obstacles , bool aleat ) {
    nombre_lignes = lignes;
    nombre_colonnes = colonnes;
    position_initiale = initial;
    position_finale = final;
    alea = aleat;
    if (aleat == true) {
        int r;
        std::vector<int> liste;
        for (int i = 0;i < nombre_obstacles;i++) {
            r = (rand() % lignes * colonnes);
            bool condition1 = (exist(liste, r) == true);
            bool condition2 = (r == initial);
            bool condition3 = (r == final);
            while ((condition1) || (condition2) || (condition3)) {
                r = (rand() % lignes * colonnes);
                condition1 = (exist(liste, r) == true);
                condition2 = (r == initial);
                condition3 = (r == final);
            }
            cout << r << endl;
            liste.push_back(r);
        }
        positions_obstacles = liste;
    }
    else {
        positions_obstacles = obstacles;
    }

    //int* matz = new int[lignes * colonnes];
    for (int i = 0;i < lignes * colonnes;i++) {
        if (i == initial) {
            matrice.push_back(3);
        }
        else if (i == final) {
            matrice.push_back(4);
        }
        else if (exist(positions_obstacles, i)) {
            matrice.push_back(0);
        }
        else {
            matrice.push_back(2);
        }
    }
    bool condition1;
    bool condition2;
    bool condition3;
    int taille = lignes * colonnes;
    int** m = new int* [taille];
    for (int i = 0;i < taille; i++) {
        *(m + i) = new int[taille];
        for (int j = 0;j < taille; j++) {
            condition1 = (((j) % colonnes == 0) && (j == i + colonnes));
            condition2 = (((j) % colonnes != 0) && ((j == i + 1) || (j == i + colonnes)));
            condition3 = ((exist(obstacles, i)) || (exist(obstacles, j)));
            if (j > i) {
                if (condition3) {
                    *(*(m + i) + j) = 0;
                    //cout << "la " << i << "eme ligne et la " << j << "eme colonne" << endl;
                }
                else if ((condition1)) {
                    *(*(m + i) + j) = 1;
                }
                else if ((condition2)) {
                    *(*(m + i) + j) = 1;
                }
                else {
                    *(*(m + i) + j) = 0;
                }
            }
            else if (i == j) {
                *(*(m + i) + j) = 0;
            }
            else {
                *(*(m + i) + j) = *(*(m + j) + i);
            }
        }
    }
    std::vector<int> aux;
    std::vector<std::vector<int>> mata;
       for (int i = 0;i < lignes * colonnes;i++) {
           for (int j = 0;j < lignes * colonnes;j++) {
               aux.push_back(*(*(m + i) + j));
           }
             mata.push_back(aux);
             aux.clear();
         }
     matrice_adj = mata;
    /*bool condition1;
    bool condition2;
    bool condition3;
    //matrice = matz;
    std::vector<int> aux;
    std::vector<std::vector<int>> mata;
    for (int i = 0;i < lignes * colonnes;i++) {
        for (int j = 0;j < lignes * colonnes;j++) {
            condition1 = (((j) % colonnes == 0) && (j == i + colonnes));
            condition2 = (((j) % colonnes != 0) && ((j == i + 1) || (j == i + colonnes)));
            condition3 = ((exist(positions_obstacles, i)) && (exist(positions_obstacles, j)));
            if (i < j) {
                if (condition1 || condition2) {
                    aux.push_back(1);
                }
                else if (condition3) {
                    aux.push_back(0);
                }
                else {
                    aux.push_back(0);
                }
            }
            else if (i == j) {
                aux.push_back(0);
            }
            else {
                aux.push_back(mata[j][i]);
            }
        }
        mata.push_back(aux);
        aux.clear();
    }*/

}

std::vector<int> resolution::pcc() {
    std::vector<int> res;
    bool reponse;
    int nbr_lignes = nombre_lignes;
    int nbr_colonnes = nombre_colonnes;
    std::vector<std::vector<int>> mata = matrice_adj;
    int n = nbr_lignes * nbr_colonnes;
    int** tab = new int* [n * 2];
    int* test = new int[n * 2];
    int* aux = new int[n * 2];
    int* s = new int[n * 2];
    int sommet_ini = position_initiale;
    int sommet_fin = position_finale;
    for (int i = 0;i < n;i++) {
        *(tab + i) = new int[n * 2];
        *(s + i) = -1;
        if (i == sommet_ini) {
            *(*(tab + i) + 0) = 0;
        }
        else {
            *(*(tab + i) + 0) = 999;
        }
    }
    for (int i = 0;i < n;i++) {
        int a;
        for (int j = 0;j < n;j++) {
            if (exist_pas(j, s, n)) {
                *(aux + j) = *(*(tab + j) + 0);
            }
            else {
                *(aux + j) = 9999;
            }

        }
        a = minimum(aux, n);
        *(s + i) = a;
        for (int k = 0;k < n;k++) {
            if ((exist_pas(k, s, n)) && (mata[k][a] == 1)) {
                if (*(aux + a) + 1 < *(aux + k)) {
                    *(*(tab + k) + 0) = *(aux + a) + 1;
                    *(*(tab + k) + i + 1) = a;
                }
            }
            else {
                *(*(tab + k) + i + 1) = -7;
            }
        }
    }
    for (int i = 0;i < n;i++) {
        // cout << endl;
        for (int j = 0;j < n;j++) {
            // cout << *(*(tab + j) + i) << "               |";
        }
    }
    //  cout << endl;
    for (int i = 0;i < n;i++) {
        *(aux + i) = *(*(tab + i) + 0);
    }
    int x = sommet_fin;
    if (*(aux + x) > n * n) {
        reponse = false;
        // cout << "il n'existe pas de chemin entre la case initiale et la case finale" << endl;
    }
    else {
        reponse = true;
        int u = 0;
        int y = 0;
        int x = sommet_fin;
        //cout << "le plus court chemin est ";
        while ((x != sommet_ini) && (y < n)) {
            while ((u < n - 1) && ((*(*(tab + x) + n - 1 - u) < 0))) {
                u++;
            }
            *(test + y) = x;
            this->matrice.erase(this->matrice.begin()+x);
            this->matrice.insert(this->matrice.begin()+x,1);
            //this->matrice[x] = 1;
            res.push_back(x);
            // cout << "(" << x / nbr_colonnes << ", " << x % nbr_colonnes << ")" << "<-";
            y++;
            x = *(*(tab + x) + n - 1 - u);
            u = 0;
        }
        /*int b = find_ind(sommet_ini, s, n);
        int v = find_ind(sommet_fin, s, n);
        cout << "le plus court chemin est ";
        while ((b < v) && (*(s + b) != x)) {
            cout << "(" << *(s + b) / nbr_colonnes << ", " << *(s + b) % nbr_colonnes << ")" << "->";
            b++;
        }*/
        // cout << "(" << x / nbr_colonnes << ", " << x % nbr_colonnes << ")" << endl;
    }
    if (reponse == true) {
        return(res);
        //return(matrice);
    }
    else {
        std::vector<int> v;
        v.push_back(0);
        return(v);
    }
}




