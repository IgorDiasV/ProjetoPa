#include <iostream>
#include "sculptor.h"
#define color(x) x/255.0
using namespace std;

int main()
{
    // [altura][profundidade][largura]
    Sculptor p(30,30,30);
    p.setColor(color(254),color(225),color(45),1);
   /* for(int i=0;i<50;i++)
    {
        p.putEllipsoid(5,5,i,5,5,1);
        p.putEllipsoid(5,20,i,5,5,1);
        p.putEllipsoid(5,35,i,5,5,1);
        p.putEllipsoid(30,5,i,5,5,1);
        p.putEllipsoid(30,20,i,5,5,1);
        p.putEllipsoid(30,35,i,5,5,1);
    }*/
    p.putSphere(10,10,10,10);

    p.writeOFF("arquivo.off");
    system("meshlab arquivo.off");

    return 0;
}
