#include <iostream> 
#include <cmath> 
using namespace std; 

/** 
* \brief calculates the value of a 
* \param x the first argument of the function 
* \param y the second argument of the function 
* \return Return a value 
*/ 

double getA(const double x, const double y, const double z); 

/** 
* \brief calculates the value of b 
* \param x the first argument of the function 
* \param y the second argument of the function 
* \param z the third argument of the function 
* \return Return b value 
*/ 

double getB(const double x, const double y, const double z); 

/* 
* \brief Enterint the program 
* \return Returns 0 in case of success 
*/ 

int main() 

{ 
const double x = 0.61; 
const double y = 3.4; 
const double z = 16.5; 
const double a = getA(x, y, z); 
const double b = getB(x, y, z); 
cout << "x=" << x << "\n" << "y=" << y << "\n" << "z=" << z << endl; 
cout << "A=" << a << "\n" << "B=" << b << endl; 
return 0; 
} 

double getA(const double x, const double y, const double z) 

{ 
return ((x * x * x) * (tan((x + y) * (x + y)) * tan((x + y) * (x + y))) + (z / (sqrt(x + y))));
} 

double getB(const double x, const double y, const double z) 

{ 
return ((y * (x * x) - z) / (exp(z * x) - 1)); 
}
