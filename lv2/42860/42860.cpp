#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int solution(string name) {
    int answer = 0;
    int a,b,check = 0,now = 0;
    char s1,s2;
    vector<pair<int,int> > v;
    
    for(int i = 0;i < name.size();i++){
        if(name[i] == 'A') v.push_back(make_pair(0,0));
        else{
            a = b = 0;
            s1 = s2 = name[i];
            
            while(s1 != 'A'){
                s1--;
                a++;
            }
            while(true){
                s2++;
                b++;
                if(s2 == 'Z'){
                    b++;
                    break;
                }
            }
            
            v.push_back(make_pair(1,min(a,b)));
            check++;
        }
    }
    
    while(check){
        int a1 = 0,b1 = 0;
        a = b = 0;
        if(v[now].first == 1){
            answer += v[now].second;
            v[now].first = 0;
            check--;
        }
        else{
            for(auto iter = v.begin()+now;;){
                if(iter->first == 1){
                    a1 = abs(iter - v.begin());
                    break;
                }
                else{
                    a++;
                    if(iter == v.end()) iter = v.begin();
                    else iter++;
                }
            }
            for(auto iter = v.begin()+now;;){
                if(iter->first == 1){
                    b1 = abs(iter - v.begin());
                    break;
                }
                else{
                    b++;
                    if(iter == v.begin()) iter = v.end()-1;
                    else iter--;
                }
            }
            if(a > b){
                now = b1;
                answer += b;
            }
            else{
                now = a1;
                answer += a;
            }
        }
    }
    
    return answer;
}
