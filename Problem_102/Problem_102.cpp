#include <iostream>
#include <complex>
#include <fstream>

template <typename T>
bool includeOrigin(T a, T b, T c)
{
    T ab = b - a, ac = c - a;
    double x = (a.imag() * ac.real() - a.real() * ac.imag()) / (ab.real()*ac.imag() - ab.imag()*ac.real());
    double y = (a.real() * ab.imag() - a.imag() * ab.real()) / (ab.real()*ac.imag() - ab.imag()*ac.real());
    return(x > 0 && y > 0 && x + y < 1);
}

int main()
{
    std::ifstream infile("triangles.txt");
    int count = 0;
    float ax, ay, bx, by, cx, cy;
    char temp;
    while(infile >> ax >> temp >> ay >> temp >> bx >> temp >> by >> temp >> cx >> temp >> cy)
    {
        std::complex<float> a (ax, ay);
        std::complex<float> b (bx, by);
        std::complex<float> c (cx, cy);
        if(includeOrigin(a, b, c))
        {
            //std::cout << a << ", " << b << ", " << c << "\n";
            count++;
        }
    }
    infile.close();
    std::cout << "\n" << count << "\n";
    return 0;
}
