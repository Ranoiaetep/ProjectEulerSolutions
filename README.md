# Project Euler Solutions and Explanations

### What is [Project Euler](https://projecteuler.net/)?

> Project Euler was started by Colin Hughes (a.k.a. euler) in October 2001 as a sub-section on [mathschallenge.net](http://mathschallenge.net/).
>
> Since then the membership has continued to grow and Project Euler moved to its own domain in 2006.

With over 700 questions published on the site, each question was developed and managed by a group of their members.

Each question would have their own difficulties which might range from pretty easy to quite hard.

Despite its difficulties, most of the question does not need much math skills beyond some basic algebras. While certain math knowledge is required, such as ***prime number*** or ***Pythagorean theorem***, and in most cases, they would also be explained, nothing really crazy is involved.

---

### What is this site for?

As the title have suggested, this site is to publish some of my attempts to solve the questions from **Project Euler**.

As I am most proficient in C++, most, if not all, would be solved in C++, despite certain questions might be much easier to be solved in other languages.

While there are many who have been solving the questions in languages like J, and achieving what I have done in hundreds of lines in a 1-liner, but just like regex:

<img src="https://pbs.twimg.com/media/D-svlGFWsAErN5b?format=jpg&name=large" style="zoom:25%;" />

(Image created by twitter user [@garabatokid](https://twitter.com/garabatokid))

There's nothing for me to disrespect those solutions, however, I feel I would rather work on them in longer ways to fully understand what I'm doing.

I might try to rewrite some of them in Python however, but it will not be today.

In the same time, I will try to add explanations on all my solutions, but those take much more time to update than the solutions themselves.

---

### Why should you use this site?

Well everyone should be encouraged to work on their own solutions (why else were you doing those questions?), from time to time, it could be frustrated when you just can't get your solution going. Well there is a forum on the site where many has participated to communicate their solutions, it is not accessible unless you have solved the problem.

Well I can't tell how efficient my solutions are, those are definitely a possible way of thinking out of many. And hopefully my explanations could guide you for your success.

---

### What if the answer is incorrect?

Do note that occasionally **Project Euler** would change the parameter of certain question to avoid brute force solving. However, if you have followed my explanation, or read how my code actually works, it should be trivial to find the new solution.

However, feel free to create an issue on this repository!

---

### What if the code does not run?

Many of my code should work with only standard C++ libraries, if any of them require C++17 or later, I will have them noted down. However, you should be preparing for at least C++11 to make sure most of them work properly.

There are many others that require a "BigInt" library. I have implemented my own, however they are not quite optimized in a way that I'm ready to share. There are many other big integer library available online. Even "boost" `int1024_t` and `uint1024_t` should work for most of the questions that require a larger number library than normal `int64_t`. While they are simple, do prepare to write your own `factorial()` or `absolute()` when they are needed.
