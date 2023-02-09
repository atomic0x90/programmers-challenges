#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    vector<string> overlaps;
    vector<int> checkOverlap;   //1 overlap x ,0 overlap o
    vector<int> permu;
    set <string> overlap;
    vector<string> checkC;
    int num = relation.size();
    
    for(int i = 0;i < relation[0].size();i++){
        overlaps.clear();
        overlap.clear();
        for(int j = 0;j < relation.size();j++) overlaps.push_back(relation[j][i]);
        
        for(int j = 0;j < overlaps.size();j++) overlap.insert(overlaps[j]);

        if(num == overlap.size()){
            checkOverlap.push_back(1);
            checkC.push_back(to_string(i));
            answer++;
        }
        else checkOverlap.push_back(0);
    }
    
    for(int i = 0;i < relation[0].size();i++){
        permu.clear();
        for(int j = 0;j < i+1;j++) permu.push_back(1);
        for(int j = i+1;j < relation[0].size();j++) permu.push_back(0);
        
        sort(permu.begin(),permu.end());

        do{
            bool checkU = false;
            for(int j = 0;j < checkOverlap.size();j++){
                if(permu[j] == 1 && checkOverlap[j] == 1){
                    checkU = true;
                    break;
                }
            }
            if(checkU) continue;
            
            overlap.clear();
            vector<string> st(relation.size(),"");
            string checkper = "";
            for(int j = 0;j < permu.size();j++){
                if(permu[j] == 1){
                    for(int k = 0;k < relation.size();k++){
                        st[k] += relation[k][j];
                    }
                    checkper += to_string(j);
                }
            }
            
            for(int j = 0;j < st.size();j++) overlap.insert(st[j]);
            
            if(overlap.size() == num){
                bool flag = true;
                for(int j = 0;j < checkper.size();j++){
                    vector<int> stpermu;
                    for(int l = 0;l < j+1;l++) stpermu.push_back(1);
                    for(int l = j+1;l < checkper.size();l++) stpermu.push_back(0);
                    sort(stpermu.begin(),stpermu.end());
                    do{
                        string stcheckper = "";
                        for(int k = 0;k < stpermu.size();k++){
                            if(stpermu[k] == 1) stcheckper += checkper[k];
                        }
                        for(int k = 0;k < checkC.size();k++){
                            if(checkC[k] == stcheckper){
                                flag = false;
                                break;
                            }
                        }
                        if(!flag) break;
                    }while(next_permutation(stpermu.begin(),stpermu.end()));
                }
                if(flag){
                    answer++;
                    checkC.push_back(checkper);
                }
            }
        }while(next_permutation(permu.begin(),permu.end()));
    }
    
    return answer;
}
