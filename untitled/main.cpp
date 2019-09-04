#include <iostream>
#include <string>
using namespace std;
void putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    cout<<"OFF\n8 6 0"<<endl;
    cout<<x0<<" "<<y0<<" "<<z0<<endl;
    cout<<x0<<" "<<y1<<" "<<z0<<endl;
    cout<<x1<<" "<<y1<<" "<<z0<<endl;
    cout<<x1<<" "<<y0<<" "<<z0<<endl;
    cout<<x0<<" "<<y0<<" "<<z1<<endl;
    cout<<x0<<" "<<y1<<" "<<z1<<endl;
    cout<<x1<<" "<<y1<<" "<<z1<<endl;
    cout<<x1<<" "<<y0<<" "<<z1<<endl;
    cout<<"4 0 3 2 1 1 1 1 1\n4 4 5 6 7 1 1 1 1\n4 0 1 5 4 1 1 1 1\n4 0 4 7 3 1 1 1 1\n4 3 7 6 2 1 1 1 1\n4 1 2 6 5 1 1 1 1"<<endl;




}
int main()
{

    putBox(0,2,0,3,0,5);
    return 0;
}
