#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string cal(int a){
    string s = "";
    a/60 < 10 ? s += "0"+to_string(a/60)+":" : s += to_string(a/60)+":";
    a%60 < 10 ? s += "0"+to_string(a%60) : s += to_string(a%60);
    return s;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> time;
    vector<vector<int>> bus(n,vector<int>(m,0));
    
    for(int i = 0;i < timetable.size();i++){
        int hour,min;
        hour = ((timetable[i][0]-'0')*10 + (timetable[i][1]-'0'))*60;
        min = (timetable[i][3]-'0')*10 + (timetable[i][4]-'0');
        //if(hour+min != 1439)
            time.push_back(hour+min);
    }
    
    if(time.size() == 0) return cal(540+(n-1)*t);
    
    sort(time.begin(),time.end());
    
    int busTime;
    int check = 0;
    
    for(int i = 0;i < n;i++){
        if(check == time.size()) break;
        busTime = 540 + t*i;
        for(int j = 0;j < m;j++){
            if(busTime >= time[check]){
                bus[i][j] = 1;
                check++;
            }
            if(check == time.size()) break;
        }
    }
    
    if(bus[bus.size()-1][bus[0].size()-1] == 0) return cal(540+(n-1)*t);
    else if(check < time.size()) return cal(time[check-1]-1);
    else return cal(time.back()-1);
}
