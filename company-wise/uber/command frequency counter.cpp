// You are given an array of commands. There are only three possible commands: cmd1, cmd2, and cmd3. Your task is to return an array of size 3 that contains the frequency of each command in the input array, in the order [frequency of cmd1, frequency of cmd2, frequency of cmd3].

// Also, any element in the form of ![index] refers to the same command that was present at the position in the input array. Note that indexing starts from 1 (not 0).

// Function Description

// Complete the function commandFrequencyCounter in the editor.

// commandFrequencyCounter has the following parameter:

// String[] commands: an array of commands
// Returns

// int[]: an array of size 3 containing the frequency of each command

// Example 1:

// Input:  commands = ["cmd1", "cmd2", "cmd3", "!1", "!2", "cmd3", "cmd1"]
// Output: [3, 2, 2] 
// Explanation:


// At index 4 (!1), the command is the same as the command at index 1 (cmd1).

// At index 5 (!2), the command is the same as the command at index 2 (cmd2).
#include<iostream>
#include<string>
#include <vector>

using namespace std;

vector<int> commandFrequencyCounter(vector<string> commands){
    vector<int> ans(3, 0);
    for(auto cmd : commands) {
        if(cmd == "cmd1")
            ans[0]++;
        else if(cmd == "cmd2")
            ans[1]++;
        else if(cmd == "cmd3")
            ans[2]++;
        else{
            findcmd(cmd, commands, ans);
        }
    }
    return ans;
}

void findcmd(string cmd, vector<string>& commands, vector<int>& ans){
    if(cmd == "cmd1") {
        ans[0]++;
        return;
    }
    else if(cmd == "cmd2") {
        ans[1]++;
        return;
    } else if(cmd == "cmd3"){
        ans[2]++;
        return;
    }
    string num(cmd.begin() + 1, cmd.end());
    int index = stoi(num) - 1;
    findcmd(commands[index], commands, ans);
}