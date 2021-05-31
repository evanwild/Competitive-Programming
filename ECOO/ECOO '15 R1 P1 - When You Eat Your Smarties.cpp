#include <bits/stdc++.h>

using namespace std;

map<string, int> counter;
vector<string> colour_occured;

int main() {
    
    int n=10;
    while (n--) {
        counter.clear();
        colour_occured.clear();
    
    string s;
    while(1) {
        getline(cin, s);
        if(s == "end of box") break;
        
        if(counter.count(s)) {
            counter[s]++;    
        }else {
            counter[s] = 1;
            colour_occured.push_back(s);
        }
    }
    
    int answer=0;
    for (int i=0; i<colour_occured.size(); i++)
    {
        if (colour_occured[i]!="red")
        {
            answer+=ceil(counter[colour_occured[i]]/7.0)*13;
        }
        else
        {
            answer+=counter["red"]*16;
        }
    }
    
    cout<<answer<<endl;
    
    }
    
    return 0;
}