/*

ByteDance has launched a new feature on TikTok called "TikTok Collectibles," where users can collect and trade digital cards featuring popular TikTok creators. Each creator has different categories of cards, such as rare cards for the most followed creators, special edition cards with unique designs, and interactive cards that come with exclusive video content.

ByteDance wants to create a number of collectible packs, each containing equal numbers of each type of card. To achieve this, they need to add more cards to ensure each type can be evenly distributed across the packs.
Given the current inventory of each category of cards as an integer array cardTypes of size n, determine the minimum number of additional cards needed so that they can create more than one pack with an equal type distribution.

Example
n = 5
cardTypes = [4, 7, 5, 11, 15]
In order to make 2 matching packets, the following numbers of additional cards of each type must be added: [0, 1, 1, 1, 1]. This sums to 4 additional cards. The numbers of cards are [4, 8, 6, 12, 16] and they can be divided evenly among 2 packets.
If 3 packets are created, an additional [2, 2, 1, 1, 0] cards are needed, sum = 6 items. This yields quantities [6, 9, 6, 12, 15]. Any number of packets ≥ 2 can be created, but creating 2 packets requires the minimum number of additional cards.

Function Description
Complete the function cardPackets in the editor below.

cardPackets has the following parameter(s):

int cardTypes[n]: the quantity available of card type
Returns
int: the minimum number of additional cards to add
Constraints
1 ≤ n ≤ 10^5
1 ≤ cardTypes[i] ≤ 500
Input Format For Custom Testing
Sample Input For Custom Testing
5
3
8
7
6
4
Sample Output
2
Explanation
For 2 packets add: [1, 0, 1, 0, 0] (2 cards) to get [4, 8, 8, 6, 4].

For 3 add [0, 1, 2, 0, 2] (5 cards) to get [3, 9, 9, 6, 6].

Any number of packets ≥ 2 can be created, but making 2 packets requires the minimum number of additional cards.

Sample Case 1
Sample Input For Custom Testing
6
3
9
7
6
5
2
Sample Output
4
Explanation
To make 2 packets, add [1, 1, 1, 0, 1, 0] (4 additional cards) to get [4, 10, 8, 6, 6, 4].

For 3 packets, add [0, 0, 2, 0, 1, 1] (4 additional cards) to get [3, 9, 9, 6, 6, 3].

Either of these solutions is minimal.


hint : This problem requires minimizing the number of additional cards needed to evenly distribute existing cards into multiple packs. 
The key is to find the smallest divisor that allows the quantities of each card type to be evenly divisible. 
By iterating through possible divisor values, calculate the minimum number of additional cards needed for each case, and choose the smallest total as the final answer.
*/

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int cardPackets(const vector<int>& cardTypes) {
    int n = cardTypes.size();
    int min_additional_cards = INT_MAX;

    // Find the maximum value in cardTypes
    int max_card_count = *max_element(cardTypes.begin(), cardTypes.end());

    // Iterate over possible divisors from 2 to max_card_count
    for (int divisor = 2; divisor <= max_card_count; ++divisor) {
        int additional_cards = 0;
        for (int card_count : cardTypes) {
            additional_cards += (divisor - (card_count % divisor)) % divisor;
        }
        min_additional_cards = std::min(min_additional_cards, additional_cards);
    }

    return min_additional_cards;
}

int main() {
    vector<int> cartTypes = {4,7,5,11,15};
    cout<<cardPackets(cartTypes)<<"\n";

    cartTypes = {3,8,7,6,4};
    cout<<cardPackets(cartTypes)<<"\n";

    cartTypes = {3,9,7,6,5,2};
    cout<<cardPackets(cartTypes)<<"\n";

    return 0;

}