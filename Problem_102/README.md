## Problem 102 - [Triangle containment](https://projecteuler.net/problem=102)

>   Three distinct points are plotted at random on a Cartesian plane, for which -1000 ≤ *x*, *y* ≤ 1000, such that a triangle is formed.
>
>   Consider the following two triangles:
>
>   A(-340,495), B(-153,-910), C(835,-947)
>
>   X(-175,41), Y(-421,-714), Z(574,-645)
>
>   It can be verified that triangle ABC contains the origin, whereas triangle XYZ does not.
>
>   Using [triangles.txt](https://projecteuler.net/project/resources/p102_triangles.txt), a 27K text file containing the co-ordinates of one thousand "random" triangles, find the number of triangles for which the interior contains the origin.
>
>   NOTE: The first two examples in the file represent the triangles in the example given above.

The question here is to figure out if a specific point is inside a triangle, if the three corners of the triangle is given.

Here we have two situations, whether the point is outside or inside of a triangle as below:

![PointInsideTriangle](PointInsideTriangle.gif)

(Technically, there is a third, where the point lies on the side of a triangle. However, it was not specified how that would be handled and luckily it never occurred in the given text file either.(To be fair the chance of that happening is quite low as well, while all three points are randomly located.))

In this illustration, we have denoted one vertex of the triangle ![ ](https://render.githubusercontent.com/render/math?math=V_{0}), then let ![ ](https://render.githubusercontent.com/render/math?math=V_{1}) and ![ ](https://render.githubusercontent.com/render/math?math=V_{2}) be the vectors from ![ ](https://render.githubusercontent.com/render/math?math=V_{0}) to the two other vertices.

Then we can express ![ ](https://render.githubusercontent.com/render/math?math=V) as:

![ ](https://render.githubusercontent.com/render/math?math=V=V_0%2Bx%20\cdot%20V_1%2By%20\cdot%20V_2)

From here, we can solve![](https://render.githubusercontent.com/render/math?math=x) and ![](https://render.githubusercontent.com/render/math?math=y):

![](https://render.githubusercontent.com/render/math?math=x%20=%20\frac{\det(VV_2)-\det(V_0V_2)}{\det(V_1V_2)})

![](https://render.githubusercontent.com/render/math?math=y%20=%20-\frac{\det(VV_1)-\det(V_0V_1)}{\det(V_1V_2)})

And since ![](https://render.githubusercontent.com/render/math?math=V%20=%20\{0,%200\}), so we can get:



![](https://render.githubusercontent.com/render/math?math=x%20=%20-\frac{\det(V_0V_2)}{\det(V_1V_2)})

![](https://render.githubusercontent.com/render/math?math=y%20=%20\frac{\det(V_0V_1)}{\det(V_1V_2)})

Now we can get ![](https://render.githubusercontent.com/render/math?math=V) is inside the triangle *iff* ![](https://render.githubusercontent.com/render/math?math=x,%20y>0) and ![](https://render.githubusercontent.com/render/math?math=a%20%2Bb<1).

For ones who don't know, ![](https://render.githubusercontent.com/render/math?math=\det) means:

>   In linear algebra, the **determinant** is a scalar value that can be computed from the elements of a square matrix and encodes certain properties of the linear transformation described by the matrix. The determinant of a matrix *A* is denoted det(*A*), det *A*, or |*A*|.

And in our case, ![](https://render.githubusercontent.com/render/math?math=\det(V_0V_2)) is equivalent to ![](https://render.githubusercontent.com/render/math?math=V_{0_x}\cdot%20V_{2_y}%20-%20V_{0_y}\cdot%20V_{2_x}).

Now this become rather simple. To figure if ![](https://render.githubusercontent.com/render/math?math=\triangle%20ABC)contains point ![](https://render.githubusercontent.com/render/math?math=\{0,%200\}), we can write:

```cpp
std::complex<float> a(ax, ay), b(bx, by), c(cx, cy);
std::complex<float> ab = b - a, ac = c - a;
double x = 	(a.imag() * ac.real() - a.real() * ac.imag()) /
    		(ab.real()*ac.imag() - ab.imag()*ac.real());
double y = 	(a.real() * ab.imag() - a.imag() * ab.real()) /
    		(ab.real()*ac.imag() - ab.imag()*ac.real());
if(x > 0 && y > 0 && x + y < 1)
{
    // point{0,0} locates inside the triangle
}
```

