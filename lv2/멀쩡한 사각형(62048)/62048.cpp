using namespace std;

long long solution(int w,int h) {
    long long answer = 1;
    long long tw = w, th = h;
    long long high,low,r;
    if(tw > th){
        high = tw;
        low = th;
    }
    else{
        high = th;
        low = tw;
    }
    //tw > th ? high = tw,low = th : high = th,low = tw;
    while(low != 0){
        r = high%low;
        high = low;
        low = r;
    }
    answer = (tw*th) - (tw+th-high);
    return answer;
}
