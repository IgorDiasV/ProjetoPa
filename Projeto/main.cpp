#include <iostream>
#include "sculptor.h"
#include "classes.h"
#include <vector>
#include "abrirprojeto.h"
#define color(x) x/255.0

using namespace std;

int main()
{
    // [altura][profundidade][largura]
    // z x y
        /*p.putBox(0,20,0,20,0,20);
        p.cutBox(0,10,0,10,0,10);
        p.setColor(0,0,1,1);
        p.putSphere(5,5,5,5);
        p.cutVoxel(19,19,19);
        p.putVoxel(19,19,19);
        p.cutEllipsoid(15,15,15,6,5,4);
        p.setColor(0,1,0,1);
        p.putEllipsoid(15,15,15,6,5,4);*/
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
   // AbrirProjeto s("fig.txt");

    return 0;
}
