#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<int> vec[3][2][2][2];
    vector<vector<string> > v(info.size());
    vector<vector<string> > qu(query.size());
    
    for(int i = 0;i < info.size();i++){
        stringstream ss(info[i]);
        for(int j = 0;j < 5;j++){
            string s;
            ss >> s;
            v[i].push_back(s);
        }
    }
    for(int i = 0;i < query.size();i++){
        stringstream ss(query[i]);
        for(int j = 0;j < 8;j++){
            string s;
            ss >> s;
            if(s != "and") qu[i].push_back(s);
        }
    }
    
    for(int i = 0;i < v.size();i++){
        int a,b,c,d,e;
        for(int j = 0;j < v[i].size()-1;j++){
            if(v[i][j] == "cpp") a = 0;
            else if(v[i][j] == "java") a = 1;
            else if(v[i][j] == "python") a = 2;
            else if(v[i][j] == "backend") b = 0;
            else if(v[i][j] == "frontend") b = 1;
            else if(v[i][j] == "junior") c = 0;
            else if(v[i][j] == "senior") c = 1;
            else if(v[i][j] == "chicken") d = 0;
            else if(v[i][j] == "pizza") d = 1;
        }
        e = stoi(v[i][v[i].size()-1]);
        
        vec[a][b][c][d].push_back(e);
    }
    
    for(int i = 0;i < qu.size();i++){
        int a,b,c,d,e;

        if(qu[i][0] == "cpp") a = 0;
        else if(qu[i][0] == "java") a = 1;
        else if(qu[i][0] == "python") a = 2;
        else if(qu[i][0] == "-") a = -1;
        
        if(qu[i][1] == "backend") b = 0;
        else if(qu[i][1] == "frontend") b = 1;
        else if(qu[i][1] == "-") b = -1;
        
        if(qu[i][2] == "junior") c = 0;
        else if(qu[i][2] == "senior") c = 1;
        else if(qu[i][2] == "-") c = -1;
        
        if(qu[i][3] == "chicken") d = 0;
        else if(qu[i][3] == "pizza") d = 1;
        else if(qu[i][3] == "-") d = -1;
        
        e = stoi(qu[i][4]);
        
        int check = 0;
        
        for(int j = 0;j < 3;j++){
            if(a != j){
                if(a != -1) continue;
            }
            for(int k = 0;k < 2;k++){
                if(b != k){
                    if(b != -1) continue;
                }
                for(int l = 0;l < 2;l++){
                    if(c != l){
                        if(c != -1) continue;
                    }
                    for(int m = 0;m < 2;m++){
                        if(d != m){
                            if(d != -1) continue;
                        }
                        
                        for(int n = 0;n < vec[j][k][l][m].size();n++){
                            if(vec[j][k][l][m][n] >= e) check++;
                        }
                    }
                }
            }
        }
        answer.push_back(check);
    }
    
    return answer;
}
