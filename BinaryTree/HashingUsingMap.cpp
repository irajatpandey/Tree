#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--){
        string first_str;
        string second_str;
        cin >> first_str;
        cin >> second_str;
        
        unordered_map<char, ll> m;
        
        for(auto i : first_str)
            m[i]++;
            
       for(auto i : m) cout << i.first << " " << i.second << endl;    
            
        for(auto i : second_str) 
            m[i]--;
        
        for(auto i : m) cout << i.first << " " << i.second << endl;    
            
        long count = 0;    
        
        for(auto i : m){
            if(abs(i.second) != 0)
               count += abs(i.second);
            
        }    
        cout << count << endl;
    }
}


