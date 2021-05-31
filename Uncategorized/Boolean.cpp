#include <bits/stdc++.h>
using namespace std;
char c;
int n=0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        cin>>c;
        if(c=='n')n++;
        else if(c=='s'){cout<<(n%2==0?"False":"True")<<"\n";break;}
        else if(c=='e'){cout<<(n%2==0?"True":"False")<<"\n";break;}
    }
    return 0;
}