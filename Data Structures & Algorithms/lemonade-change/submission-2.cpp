class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;
        bool flag = true;
        for(auto &i:bills){
            int rem = i-5;
            if(rem == 0){
                five++;
            }
            else if(rem == 5){
                if(five==0){
                    return false;
                }
                ten++;
                five--;
            }
            else if(rem == 15){
                if(ten > 0 && five <= 0){
                    return false;
                }
                else if(ten <= 0 && five < 3){
                    return false;
                }
                else{
                    if(ten>0&&five>0){
                        five--;
                        ten--;
                    }
                    else{
                        five-=3;
                    }
                }
            }
        }
        return true;
    }
};