#include <iostream>
#include "sculptor.h"
using namespace std;

int main()
{
    // [altura][profundidade][largura]
    Sculptor p(30,30,30);

    //p.putBox(0,10,0,10,0,10);
    //p.cutBox(1,9,1,10,1,10);
    p.putSphere(10,10,10,5);
    p.setColor(0,1,0,1);

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
