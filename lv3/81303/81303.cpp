#include <string>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;

bool Find(pair<int,pair<int,int> > a){
    return a.first;
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    int now = k;
    int low = 0,high = n-1;
    stack<int> del;
    vector<pair<int,pair<int,int> > > v(n);
    for(int i = 0;i < n;i++){
        answer += 'O';
        if(i == 0){
            v[i].first = 1;
            v[i].second.first = -1;
            v[i].second.second = i+1;
        }
        else if(i == n-1){
            v[i].first = 1;
            v[i].second.first = i-1;
            v[i].second.second = -1;
        }
        else{
            v[i].first = 1;
            v[i].second.first = i-1;
            v[i].second.second = i+1;
        }
    }
    
    for(int i = 0;i < cmd.size();i++){
        int sum = 0;
        while(cmd[i][0] == 'U' || cmd[i][0] == 'D'){
            if(cmd[i][0] == 'U'){
                cmd[i][0] = ' ';
                int num = stoi(cmd[i]);
                sum -= num;
            }
            else if(cmd[i][0] == 'D'){
                cmd[i][0] = ' ';
                int num = stoi(cmd[i]);
                sum += num;
            }
            
            if(i < cmd.size()-1) i++;
            else break;
        }
        
        if(sum < 0){
            sum *= -1;
            while(sum){
                now = v[now].second.first;
                sum--;
            }
        }
        else if(sum > 0){
            while(sum){
                now = v[now].second.second;
                sum--;
            }
        }
        
        if(cmd[i][0] == 'C'){
            del.push(now);
            answer[now] = 'X';
            if(v[now].second.second == -1){
                int tmp = v[now].second.first;
                v[now].first = 0;
                v[tmp].second.second = -1;
                now = tmp;
                high = tmp;
            }
            else if(v[now].second.first == -1){
                int tmp = v[now].second.second;
                v[now].first = 0;
                v[tmp].second.first = -1;
                now = tmp;
                low = tmp;
            }
            else{
                int pre = v[now].second.first;
                int post = v[now].second.second;
                v[now].first = 0;
                v[pre].second.second = post;
                v[post].second.first = pre;
    
                now = post;
            }
        }
        else if(cmd[i][0] == 'Z'){
            int check = del.top();
            answer[check] = 'O';
            del.pop();
            if(check < low){
                v[low].second.first = check;
                v[check].first = 1;
                v[check].second.first = -1;
                v[check].second.second = low;
                
                low = check;
                continue;
            }
            else if(check > high){
                v[high].second.second = check;
                v[check].first = 1;
                v[check].second.first = high;
                v[check].second.second = -1;
                
                high = check;
                continue;
            }
            auto it = find_if(v.begin()+check+1,v.end(),Find);

            int sf = it->second.first;
            it->second.first = check;
            v[check].first = 1;
            v[check].second.first = sf;
            v[check].second.second = it-v.begin();
            v[sf].second.second = check;
        }
    }
    
    return answer;
}
