#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(),phone_book.end());
    
    bool flag = true;
    
    for(int i = 0;i < phone_book.size()-1;i++){
        flag = true;
        if(phone_book[i].size() < phone_book[i+1].size()){
            for(int j = 0;j < phone_book[i].size();j++){
                if(phone_book[i][j] != phone_book[i+1][j]){
                    flag = false;
                    break;
                }
            }
            if(flag) return false;
        }
    }
    
    return true;
}
