#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void initTriangle(std::vector<int> &triangle)
{
    int number = 0;
    for(int i = 1; number < 1000; i++)
    {
        number = i * (i + 1) / 2;
        triangle.push_back(number);
    }
}

int getValue(std::string s)
{
    int value = 0;
    for(auto c : s)
    {
        value += c - 'A' + 1;
    }
    return value;
}

void readFile(std::vector<int> &source, std::string file)
{
    std::fstream f;
    f.open(file);
    std::string line;
    while(std::getline(f, line, '\"'))
    {
        if(line != ",")
        {
            source.push_back(getValue(line));
        }
    }
}

int main()
{
    std::vector<int> values;
    readFile(values, "p042_words.txt");
    std::vector<int> triangle;
    initTriangle(triangle);
    int count = 0;
    for(auto a : values)
    {
        for(auto b : triangle)
        {
            if(a == b)
            {
                count++;
            }
        }
    }
    std::cout << count << "\n";
}
