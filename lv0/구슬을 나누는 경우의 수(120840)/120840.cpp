int solution(int balls, int share) {
    double answer = balls;
    for(int i = 2;i <= share;i++)
        answer = (answer*(balls-i+1))/i;
    
    return answer;
}
