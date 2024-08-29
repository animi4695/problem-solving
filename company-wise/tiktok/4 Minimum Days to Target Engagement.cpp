/*
The TikTok team is working on enhancing an AI model that curates personalized content feeds. A performance metric called initialEngagementScore is defined to measure how well the AI is currently performing. The team aims to improve this score to a targetEngagementScore.

There are n data sets available for training, represented by trainingEngagementScore, where trainingEngagementScore[i] denotes the potential improvement from the i-th data set. The AI model can only be trained on a data set if its current engagement score is greater than or equal to the score of the data set. Training the AI on the i-th data set increases its score by trainingEngagementScore[i]. Moreover, the AI model can be trained on each data set only once.

On each day, the team can do either of the following:

Train the AI model on any data set
Manually increase the engagement score of the AI by the number of days since training started.
Your task is to find the minimum number of days required for the AI model to reach the targetEngagementScore.

Function Description

Complete the function minDaysToTargetEngagement in the editor.

minDaysToTargetEngagement has the following parameter(s):

initialScore: an integer representing the initial engagement score
targetScore: an integer representing the target engagement score
trainingScore: an array of integers representing the potential improvement from each data set
Returns

int: the minimum number of days required to reach the target engagement score

Example 1:

Input:  initialScore = 0, targetScore = 30, trainingScore = [15, 3, 2]
Output: 6 
Explanation:
      - On the first 2 days, the score of the AI is increased by 1 and 2 respectively. Score = 0 + 1 + 2 = 3.
      - Then, the AI can be trained on the 2nd data set. Score = 3 + 3 = 6.
      - On the 4th and 5th day, the score of the AI is increased by 4 and 5 respectively. Score = 6 + 4 + 5 = 15.
      - On the 6th day, the AI is trained on the 1st data set. Score = 15 + 15 = 30.

      The AI model reaches the target score on the 6th day. Hence, the minimum number of required days = 6.
*/


#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
#include<queue>

using namespace std;

int minDaysToTargetEngagement(int initialScore, int targetScore, vector<int> trainingScore) {
    int days = 1;
    int currentScore = initialScore;
    // sorting helps to make sure i moves only to the indices that currentScore hasn't reached yet.
    sort(trainingScore.begin(), trainingScore.end());
    int i = 0;
    priority_queue<int> pq;

    while(currentScore < targetScore) {
        // check if the current Score is >= any of the elements from training score
        while(i < trainingScore.size() && currentScore >= trainingScore[i]){
            pq.push(trainingScore[i]);
            i++;
        }

        if(!pq.empty() && pq.top() > days) {
            currentScore += pq.top();
            pq.pop();
        }
        else{
            currentScore += days;
        }

        days++;
    }
    return days;
}

int main() {
    int initialScore = 0, targetScore = 30;
    vector<int> trainingScore = {15, 3, 2};
    cout<<minDaysToTargetEngagement(initialScore, targetScore, trainingScore)<<"\n";

    return 0;
}