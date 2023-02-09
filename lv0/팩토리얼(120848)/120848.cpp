int solution(int n) {
    int answer = 0;
    int result = 1;
    for(int i = 1;;i++){
        result *= i;
        if(n < result) break;
        answer = i;
    }
    return answer;
}
