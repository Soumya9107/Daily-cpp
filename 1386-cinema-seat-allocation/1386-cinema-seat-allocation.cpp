class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reservedMap;

        for(const auto& seat : reservedSeats){
            reservedMap[seat[0]] |= (1 << seat[1]);
        }

        int leftMask = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int rightMask = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);
        int middleMask = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);

        int totalGroups = (n - reservedMap.size()) * 2;

        for(const auto& [row, mask] : reservedMap){
            bool leftAvailable = (mask & leftMask) == 0;
            bool rightAvailable = (mask & rightMask) == 0;
            bool middleAvailable = (mask & middleMask) == 0;

            if(leftAvailable && rightAvailable){
                totalGroups += 2;
            }else if(leftAvailable || rightAvailable || middleAvailable){
                totalGroups += 1;
            }
        }
        return totalGroups;
    }

};