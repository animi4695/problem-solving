#include<iostream>
#include<climits>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;
void splitString(string &str, vector<string> &s){
    size_t pos = 0;
    while( (pos = str.find(".")) != std::string::npos){
        string token = str.substr(0, pos);
        s.push_back(token);
        str.erase(0, pos+1);
    }
}

void delLeadingZeros(string &X, int len){
    for(int i = 0; i < len; i++){
        int temp = X[i]-'0';
        if(!temp) X.erase(0, 1);
        else{
            break;
        }
    }
}

int isGreater(string A, string B){
    auto as = A.length(), bs = B.length();
    int lenGap = as-bs;
    if(lenGap != 0){
        return lenGap >0 ? 1 : -1;
    }
    else if (A != B) return A>B? 1: -1;
    return 0;
}

int compareVersion(string A, string B){
    int i =0, j = 0;
    vector<string> a, b;

    splitString(A, a);
    splitString(B, b);

    // edge case 
    // if there are no dots or to get the last digit
    a.push_back(A);
    b.push_back(B);

    int is = a.size(), js = b.size();

    while (i < is && j < js)
    {
        delLeadingZeros(a[i], a[i].length());
        delLeadingZeros(b[j], b[j].length());

        auto temp = isGreater(a[i], b[j]);

        if(temp != 0){
            return temp;
        }
        else{
            ++i;
            ++j;
            if(i==is && j < js){
                delLeadingZeros(b[j], b[j].length());
                if(b[j] != "") return -1;
            }
            else if( i < is && j == js){
                delLeadingZeros(a[i], a[i].length());
                if(a[i] != "") return 1;
            }
        }
    }
    return 0;
}

int main(){
    string A = "4444371174137455", B = "5.168";
    cout<<compareVersion(A, B);
    return 0;
}