#include <string>
#include <vector>
#include <utility>

using namespace std;

int solution(string s) {
    int answer = 0;
    for(int i = 1;i <= (s.size()/2)+1;i++){
        int check = 0;
        int ssize = 0;
        string st = "";
        vector <pair<string,int> > v;
        for(int j = 0;j < s.size();j++){
            check++;
            st += s[j];
            if(check == i){
                if(!v.empty()){
                    if(v.back().first == st) v.back().second++;
                    else v.push_back(make_pair(st,1));
                }
                else v.push_back(make_pair(st,1));
                check = 0;
                st = "";
            }
        }
        if(s.size()%i != 0) ssize = s.size()%i;
        
        for(int j = 0;j < v.size();j++){
            if(v[j].second == 1) ssize += i;
            else{
                int tmp = 0;
                int tmp1 = v[j].second;
                while(tmp1 != 0){
                    tmp++;
                    tmp1 /= 10;
                }
                ssize += i + tmp;
            }
        }
        if(answer == 0 || answer > ssize) answer = ssize;
    }
    return answer;
}
