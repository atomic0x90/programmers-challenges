#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector<string>v1;
    vector<string>v2;
    int v1size,v2size,check = 0;
    string s1 = "",s2 = "";
    for(int i = 0;i < str1.size();i++) s1 += tolower(str1[i]);
    for(int i = 0;i < str2.size();i++) s2 += tolower(str2[i]);
    
    for(int i = 0;i < s1.size()-1;i++){
        if(s1[i] >= 'a' && s1[i] <= 'z' && s1[i+1] >= 'a' && s1[i+1] <= 'z'){
            string s = "";
            s += char(s1[i]);
            s += char(s1[i+1]);
            v1.push_back(s);
        }
    }
    for(int i = 0;i < s2.size()-1;i++){
        if(s2[i] >= 'a' && s2[i] <= 'z' && s2[i+1] >= 'a' && s2[i+1] <= 'z'){
            string s = "";
            s += char(s2[i]);
            s += char(s2[i+1]);
            v2.push_back(s);
        }
    }
    
    v1size = v1.size();
    v2size = v2.size();
    
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    
    for(int i = 0;i < v1.size();i++){
        for(int j = 0;j < v2.size();j++){
            if(v1[i] == v2[j]){
                check++;
                v2.erase(v2.begin()+j,v2.begin()+j+1);
                break;
            }
        }
    }
    
    if(v1size+v2size-check != 0) answer = 65536*((double)check/(double)(v1size+v2size-check));
    else answer = 65536;
    
    return answer;
}
