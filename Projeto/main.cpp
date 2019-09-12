#include <iostream>
#include "sculptor.h"
using namespace std;

int main()
{

    Sculptor p(2,2,2);
    p.setColor(1,1,0,1);
    p.putVoxel(0,0,0);
    p.putVoxel(1,1,1);

    p.writeOFF("arquivo.off");
    system("geomview arquivo.off");

    return 0;
}
