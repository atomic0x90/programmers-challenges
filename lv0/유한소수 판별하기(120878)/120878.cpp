int solution(int a, int b) {
    if(a > b){
        while(b != 1){
            int tmp = b;
            bool flag = true;
            while(tmp > 1){
                if(a % tmp == 0 && b % tmp == 0){
                    a /= tmp;
                    b /= tmp;
                    flag = false;
                    break;
                }
                tmp--;
            }
            if(flag) break;
        }
        
        while(b > 1 && (b % 2 == 0 || b % 5 == 0)){
            if(b%2 == 0) b /= 2;
            else if(b%5 == 0) b /= 5;
        }
        
        return b == 1 ? 1 : 2;
    }
    else if(a < b){
        while(a != 1){
            int tmp = a;
            bool flag = true;
            while(tmp > 1){
                if(b % tmp == 0 && a % tmp == 0){
                    b /= tmp;
                    a /= tmp;
                    flag = false;
                    break;
                }
                tmp--;
            }
            if(flag) break;
        }
        
        while(b > 1 && (b % 2 == 0 || b % 5 == 0)){
            if(b%2 == 0) b /= 2;
            else if(b%5 == 0) b /= 5;
        }
        
        return b == 1 ? 1 : 2;
    }
    else return 1;
}
