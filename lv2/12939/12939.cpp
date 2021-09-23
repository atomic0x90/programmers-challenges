#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> v;
    stringstream ss(s);
    
    do{
        int num;
        ss >> num;
        v.push_back(num);
    }while(ss);
    
    answer = to_string(*min_element(v.begin(),v.end()));
    answer += " "+to_string(*max_element(v.begin(),v.end()));
    return answer;
}
