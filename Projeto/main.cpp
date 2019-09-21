#include <iostream>
#include "sculptor.h"
#define color(x) x/255.0
using namespace std;

int main()
{
    // [altura][profundidade][largura]
    Sculptor p(101,101,101);

    //p.putBox(0,10,0,10,0,10);
    p.setColor(color(50),color(120),color(115),1);
    p.putVoxel(0,0,0);
    p.putVoxel(100,0,0);
    p.putVoxel(0,100,0);
    p.putVoxel(0,0,100);
    p.putVoxel(100,100,0);
    p.putVoxel(0,100,100);
    p.putVoxel(100,0,100);
    p.putVoxel(100,100,100);
    p.setColor(color(220),color(20),color(60),1);//(220,20,60)
    p.putBox(90,150,90,150,90,150);
    p.putEllipsoid(-200,-200,-200,50,25,30);
    //p.putEllipsoid(50,50,50,8,15,25);
    //p.cutBox(2,8,2,8,2,8);
    //p.cutBox(7,10,0,10,0,10);
    //p.setColor(color(105),color(50),color(160),1);//(220,20,60)
    p.putSphere(-1,-1,-1,10);
    //p.cutBox(20,100,0,100,0,100);

    /*
    p.putVoxel(1,0,0);//vermelho
    p.setColor(0,0,1,1);
    p.putVoxel(0,1,0);//azul
    p.setColor(0,1,0,1);
    p.putVoxel(0,0,1);//verde
    p.setColor(1,1,1,1);
    p.putVoxel(0,0,0);
    */

    p.writeOFF("arquivo.off");
    system("meshlab arquivo.off");

    return 0;
}
