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
   /* Sculptor p(20,20,20);
    vector<FiguraGeometrica*> fig;

    fig.push_back(new PutVoxel(1, 1, 1, 1, 0, 0, 1));
    fig.push_back(new PutVoxel(2, 2, 2, 0, 1, 0, 1));
    fig.push_back(new PutVoxel(3, 3, 3, 0, 0, 1, 1));
    fig.push_back(new PutSphere(19, 19, 19, 5, 1, 1, 1, 1));

    for(unsigned int i=0; i<fig.size(); i++){
        fig[i]->draw(p);
    }

    p.writeOFF("alo.off");
    system("meshlab alo.off");*/
    AbrirProjeto s("teste");

    return 0;
}
