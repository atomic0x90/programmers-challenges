#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(int N, int number) {
    if(N == number) return 1;
    
    vector<set<int> > v(8);
    
    v[0].insert(N);
    for(int i = 1;i < 8;i++){
        for(int j = 0;j < 8;j++){
            for(int k = 0;k < 8;k++){
                if(i != j+k+1) continue;
                
                for(auto iter1 = v[j].begin();iter1 != v[j].end();iter1++){
                    for(auto iter2 = v[k].begin();iter2 != v[k].end();iter2++){
                        v[i].insert((*iter1)+(*iter2));
                        v[i].insert((*iter1)-(*iter2));
                        v[i].insert((*iter1)*(*iter2));
                        if(*iter2 != 0) v[i].insert((*iter1)/(*iter2));
                    }
                }
            }
        }
        int sum = N;
        for(int j = 0;j < i;j++) sum = sum * 10 + N;
        
        v[i].insert(sum);
        
        if(find(v[i].begin(),v[i].end(),number) != v[i].end()) return i+1;
    }
    
    return -1;
}
