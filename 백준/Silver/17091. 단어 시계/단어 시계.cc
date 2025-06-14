#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int h, m;
string str[31]={
    " ",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "quarter",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
    "twenty",
    "twenty one",
    "twenty two",
    "twenty three",
    "twenty four",
    "twenty five",
    "twenty six",
    "twenty seven",
    "twenty eight",
    "twenty nine",
    "half"
};

int main()
{
    FASTIO;
    cin >> h >> m;
    if(m == 0){
        cout << str[h] <<" o' clock";
    }
    else if(m<=30){
        cout << str[m]; 
        if(m != 15 && m != 30){
            cout << " minute";
            if(m != 1) cout << "s";
        }
        cout << " past " << str[h];
    }
    else{
        cout << str[60-m];
        if(60-m !=  15){
            cout << " minute";
            if(60-m != 1) cout << "s";
        }
        cout << " to " << str[h+1!=13? h+1:1];
    }
    return 0;
}