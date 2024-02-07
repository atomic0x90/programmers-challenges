#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int nowAttack = 0;
    int continuity = 0;
    int cool = 0;
    int nowHealth = health;
    for(int i = 1;i <= attacks[attacks.size()-1][0];i++){
        if(attacks[nowAttack][0] == i){
            cool = 0;
            nowHealth -= attacks[nowAttack][1];
            nowAttack++;
            if(nowHealth <= 0) return -1;
        }
        else{
            cool++;
            if(cool == bandage[0]){
                cool = 0;
                nowHealth += bandage[1] + bandage[2];
                nowHealth = nowHealth > health ? health : nowHealth;
            }
            else{
                nowHealth += bandage[1];
                nowHealth = nowHealth > health ? health : nowHealth;
            }
        }
    }
    return nowHealth;
}s
