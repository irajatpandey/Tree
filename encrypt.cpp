#include<bits/stdc++.h>
using namespace std;


void printCipher(string str, int n){
     vector<pair<char, int>> v(52);
     
     for(int i = 0; i < 26; i++){
         

         v[i].first = 'A' + i;
         v[i].second = 65 + i;
     }

     int j = 0;
     for(int i = 26; i < 52; i++ ){
         
         
         v[i].first = 'a' + j;
         v[i].second = 97 + j;
         j++;
     }

     
    for(auto i : str){
        if(i >= 'A' and i <= 'Z'){
            
            cout << char(( i - 65 + n) % 26 + 65);
        }
        else if(i >= 'a' and i <= 'z')    
           cout << char(( i - 97 + n) % 26 + 97);

        else if(isdigit(i)){
            cout << char((i - 48 + n) % 10 + 48);
        }
        else
            cout << i ;    
    if(isu)
        
    }
     
     
}
int main(){
    
    int n;
    string str;
    cin >> str >> n;
    
    printCipher(str, n);
}