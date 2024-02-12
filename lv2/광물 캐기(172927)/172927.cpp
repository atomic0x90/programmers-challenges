#include <string>
#include <vector>

using namespace std;

int algo(vector<int> &picks, int vt, vector<vector<int>> &value){
    int returnValue;
    if(picks[0] != 0){
        int maxValue = 0;
        int index = 0;
        for(int i = 0;i < vt;i++){
            if(maxValue < value[i][2]){
                maxValue = value[i][2];
                index = i;
            }
        }
        picks[0]--;
        returnValue = value[index][0];
        for(int i = 0;i < 3;i++) value[index][i] = 0;
        return returnValue;
    }
    else if(picks[1] != 0){
        int maxValue = 0;
        int index = 0;
        for(int i = 0;i < vt;i++){
            if(maxValue < value[i][2]){
                maxValue = value[i][2];
                index = i;
            }
        }
        picks[1]--;
        returnValue = value[index][1];
        for(int i = 0;i < 3;i++) value[index][i] = 0;
        return returnValue;
    }
    else{
        int maxValue = 0;
        int index = 0;
        for(int i = 0;i < vt;i++){
            if(maxValue < value[i][2]){
                maxValue = value[i][2];
                index = i;
            }
        }
        picks[2]--;
        returnValue = value[index][2];
        for(int i = 0;i < 3;i++) value[index][i] = 0;
        return returnValue;
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    vector<vector<string>> v(10);
    vector<vector<int>> value(10,vector<int>(3,0));
    int vt = 0;
    
    for(int i = 0;i < minerals.size();i++){
        if(i%5 == 0 && i != 0) vt++;
        v[vt].push_back(minerals[i]);
    }
    
    for(int i = 0;i < v.size();i++){
        int dia = 0, iro = 0, sto = 0;
        for(int j = 0;j < v[i].size();j++){
            if(v[i][j] == "diamond") dia++;
            else if(v[i][j] == "iron") iro++;
            else sto++;
        }
        value[i][0] = dia + iro + sto;
        value[i][1] = (5*dia) + iro + sto;
        value[i][2] = (25*dia) + (5*iro) + sto;
    }
    
    vt++;
    
    if(vt < picks[0] + picks[1] + picks[2]){
        // 곡괭이 남음
        int num = vt;
        while(num != 0){
            answer += algo(picks,vt,value);
            num--;
        }
    }
    else{
        // 곡괭이 다 씀
        vt = picks[0] + picks[1] + picks[2];
        while(picks[0] + picks[1] + picks[2] != 0){
            answer += algo(picks,vt,value);
        }
    }
    
    return answer;
}
