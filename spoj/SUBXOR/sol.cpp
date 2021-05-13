#include <cstdio>
#include <iostream>
#include <fstream>

#define SPACE 3
using namespace std;
struct TrieNode {
    TrieNode* next[2];
    int cnt;
    TrieNode() {
        next[0] = next[1] = NULL;
        cnt = 0;
    }
};
void insertNum(TrieNode* root, unsigned num) {
    TrieNode* p = root;
    for(int i = 31; i >= 0; i--) {
        int index = (num >> i) & 1;
        if(!p->next[index])
            p->next[index] = new TrieNode();
        p = p->next[index];
        p->cnt++;
    }
}
int getCnt(TrieNode* root) {
    return root ? root->cnt : 0;
}
int queryLessThanK(TrieNode* root, int pre, int k) {
    TrieNode* p = root;
    int ret = 0;
    for(int i = 31; i >= 0; i--) {
        if(p == NULL)
            break;
        int indexPre = (pre >> i) & 1; // prefiexbit
        int indexK = (k >> i) & 1; // bit
        if(indexPre == indexK) {
            if(indexK)
                ret += getCnt(p->next[1]);
            p = p->next[0];
        }
        else if(indexPre != indexK) {
            if(indexK)
                ret += getCnt(p->next[0]);
            p = p->next[1];
        }
    }
    cout<<ret<<" ";
    return ret;
}

struct Trunk
{
    Trunk *prev;
    string str;
 
    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};


void showTrunks(Trunk *p, ofstream * MyFile)
{
    if (p == nullptr) {
        return;
    }
 
    showTrunks(p->prev, MyFile);
    // cout << p->str;
    *MyFile << p->str;
}

void printTree(TrieNode* root, Trunk *prev, bool isLeft, ofstream * MyFile)
{
    if (root == nullptr) {
        return;
    }
 
    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);
 
    printTree(root->next[1], trunk, true, MyFile);
 
    if (!prev) {
        trunk->str = "———";
    }
    else if (isLeft)
    {
        trunk->str = ".———";
        prev_str = "   |";
    }
    else {
        trunk->str = "`———";
        prev->str = prev_str;
    }
 
    showTrunks(trunk, MyFile);
    *MyFile << root->cnt << "\n";
    // cout << root->cnt << endl;
 
    if (prev) {
        prev->str = prev_str;
    }
    trunk->str = "   |";
 
    printTree(root->next[0], trunk, false, MyFile);
}

int main() {
    int nTest; scanf("%d", &nTest);
    while(nTest--) {
        int nNum, k;
        scanf("%d %u", &nNum, &k);
        TrieNode* root = new TrieNode();
                 // insertNum (root, 0) to ensure pre prefix and XOR itself may be less than k
        insertNum(root, 0);
        unsigned pre = 0;
        long long ans = 0;
        while(nNum--) {
            unsigned num; scanf("%u", &num);
            pre = pre ^ num;
            ans += queryLessThanK(root, pre, k);
            // cout<<ans<<" ";
            insertNum(root, pre);
        }
        ofstream MyFile("filename.txt");
        printTree(root, nullptr, false, &MyFile);
        MyFile.close();
        cout << ans << endl;
    }
    return 0;
}