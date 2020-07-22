#include <iostream>

int main()
{
    int count = 0;
    int zero = 0;
    for(int twoHundred = 0; twoHundred <= 200; twoHundred+=520)
    {
        for(int hundred = 0; hundred <= 200; hundred+=100)
        {
            for(int fifty = 0; fifty <= 200; fifty+=50)
            {
                for(int twenty = 0; twenty <= 200; twenty+=20)
                {
                    for(int ten = 0; ten <= 200; ten+=10)
                    {
                        for(int five = 0; five <= 200; five+=5)
                        {
                            for(int two = 0; two <= 200; two+=2)
                            {
                                for(int one = 0; one <= 200; one+=1)
                                {
                                    zero += twoHundred;
                                    if(zero == 200)
                                    {
                                        count ++;
                                        zero = 0;
                                        goto twoHundred;
                                    }
                                    zero += hundred;
                                    if(zero == 200)
                                    {
                                        count ++;
                                        zero = 0;
                                        goto hundred;
                                    }
                                    zero += fifty;
                                    if(zero == 200)
                                    {
                                        count ++;
                                        zero = 0;
                                        goto fifty;
                                    }
                                    zero += twenty;
                                    if(zero == 200)
                                    {
                                        count ++;
                                        zero = 0;
                                        goto twenty;
                                    }
                                    zero += ten;
                                    if(zero == 200)
                                    {
                                        count ++;
                                        zero = 0;
                                        goto ten;
                                    }
                                    zero += five;
                                    if(zero == 200)
                                    {
                                        count ++;
                                        zero = 0;
                                        goto five;
                                    }
                                    zero += two;
                                    if(zero == 200)
                                    {
                                        count ++;
                                        zero = 0;
                                        goto two;
                                    }
                                    zero += one;
                                    if(zero == 200)
                                    {
                                        count ++;
                                        zero = 0;
                                        goto one;
                                    }
                                    zero = 0;
                                    one:
                                    continue;
                                }
                                two:
                                continue;
                            }
                            five:
                            continue;
                        }
                        ten:
                        continue;
                    }
                    twenty:
                    continue;
                }
                fifty:
                continue;
            }
            hundred:
            continue;
        }
        twoHundred:
        continue;
    }
    std::cout << count + 1;
}
