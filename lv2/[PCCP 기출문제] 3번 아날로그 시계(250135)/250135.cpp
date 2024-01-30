#include <string>
#include <vector>

using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    int starth = h1;
    int startm = m1;
    int starts = s1;
    while(h1 != h2 || m1 != m2 || s1 != s2){
        double nowH = (s1/720.0)+(m1/12.0)+(h1%12)*5;
        double nowM = (s1/60.0)+m1;
        double nowS = s1;
        
        if(nowM == nowH){
            if((starth == 0 && h1 != 12)||(starth == 12 && startm == 0 && starts == 0)) answer++;
        }
        else{
            if(nowS == 59 && nowH > 59 && nowM > 59){
                answer++;
            }
            else{
                if(nowH > nowS && nowH < nowS + 1){
                    answer++;
                }
                if(nowM > nowS && nowM < nowS + 1){
                    answer++;
                }
            }
        }
        s1++;
        if(s1 == 60){
            s1 = 0;
            m1++;
        }
        if(m1 == 60){
            m1 = 0;
            h1++;
        }
        
    }
    
    return answer;
}
