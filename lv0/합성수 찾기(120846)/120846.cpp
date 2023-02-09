int solution(int n) {
    int answer = 0;
    for(int i = 4;i <= n;i++){
        int check = 0;
        for(int j = 1;j <= i;j++){
            if(i%j == 0) check++;
            if(check >= 3){
                answer++;
                break;
            }
        }
    }
    return answer;
}
