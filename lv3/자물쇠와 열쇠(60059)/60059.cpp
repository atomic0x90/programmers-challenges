#include <string>
#include <vector>
using namespace std;

vector<vector<int>> c90(vector<vector<int>>key){
    vector<vector<int>> tmp(key.size(),vector<int>(key.size(),0));
    for(int i = 0;i < key.size();i++){
        for(int j = 0;j < key[i].size();j++){
            tmp[i][j] = key[key[i].size()-j-1][i];
        }
    }
    return tmp;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int M = key.size(),N = lock.size();
    
    for(int i = 0;i < M+N-1;i++){
        for(int j = 0;j < M+N-1;j++){
            vector<vector<int>> tkey = key;
            int check = 0;
            
            do{
                vector<vector<int>>field((2*M)+N-2,vector<int>((2*M)+N-2,0));
                
                for(int k = 0;k < M;k++){
                    for(int l = 0;l < M;l++){
                        field[k+i][l+j] = tkey[k][l];
                    }
                }
                
                for(int k = 0;k < N;k++){
                    for(int l = 0;l < N;l++){
                        if(lock[k][l] == 0) continue;
                        else if(lock[k][l] == 1)
                            field[k+M-1][l+M-1] == 0 ? field[k+M-1][l+M-1] = lock[k][l] : field[k+M-1][l+M-1] = 0;
                    }
                }

                bool flag = true;
                
                for(int k = M-1;k < M+N-1;k++){
                    for(int l = M-1;l < M+N-1;l++){
                        if(field[k][l] == 0) flag = false;
                    }
                }
                
                if(flag) return true;
                
                tkey = c90(tkey);
            }while(check++ < 4);
        }
    }
   
    return false;
}
