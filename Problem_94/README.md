## Problem 94.

> It is easily proved that no equilateral triangle exists with integral length sides and integral area. However, the *almost equilateral triangle* 5-5-6 has an area of 12 square units.
>
> We shall define an *almost equilateral triangle* to be a triangle for which two sides are equal and the third differs by no more than one unit.
>
> Find the sum of the perimeters of all *almost equilateral triangles* with integral side lengths and area and whose perimeters do not exceed one billion (1,000,000,000).



First, let's look at the formula to find the area of a triangle:

![ ](https://render.githubusercontent.com/render/math?math=A_{tri} = h * b_{h} / 2)

To ensure ![](https://render.githubusercontent.com/render/math?math=A_{tri}) gets an integer solution, both![](https://render.githubusercontent.com/render/math?math=h) and![](https://render.githubusercontent.com/render/math?math=b_{h})need to be integers, and either ![](https://render.githubusercontent.com/render/math?math=h) or ![](https://render.githubusercontent.com/render/math?math=b_{h})need to be an even number.

In this problem, we also know what ![](https://render.githubusercontent.com/render/math?math=b_{h} = [ 3, 1000000000 / 3%29), so the only value we actually need to find in this question would be ![](https://render.githubusercontent.com/render/math?math=h).

To find ![](https://render.githubusercontent.com/render/math?math=h), we would be using Pythagorean formula:

![](https://render.githubusercontent.com/render/math?math=a^{2}%2Bb^{2}=c^{2})

Or in this particular case, it would be:

![](https://render.githubusercontent.com/render/math?math=h^{2}=%28{b_{h}\pm1}%29^{2} - %28{b_{h}/2}%29^{2}, h\in \mathbb{N})

And we already know that ![](https://render.githubusercontent.com/render/math?math=b_{h}) is an integer, so ![](https://render.githubusercontent.com/render/math?math={b_{h}}/2) also need to be an integer. Which means ![](https://render.githubusercontent.com/render/math?math=b_{h}) is an even number.

Now we can start to build our function to test for all possible ![](https://render.githubusercontent.com/render/math?math=b_{h}), if ![](https://render.githubusercontent.com/render/math?math=h) is and integer:

```cpp
bool isHeightInteger(long long base, long long hyp)
{
//	if(base % 2)												// To test if base is odd.
//	{															// This step could also be done in the input
//		return false;											// part, which could reduce test cases.
//	}
    
    long long heightSq = base * base / 4 + hyp * hyp;			// Since std::pow(heightSq, 0.5) returns a 
    long long height = std::round(std::pow(heightSq, 0.5));		// floating type, we would need to round it 
    return height * height == heightSq;							// and square it back to see if it gets the
}																// gets the original value.
```

Now we can easily create a main to test all case below 333,333,334, since that's the max value to possibly give a perimeter no larger than 1,000,000,000:

```cpp
int main()
{																// Notice that we mannually skipped 2
    long long sum = 0;											// because we could tell neither (2,3,3) or
    for(long long i = 4; i < 333333334; i+=2)					// (2,1,1) is a valid answer, and we skipped
    {															// 1 and 3 because they are odd.
        if(isIntTri(i, i+1))									
        {
            std::cout << i << ", " << i+1 << "\n";				// This would test all case of bₕ±1 where
            sum += i * 3 + 2;									// bₕ is an even number.
        }														// If the height is also an integer, it 
        if(isIntTri(i, i-1))									// would output both bₕ and h, and add the
        {														// perimeter to sum.
            std::cout << i << ", " << i-1 << "\n";
            sum += i * 3 - 2;
        }
    }
}
```

