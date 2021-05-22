#ifndef RESOLUTION_H
#define RESOLUTION_H
#include <vector>
#include <iostream>
using namespace std;
class resolution
{
public:
        int nombre_lignes;
        int nombre_colonnes;
        int position_initiale;
        int position_finale;
        bool alea;
        std::vector<std::vector<int>> matrice_adj;
        std::vector<int> positions_obstacles;
        std::vector<int> matrice;
        std::vector<int> pcc();
        resolution(int, int, int,int, int, std::vector<int>,bool);
        resolution();
        resolution(const resolution&);
        //resolution &operator=(const resolution &);
        ~resolution();
    protected:

    private:
};

#endif // RESOLUTION_H
