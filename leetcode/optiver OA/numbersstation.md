Q1) Numbers Station
A friend asks you to tune into a lecal numbers station, a radio station that is publishing a coded message. They say they've had a tip on how to decipher the messages the station is publishing, but want your help in writing a program that will do the deciphering. You start listening to the station and notice that in each voice sample the person reads out a number follow by letter or a hyphen '-'. The numbers don't seem to be in any particular order...

- Every sample will contain a number which can be used to put the messages in order (sequerice (D).

- Every message only contains the letters a-z.
- A complete message is a continuous set of characters surrounded by two - characters.
- Sometimes a message is never completed (missing sequence IDs).
- Once you've completed a full message, all messages completed later with a lower sequence iD are no longer useful and shouldnt be output (you should only output the latest message).
- if two full messages are completed at the same time, then you should output only the message containing higher sequence IDS.
- A full broadcast can contain multiple complete messages ano you will need to output each of them.
Function Description
You are to implement the function Processsample that takes:

a sequence number for the sample,
the character for the sample.
Whenever a full message is completed you should call
the OnMessageComplete function with the completed message.

Constraints
0 < sequence id <= 2^64 - 1

number of messages 5 * 10^5

Input Format
For each line, the first string is the sequense number associated with
the sample, the second character is the character related to the
sequence number

Sample Case 0
Sample input

1 -
2 h
3 e
4 y
5 -
6 b
7 -
Sample Output
hey

Sample Case 1
Sample input

1 -
2 h
3 e
5 -
6 b
7 y
8 e
9 -
4 y
Sample Output
bye

sample input
1 -
2 b
3 y
4 -
6 h
7 i
8 -
4 e
sample output 
hi
Explanation - When placed in order according to their sequence ids we get -bye-hi- this broadcast contains two complete messages ('bye' and 'hi'), but because the second complete message('hi') was completed before the first('bye'), we only output the later message('hi')

sample input
1 -
2 h
3 e
4 l
5 l
6 o
7 -
8 b
9 y
10 e
11 -

sample output
hello
bye

Explanation - When placed in order according to their subsequence ids we get -hello-bye- this broadcast contains two complete messages ('hello' and 'bye'), since the first complete message ('hello') is finished first, we output it. Then when sequence id 11 '-' completes the second message ('bye') we output that as well.


Boiler-plate code

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class IPrinter
{
public:
    virtual ~IPrinter() = default;
    virtual void OnMessageComplete(const std::string &message) const = 0;
};

class Printer
    : public IPrinter
{
public:
    void OnMessageComplete(const std::string &message) const override
    {
        std::cout << message << std::endl;
    }
};

class Decoder
{
public:
    Decoder(const IPrinter &printer)
        : mPrinter(printer)
    {
    }

    void ProcessSample(const uint64_t sequence, const char character)
    {
        /* complete your function and call mPrinter.OnMessageComplete when completing a message */
    }

    const IPrinter &mPrinter;
};

int main()
{
    Printer printer;
    Decoder decoder(printer);

    uint64_t seqNum;
    char message;

    while (!std::cin.eof())
    {
        std::cin >> seqNum >> message;
        if (std::cin.eof())
            break;
        decoder.ProcessSample(seqNum, message);
    }

    return 0;
}