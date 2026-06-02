class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Land -> Water
                int finishLand = landStartTime[i] + landDuration[i];
                int finishLW =
                    max(finishLand, waterStartTime[j]) + waterDuration[j];

                // Water -> Land
                int finishWater = waterStartTime[j] + waterDuration[j];
                int finishWL =
                    max(finishWater, landStartTime[i]) + landDuration[i];

                ans = min(ans, min(finishLW, finishWL));
            }
        }

        return ans;
    }
};