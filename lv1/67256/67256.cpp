#include <string>
#include <vector>
#include <cstdlib>

using namespace std;
int key[4][3] = {1,2,3,4,5,6,7,8,9,-1,0,-1};

int gap(int num,int l,int r){
    int numX,numY,lX,lY,rX,rY;
    int flag = 0;
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 3;j++){
            if(num == key[i][j]){
                numX = i;
                numY = j;
                flag = 1;
                break;
            }
        }
        if(flag == 1) break;
    }
    flag = 0;
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 3;j++){
            if(l == key[i][j]){
                lX = i;
                lY = j;
                flag = 1;
                break;
            }
        }
        if(flag == 1) break;
    }
    flag = 0;
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 3;j++){
            if(r == key[i][j]){
                rX = i;
                rY = j;
                flag = 1;
                break;
            }
        }
        if(flag == 1) break;
    }
    int gapr,gapl;
    gapr = abs(numX - rX) + abs(numY - rY);
    gapl = abs(numX - lX) + abs(numY - lY);
    if(gapr > gapl) return -1;
    else if(gapr == gapl) return 0;
    else return 1;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int nowl = -1;
    int nowr = -1;
    for(int i = 0;i < numbers.size();i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            nowl = numbers[i];
            answer += "L";
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            nowr = numbers[i];
            answer += "R";
        }
        else{
            int flag = gap(numbers[i],nowl,nowr);
            if(flag == -1){
                nowl = numbers[i];
                answer += "L";
            }
            else if(flag == 1){
                nowr = numbers[i];
                answer += "R";
            }
            else{
                if(hand == "left"){
                    nowl = numbers[i];
                    answer += "L";
                }
                else{
                    nowr = numbers[i];
                    answer += "R";
                }
            }
        }
    }
    
    return answer;
}
