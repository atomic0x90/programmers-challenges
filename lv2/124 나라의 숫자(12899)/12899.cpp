#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string s = "";
    vector <int> v;
    long result = 0;
    
    while(n != 0){
        if(n % 3 == 1) v.push_back(1);
        else if(n % 3 == 2) v.push_back(2);
        else v.push_back(4);
        
        if(n%3 == 0){
            n /= 3;
            n--;
        }
        else n /= 3;
    }
    
    reverse(v.begin(),v.end());
    
    for(int i = 0;i < v.size();i++)
        result = result*10 + v[i];
    
    s = to_string(result);
    
    return s;
}
