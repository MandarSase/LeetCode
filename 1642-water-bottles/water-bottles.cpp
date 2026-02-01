class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int BD,EB;
        BD=numBottles;
        EB=numBottles;
      while(EB >= numExchange){
        int a=EB/numExchange;
        int b=EB%numExchange;
        EB=a+b;
        BD+=a;
      }
      

        return BD;
    }
};