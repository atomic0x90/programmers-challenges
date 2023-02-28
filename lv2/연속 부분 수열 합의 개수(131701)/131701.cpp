#include <set>
#include <vector>

using namespace std;

int solution(vector<int> elements) {
    int elementsSize = elements.size();
    set<int> s;
    
    for(int i = 0;i < elementsSize;i++) elements.push_back(elements[i]);
    
    for(int i = 0;i < elementsSize;i++){
        for(int j = 1;j <= elementsSize;j++){
            int sum = 0;
            for(int k = 0;k < j;k++) sum += elements[i+k];
            
            s.insert(sum);
        }
    }
    
    return s.size();
}
