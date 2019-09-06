#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;
void putVoxel(int x,int y,int z)
{
    ofstream fout;
    fout.open("/home/igor/Documentos/arquivo.off");
    if(!fout.is_open())
    {
        exit(0);
    }
    fout<<"OFF\n8 6 0"<<endl;
    fout<<x-0.5<<" "<<y+0.5<<" "<<z-0.5<<endl;
    fout<<x-0.5<<" "<<y-0.5<<" "<<z-0.5<<endl;
    fout<<x+0.5<<" "<<y-0.5<<" "<<z-0.5<<endl;
    fout<<x+0.5<<" "<<y+0.5<<" "<<z-0.5<<endl;
    fout<<x-0.5<<" "<<y+0.5<<" "<<z+0.5<<endl;
    fout<<x-0.5<<" "<<y-0.5<<" "<<z+0.5<<endl;
    fout<<x+0.5<<" "<<y-0.5<<" "<<z+0.5<<endl;
    fout<<x+0.5<<" "<<y+0.5<<" "<<z+0.5<<endl;
    fout<<"4 0 3 2 1 1 1 1 1\n4 4 5 6 7 1 1 1 1\n4 0 1 5 4 1 1 1 1\n4 0 4 7 3 1 1 1 1\n4 3 7 6 2 1 1 1 1\n4 1 2 6 5 1 1 1 1"<<endl;

    fout.close();


}
int main()
{

    putVoxel(2,5,5);
    return 0;
}
