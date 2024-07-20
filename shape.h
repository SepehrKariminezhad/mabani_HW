#include <iostream>
#include <array>
class Cube {

public:
    Cube(){}
    Cube(auto _A, auto _B, auto _C): A(_A), B(_B), C(_C){
    }
public:
    double EvalVolume(){
        return A * B * C;
    }
    std::array<double, 3> GetAll(){
        auto tmp {std::array<double, 3>()};
        tmp[0]=A;
        tmp[1]=B;
        tmp[2]=C;
        return tmp;
    }
    void SetAll(auto _A, auto _B, auto _C){
        A=_A;
        B=_B;
        C=_C;
    }
    void SetA(double x){
        A=x;
    }
    void SetB(double x){
        B=x;
    }
    void SetC(double x){
        C=x;
    }
    const double& GetA(){
        return A;
    }
    const double& GetB(){
        return B;
    }
    const double& GetC(){
        return C;
    }
private:
    double A, B, C, Volume;
};

class sphere
{
public:
    sphere()
    {R = 0;}

    sphere(auto a)
    {R = a;}

    double EvalVolume()
    {
        return (4/3) * pi * (R*R*R);
    }

    void getR(auto a)
    {
        R = a;
    }
private:
    double R;
    float pi = 3.14159;
};


class pyramid
{
public:
    pyramid(){
         A = 0;
         H = 0;
    }
    pyramid(auto a , auto b)
    {
       A = a;
       H = b;
    }
    double EvalVolume()
    {
        return (1/3) * H * A * A;
    }
    void getA_H(auto a , auto b)
    {
        A = a;
        H = b;
    }

private:
    double A , H;
};




class cylinder
{
public:
    cylinder(){
        A = 0;
        H = 0;
    }
    cylinder(auto a , auto b)
    {
        A = a;
        H = b;
    }
    double EvalVolume()
    {
        return H * (pi * A * A);
    }
    void getA_H(auto a , auto b)
    {
        A = a;
        H = b;
    }

private:
    double A , H;
    float pi = 3.14159;
};
