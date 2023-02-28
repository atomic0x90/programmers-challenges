#include <string>

using namespace std;

bool prime(long num){
    if(num <= 1) return false;
    
    bool flag = true;
    for(long i = 2;i*i <= num;i++){
        if(num%i == 0){
            flag = false;
            break;
        }
    }
    return flag;
}

int solution(int n, int k) {
    int answer = 0;
    string s = "";
    while(n){
        s = to_string(n%k) + s;
        n /= k;
    }
    
    string ts = "";
    for(int i = 0;i < s.size();i++){
        if(s[i] == '0'){
            if(ts != ""){
                if(prime(stol(ts))) answer++;
                
                ts = "";
            }
        }
        else ts += s[i];
    }
    
    if(ts != ""){
        if(prime(stol(ts))) answer++;
    }
    
    return answer;
}
