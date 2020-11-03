#include <iostream>
#include<vector>

int main()
{
    int n;
    std::cin >> n;
    int stackSize = 0, maxStackSize = 0, maxStackSizeIndex = 0;
    int maxItem = 0, maxIndex = 0, last = 0;
    std::vector<int> maxSymbolsStack;
    for (int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;
        if (a == 1)
        {
            stackSize++;
            if (stackSize > maxStackSize)
            {
                maxStackSize = stackSize;
                maxStackSizeIndex = i + 1;
            }
        }
        if (a == 2)
        {
            stackSize--;
            if (stackSize == 0)
            {
                // maxSymbolsStack.push_back(i + 1);
                if((i+1) - last > maxItem){
                    maxItem = (i+1) - last;
                    maxIndex = last+1;
                }
                last = i+1;
            }
        }
    }
    // for (int i = 0; i < maxSymbolsStack.size() - 1; i++)
    // {
    //     if ((maxSymbolsStack[i + 1] - maxSymbolsStack[i]) > maxItem)
    //     {
    //         maxItem = (maxSymbolsStack[i + 1] - maxSymbolsStack[i]);
    //         maxIndex = maxSymbolsStack[i] + 1;
    //     }
    // }

    std::cout << maxStackSize << " " << maxStackSizeIndex << " " << maxItem << " " << maxIndex;

    return 0;
}