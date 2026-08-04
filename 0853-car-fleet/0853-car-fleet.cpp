class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       vector<pair<int, double>> cars(speed.size());
       for(int i = 0;i < speed.size();i++){
        double arrivalTime = (double) (target - position[i]) / (double) speed[i];
        pair<int, double> newPair = { position[i], arrivalTime };
        cars[i] = newPair;
       } 
       sort(cars.begin(), cars.end());

       int numFleets = 1;
       double earliestTime = cars.back().second;
       for(int i = cars.size() - 2;i >= 0;i--){
        if(cars[i].second > earliestTime){
            numFleets++;
            earliestTime = cars[i].second;
        }
       }
       return numFleets;
    }
};
