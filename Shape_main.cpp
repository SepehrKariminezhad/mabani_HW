#include<iostream>
#include <vector>
#include "shape.h"

using namespace std;


int main() {
    Cube c;
    Cube c2(1,4,6);

    vector<Cube> Cubes;
    Cubes.push_back(c);
    Cubes.push_back(c2);
    Cubes.push_back(Cube(6,8,9));

    for ( auto x : Cubes){
        cout << x.EvalVolume() << "\n";
    }
    sphere s;
    sphere s2(2);
    cout << s.EvalVolume() << "\n";
    cout << s2.EvalVolume();
    return 0;
}