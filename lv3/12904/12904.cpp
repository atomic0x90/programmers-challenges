#include <string>
using namespace std;
int solution(string s){
    int answer = 0;
    
    for(int i = s.size();i > 1;i--){
        
        for(int j = 0;j< s.size();j++){
            if(i+j > s.size()) break;
            
            int start = j,end = i+j-1;
            
            while(start < end){
                if(s[start] != s[end]) break;
                start++;
                end--;
            }
            
            if(start >= end) return i;
        }
    }
    return 1;
}
