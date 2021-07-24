#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int check;
    queue<pair<int,int> > q;
    vector<int> answer(2);
    
    vector<vector<int> > visit(picture.size(),vector<int>(picture[0].size(),0));
    
    for(int i = 0;i < picture.size();i++){
        for(int j = 0;j < picture[i].size();j++){
            if(picture[i][j] == 0) visit[i][j] = 1;
        }
    }
    
    for(int i = 0;i < visit.size();i++){
        for(int j = 0;j < visit[i].size();j++){
            if(visit[i][j] == 0){
                check = 1;
                visit[i][j] = 1;
                q.push(make_pair(i,j));
                
                while(!q.empty()){
                    if(q.front().second-1 >= 0){
                        if(visit[q.front().first][q.front().second-1] == 0 && picture[q.front().first][q.front().second] == picture[q.front().first][q.front().second-1]){//up
                            q.push(make_pair(q.front().first,q.front().second-1));
                            check++;
                            visit[q.front().first][q.front().second-1] = 1;
                        }
                    }
                    if(q.front().second+1 < visit[q.front().first].size()){
                        if(visit[q.front().first][q.front().second+1] == 0 && picture[q.front().first][q.front().second] == picture[q.front().first][q.front().second+1]){//down
                            q.push(make_pair(q.front().first,q.front().second+1));
                            check++;
                            visit[q.front().first][q.front().second+1] = 1;
                        }
                    }
                    if(q.front().first-1 >= 0){
                        if(visit[q.front().first-1][q.front().second] == 0 && picture[q.front().first][q.front().second] == picture[q.front().first-1][q.front().second]){//left
                            q.push(make_pair(q.front().first-1,q.front().second));
                            check++;
                            visit[q.front().first-1][q.front().second] = 1;
                        }
                     }
                    if(q.front().first+1 < visit.size()){
                        if(visit[q.front().first+1][q.front().second] == 0 && picture[q.front().first][q.front().second] == picture[q.front().first+1][q.front().second]){//right
                            q.push(make_pair(q.front().first+1,q.front().second));
                            check++;
                            visit[q.front().first+1][q.front().second] = 1;
                        }
                    }
                    q.pop();
                }
                number_of_area++;
                if(max_size_of_one_area < check) max_size_of_one_area = check;
             }
        }
    }
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    return answer;
}
