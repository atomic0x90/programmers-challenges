int solution(int a, int b, int n) {
    int answer = 0;
    while(n >= a){
        int num = n;
        int ret = 0;
        while(num >= a){
            num -= a;
            ret += b;
        }
        n = num+ret;
        answer += ret;
    }
    return answer;
}
