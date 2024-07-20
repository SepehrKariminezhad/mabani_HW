#include<iostream>
#include"shape.h"
#include <ctime>
#include "vector with 1 ptr.h"
#include "vector with 2 ptr.h"

using namespace std;

int main() {
    //creating a cube and a vector that is written with one pointer
    Cube a;
    vector<Cube> vec1;
    vec1.push_back(a);



    // the amount of cubes of reaching about 0.1 MB is about 3125 cubes
    for (int i = 0; i < 3124; i++) {
        vec1.push_back(a);
    }

    vec1.sizeof_();    //this tells us that the size of our cubes is 0.1 MB


    // the for to perform 1000 insert and remove functions and recording the cpu ticks
    clock_t s1;
    s1 = clock();
    for (int i = 0; i < 1001; i++) {
        vec1.insert(i, a);
        vec1.remove(i);
    }
    int cpu_ticks_ptr1 = clock() - s1;



    //creating a vector that is written with 2 pointers and passing 3125 cubes which reaches 0.1 MB according to line 22
    vector_2<Cube> vec2 (3125 , a);



    // the for to perform 1000 insert and remove functions and recording the cpu ticks
    clock_t s2;
    s2 = clock();
    for (int i = 0 ; i < 1001 ; i++)
    {
        vec1.insert(i, a);
        vec1.remove(i);
    }
    int cpu_ticks_ptr2 = clock() - s2;


    //printing the conclusion
    cout << "The amount of clock ticks for the vector with one ptr is " <<cpu_ticks_ptr1 << " and the amount of clock ticks for the vector with two ptrs is " <<cpu_ticks_ptr2 << endl ;


}


