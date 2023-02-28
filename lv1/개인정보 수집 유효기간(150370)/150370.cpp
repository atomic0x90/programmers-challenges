#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int year = stoi(today.substr(0,4));
    int month = stoi(today.substr(5,7));
    int day = stoi(today.substr(8));
    
    for(int i = 0;i < privacies.size();i++){
        int tYear = stoi(privacies[i].substr(0,4));
        int tMonth = stoi(privacies[i].substr(5,7));
        int tDay = stoi(privacies[i].substr(8,10));
        char term = privacies[i].back();
        
        for(int j = 0;j < terms.size();j++){
            stringstream ss(terms[j]);
            string a,b;
            ss>>a>>b;
            if(a[0] == term){
                int mon = stoi(b);
                tYear += mon/12;
                mon %= 12;
                tMonth += mon;
                if(tMonth > 12){
                    tYear++;
                    tMonth -= 12;
                }
                
                tDay--;
                if(tDay == 0){
                    tDay = 28;
                    tMonth--;
                    if(tMonth == 0){
                        tMonth = 12;
                        tYear--;
                    }
                }
                
                if(year > tYear ||
                   (year == tYear && month > tMonth) ||
                   (year == tYear && month == tMonth && day > tDay))
                    answer.push_back(i+1);
                
                break;
            }
        }
    }
    
    return answer;
}
