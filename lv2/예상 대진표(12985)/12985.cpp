#include <algorithm>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    int mi,ma;
    mi = min(a,b);
    ma = max(a,b);
    while( (mi-1)/2 != (ma-1)/2 ){
        mi%2 == 0 ? mi /= 2 : mi = mi/2 + 1;
        ma%2 == 0 ? ma /= 2 : ma = ma/2 + 1;
        answer++;
    }
    

    return answer;
}
