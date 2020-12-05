## Problem 94 - [Almost equilateral triangles](https://projecteuler.net/problem=94)

> It is easily proved that no equilateral triangle exists with integral length sides and integral area. However, the *almost equilateral triangle* 5-5-6 has an area of 12 square units.
>
> We shall define an *almost equilateral triangle* to be a triangle for which two sides are equal and the third differs by no more than one unit.
>
> Find the sum of the perimeters of all *almost equilateral triangles* with integral side lengths and area and whose perimeters do not exceed one billion (1,000,000,000).

## Naive Solution

First, let's look at the formula to find the area of a triangle:

![ ](https://render.githubusercontent.com/render/math?math=A_{tri}=h*b_{h}/2)

To ensure ![](https://render.githubusercontent.com/render/math?math=A_{tri}) gets an integer solution, both![](https://render.githubusercontent.com/render/math?math=h) and![](https://render.githubusercontent.com/render/math?math=b_{h})need to be integers, and either ![](https://render.githubusercontent.com/render/math?math=h) or ![](https://render.githubusercontent.com/render/math?math=b_{h})need to be an even number.

In this problem, we also know what ![](https://render.githubusercontent.com/render/math?math=b_{h}=[3,1000000000/3%29), so the only value we actually need to find in this question would be ![](https://render.githubusercontent.com/render/math?math=h).

To find ![](https://render.githubusercontent.com/render/math?math=h), we would be using Pythagorean formula:

![](https://render.githubusercontent.com/render/math?math=a^{2}%2Bb^{2}=c^{2})

Or in this particular case, it would be:

![](https://render.githubusercontent.com/render/math?math=h^{2}=%28{b_{h}\pm1}%29^{2}-%28{b_{h}/2}%29^{2},h\in\mathbb{N})

And we already know that ![](https://render.githubusercontent.com/render/math?math=b_{h}) is an integer, so ![](https://render.githubusercontent.com/render/math?math={b_{h}}/2) also need to be an integer. Which means ![](https://render.githubusercontent.com/render/math?math=b_{h}) is an even number.

Now we can start to build our function to test for all possible ![](https://render.githubusercontent.com/render/math?math=b_{h}), if ![](https://render.githubusercontent.com/render/math?math=h) is and integer:

```cpp
bool isHeightInteger(long long base, long long hyp)
{
//  To test if base is odd.
//  This step could also be done in the input part, which could reduce test cases.
//  if(base % 2)
//  {
//  	return false;
//  }
    
//  Since std::pow(heightSq, 0.5) returns a floating type, we would need to round it 
//  and square it back to see if it gets the gets the original value.
    long long heightSq = base * base / 4 + hyp * hyp;
    long long height = std::round(std::pow(heightSq, 0.5));
    return height * height == heightSq
}
```

Now we can easily create a `main()` to test all case below 333,333,334, since that's the max value to possibly give a perimeter no larger than 1,000,000,000:

```cpp
int main()
{
    long long sum = 0;
//  Notice that we mannually skipped 2 because we could tell neither (2,3,3) or (2,1,1) is a valid answer,
//  and we skipped 1 and 3 because they are odd.
    for(long long i = 4; i < 333333334; i+=2)
    {
//  This would test all case of bₕ±1 where bₕ is an even number. If the height is also an integer, 
//  it would output both bₕ and h, and add the perimeter to sum.
        if(isIntTri(i, i+1))
        {
            std::cout << i << ", " << i+1 << "\n";
            sum += i * 3 + 2;
        
        if(isIntTri(i, i-1))
        {
            std::cout << i << ", " << i-1 << "\n";
            sum += i * 3 - 2;
        }
    }
}
```

- This sure runs, and runs pretty well for the first few iterations, but it would soon become really slow...

## Better Solution

If you print the first few Almost Equilateral Triangles, you might see some subtle pattern(or not).

A nice property about isosceles triangles is that they could be perfectly divided to equal right triangle if you divide them along their center line/height. And let's call one of them:![](https://render.githubusercontent.com/render/math?math=\triangle{ABC}), where ![](https://render.githubusercontent.com/render/math?math=\angle{C})is the right angle, ![](https://render.githubusercontent.com/render/math?math=\overline{c})is the leg of the isosceles triangle, ![](https://render.githubusercontent.com/render/math?math=\overline{a})is the original ![](https://render.githubusercontent.com/render/math?math=h)of the isosceles triangle:

![](https://github.com/Ranoiaetep/ProjectEulerSolutions/blob/master/Problem_094/Triangle.png?raw=true)

The fact we know ![](https://render.githubusercontent.com/render/math?math=\overline{c}=2\overline{b}\pm1), we can also confirm that ![](https://render.githubusercontent.com/render/math?math=\overline{a},\overline{b},\overline{c})must be a [*Primitive Pythagorean Triple*](https://en.wikipedia.org/wiki/Pythagorean_triple)(all three are relatively coprime of each other).

There are many ways to generate all Primitive Pythagorean Triples, and one of them would be based on [Tree of primitive Pythagorean triples](https://en.wikipedia.org/wiki/Tree_of_primitive_Pythagorean_triples):

<img src="https://upload.wikimedia.org/wikipedia/commons/d/d0/Berggrens%27s_tree_with_reordered_path_keys.svg" style="zoom: 25%;" />

To generate each iterations of the tree, you would multiply the current triple with:

![](https://wikimedia.org/api/rest_v1/media/math/render/svg/c3ae2ba860841c93e39c8f2b711691f7f352aefe)

Now go back to the triangles we have formed earlier, some of the earlier one would have the length of each side be:

| Leg  | Base |
| ---- | ---- |
| 5    | 6    |
| 17   | 16   |
| 65   | 66   |
| 241  | 240  |
| ⋮    | ⋮    |

And if you divide these triangles the way we have mentioned earlier, you would have:

| ![](https://render.githubusercontent.com/render/math?math=\overline{a}) | ![](https://render.githubusercontent.com/render/math?math=\overline{b}) | ![](https://render.githubusercontent.com/render/math?math=\overline{c}) |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 4                                                            | 3                                                            | 5                                                            |
| 15                                                           | 8                                                            | 17                                                           |
| 56                                                           | 33                                                           | 65                                                           |
| 209                                                          | 120                                                          | 241                                                          |
| ⋮                                                            | ⋮                                                            | ⋮                                                            |

Since they are all primitive pytahgorean triples, they of course all appears on that earlier tree. In fact, they would each be the first and third branch of the previous branch.

Now we can easily transform them into code:

```cpp
// A helper function to do matrix multiplication since C++ doesn't have a built-in matrix type.
Triangle Multiply(triangle tri, std::array<std::array<int, 3>, 3>& matrix)
{
    return Triangle{
        matrix[0][0] * tri.A + matrix[0][1] * tri.B + matrix[0][2] * tri.C,
        matrix[1][0] * tri.A + matrix[1][1] * tri.B + matrix[1][2] * tri.C,
        matrix[2][0] * tri.A + matrix[2][1] * tri.B + matrix[2][2] * tri.C };
}

std::array<std::array<int, 3>, 3> MatrixA {{{{-1,2,2}},{{-2,1,2}},{{-2,2,3}}}};
std::array<std::array<int, 3>, 3> MatrixC {{{{1,-2,2}},{{2,-1,2}},{{2,-2,3}}}};

// Here we will get the next triangle, and add the perimeter of it to SUM. 
// Toggle decides whether we are using MatrixA or MatirxC for the multiplication.
void Transform(Triangle tri, bool toggle = 1)
{
    int P = tri.C * 2 + (toggle ? tri.A * 2 : tri.B * 2);
    if (P > MAX) return;
    SUM += P;
    Transform(toggle ? Multiply(tri, MatrixA) : Multiply(tri, MatrixC), !toggle);
}


int main()
{
    Transform({3,4,5}); // Here we just pass in the origin triple {3,4,5}.
    std::cout << "RESULT: " << SUM << "\n";
}
```

-   Comparing to the first algorithm having ![](https://render.githubusercontent.com/render/math?math=\O(n^2)), this algorithm have complexity of ![](https://render.githubusercontent.com/render/math?math=\O(\log{n})).
