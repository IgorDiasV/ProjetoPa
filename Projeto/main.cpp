#include "sculptor.h"
#include "classes.h"
#include "abrirprojeto.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    /*
    Sculptor p(30,30,30);
    vector<FiguraGeometrica*> fig;
    fig.push_back(new PutBox(0, 20, 0, 20, 0, 20,0,1,0,1));
    fig.push_back(new CutBox(0, 10, 0, 10, 0, 10));
    fig.push_back(new PutSphere(5, 5, 5, 5, 1, 1, 1,1));
    fig.push_back(new CutVoxel(19, 19, 19));
    fig.push_back(new PutVoxel(19,19,19,1,1,1,1));
    fig.push_back(new PutVoxel(20,20,20,1,1,1,1));
    fig.push_back(new CutEllipsoid(15,15,15,6,5,4));
    fig.push_back(new PutEllipsoid(15,15,15,8,5,6,1,1,1,1));

    for(unsigned int i=0; i<fig.size(); i++){
        fig[i]->draw(p);
    }

    p.writeOFF("figura.off");
    system("meshlab figura.off");
    */
    AbrirProjeto s("fig.txt");

    return 0;
}
