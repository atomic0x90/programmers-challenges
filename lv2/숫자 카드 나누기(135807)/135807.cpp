#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    sort(arrayA.begin(),arrayA.end());
    sort(arrayB.begin(),arrayB.end());
    for(int i = max(arrayA.front(),arrayB.front());i >= 2;i--){
        if((arrayA[0]%i == 0 && arrayB[0]%i == 0)||(arrayA[0]%i != 0 && arrayB[0]%i != 0 )) continue;
        bool flag1 = true, flag2 = true;
        bool flag = true;
        int check1 = -1, check2 = -1;
        
        for(int j = 0;j < arrayA.size();j++){
            if(arrayA[j]%i == 0 && arrayA[j] >= i){
                check1++;
                if(!flag1){
                    flag = false;
                    break;
                }
            }
            if(check1 != j) flag1 = false;
        }
        if(flag){
            for(int j = 0;j < arrayB.size();j++){
                if(arrayB[j]%i == 0 && arrayB[j] >= i){
                    check2++;
                    if(!flag2){
                        flag = false;
                        break;
                    }
                }
                if(check2 != j) flag2 = false;
            }
        }
        if(flag1 != flag2 && 
           (check1 == -1 || check2 == -1) && 
           (check1 == arrayA.size()-1 || check2 == arrayB.size()-1) &&
           flag){
            answer = i;
            break;
        }
    }
    return answer;
}
