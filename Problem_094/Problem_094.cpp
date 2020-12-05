#include <iostream>
#include <array>

const int MAX = 1000000000;
struct Triangle
{
	int A;
	int B;
	int C;
};

int SUM = 0;

std::array<std::array<int, 3>, 3> MatrixA {{{{-1,2,2}},{{-2,1,2}},{{-2,2,3}}}};
std::array<std::array<int, 3>, 3> MatrixC {{{{1,-2,2}},{{2,-1,2}},{{2,-2,3}}}};

Triangle Transform(Triangle tri, std::array<std::array<int, 3>, 3>& matrix)
{
	return Triangle{
		matrix[0][0] * tri.A + matrix[0][1] * tri.B + matrix[0][2] * tri.C,
		matrix[1][0] * tri.A + matrix[1][1] * tri.B + matrix[1][2] * tri.C,
		matrix[2][0] * tri.A + matrix[2][1] * tri.B + matrix[2][2] * tri.C };
}

void Transform(Triangle tri, bool toggle = 1)
{
	int P = tri.C * 2 + (toggle ? tri.A * 2 : tri.B * 2);
	if (P > MAX) return;
	SUM += P;
	std::cout << "Triangle: " << tri.C << ", " << tri.C << ", " << (toggle ? tri.A * 2 : tri.B * 2);
	std::cout << "\nPythagorean: " << tri.A << ", " << tri.B << ", " << tri.C;
	std::cout << "\n" << "P: " << P << "\tSum: " << SUM << "\n\n";
	Transform(
		toggle ? Transform(tri, MatrixA) : Transform(tri, MatrixC), 
		!toggle);
}

int main()
{
	Triangle Origin{3,4,5};
    Transform({3,4,5});
    std::cout << "RESULT: " << SUM << "\n";
}
