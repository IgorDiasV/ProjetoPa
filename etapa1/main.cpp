#include <iostream>
#include <iomanip>
#define np 3
#define nl 2
#define nc 1

using namespace std;

int main(){

    int ***x = new int**[np*nl*nc];

    for(int i = 0; i < np; i++){
        x[i] = new int*[nl*nc];
    }
    for(int i = 0; i < np; i++){
        for(int j = 0; j < nl; j++){
            x[i][j] = new int[nc];
        }
    }

    for(int i = 0; i < np; i++){
        for(int j = 0; j < nl; j++){
            for(int k = 0; k < nc; k++){
                  x[i][j][k] = j;
            }
        }
    }

    for(int i = 0; i < np; i++){
        for(int j = 0; j < nl; j++){
            for(int k = 0; k < nc; k++){
                  cout << setw(2) << x[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    for(int i = 0; i < np; i++){
        for(int j = 0; j < nl; j++){
            delete x[i][j];
        }
    }
    delete [] *x;
    delete [] **x;

    return 0;
}

