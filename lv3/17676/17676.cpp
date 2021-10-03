#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector<int> start;
    vector<int> end;
    for(int i = 0;i < lines.size();i++){
        for(int j = 0;j < lines[i].size();j++){
                if(lines[i][j] == '-' || lines[i][j] == ':') lines[i][j] = ' ';
        }
        stringstream ss(lines[i]);
        int num;
        double h,m,s1,s2;
        ss >> num;
        ss >> num;
        ss >> num;
        ss >> h;
        ss >> m;
        ss >> s1;
        ss >> s2;
        
        h *= 60*60*1000;
        m *= 60*1000;
        s1 *= 1000;
        s2 *= 1000;
        start.push_back(h+m+s1+1-s2);
        end.push_back(h+m+s1);
    }
    
    for(int i = 0;i < start.size();i++){
        int check = 0;
        for(int j = i;j < start.size();j++){
            if(end[i]+1000 > start[j]) check++;
        }
        if(check > answer) answer = check;
    }
    
    return answer;
}
