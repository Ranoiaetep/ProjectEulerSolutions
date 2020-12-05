#include <iostream>
#include <algorithm>
#include <map>

std::map<int, int> map;
const int MAX = 1500000;
struct triangle
{
	int A;
	int B;
	int C;
};

void Transform(triangle tri)
{
	if (tri.A + tri.B + tri.C > MAX) return;
	for(int i = tri.A + tri.B + tri.C; i <= MAX; i += tri.A + tri.B + tri.C)
	{
		++map[i];
	}
	Transform(triangle{
		+ 1 * tri.A - 2 * tri.B + 2 * tri.C,
		+ 2 * tri.A - 1 * tri.B + 2 * tri.C,
		+ 2 * tri.A - 2 * tri.B + 3 * tri.C});
	Transform(triangle{
		+ 1 * tri.A + 2 * tri.B + 2 * tri.C,
		+ 2 * tri.A + 1 * tri.B + 2 * tri.C,
		+ 2 * tri.A + 2 * tri.B + 3 * tri.C});
	Transform(triangle{
		- 1 * tri.A + 2 * tri.B + 2 * tri.C,
		- 2 * tri.A + 1 * tri.B + 2 * tri.C,
		- 2 * tri.A + 2 * tri.B + 3 * tri.C});
}

int main(int argc, const char * argv[])
{
	triangle Origin{3,4,5};
	Transform(Origin);
	std::cout << std::count_if(map.begin(), map.end(), [](auto a){
		return a.second == 1;
	}) << "\n\n";
}
