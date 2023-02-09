#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

bool prime(int n){
    if(n <= 1) return false;
    if(n == 2 || n == 3) return true;

    for(int i = 2;i <= sqrt(n);i++){
        if(n%i == 0) return false;
    } 
    return true;
}

int solution(string numbers) {
    vector<int> v;
    vector<char> s;
    vector<char> tmp;
    set<int> set;
    string st;
    
    for(int i = 0;i < numbers.size();i++) s.push_back(numbers[i]);
    
    sort(s.begin(),s.end());
    
    for(int i = 1;i <= numbers.size();i++){
        v.clear();
        
        for(int j = 0;j < numbers.size();j++) v.push_back(0);
        for(int j = 0;j < i;j++) v[j] = 1;
        sort(v.begin(),v.end());
        
        do{
            tmp.clear();
            for(int j = 0;j < v.size();j++){
                if(v[j] == 1) tmp.push_back(s[j]);
            }
            
            do{
                st = "";
                for(int j = 0;j < tmp.size();j++) st += tmp[j];
                
                if(prime(stoi(st))) set.insert(stoi(st));
                
            }while(next_permutation(tmp.begin(),tmp.end()));
        }while(next_permutation(v.begin(),v.end()));
    }
    return set.size();
}
