#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a,string b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector <string> s;
    for(int i = 0;i < numbers.size();i++) s.push_back(to_string(numbers[i]));
    
    sort(s.begin(),s.end(),compare);
    
    for(int i = 0;i < s.size();i++) answer += s[i];
    
    return answer[0] == '0' ? "0" : answer;
}
