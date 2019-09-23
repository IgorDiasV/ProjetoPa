#include <iostream>
#include "sculptor.h"
#define color(x) x/255.0
using namespace std;

int main()
{
    // [altura][profundidade][largura]
    // z x y
    Sculptor p(30,30,30);
    p.putBox(0,20,0,20,0,20);
    p.cutBox(0,10,0,10,0,10);
    p.setColor(0,0,1,1);
    p.putSphere(5,5,5,5);
    p.cutVoxel(19,19,19);
    p.putVoxel(19,19,19);
    p.cutEllipsoid(15,15,15,6,5,4);
    p.setColor(0,1,0,1);
    p.putEllipsoid(15,15,15,6,5,4);
    p.writeOFF("arquivo.off");
    system("meshlab arquivo.off");

    return 0;
}
