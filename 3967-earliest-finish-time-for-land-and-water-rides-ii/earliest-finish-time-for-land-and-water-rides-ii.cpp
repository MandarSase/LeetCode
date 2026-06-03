class Solution {
public:
    long long earliestFinishTime(vector<int>& landStartTime,
                                 vector<int>& landDuration,
                                 vector<int>& waterStartTime,
                                 vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        vector<pair<int,int>> water(m);
        for (int i = 0; i < m; i++)
            water[i] = {waterStartTime[i], waterDuration[i]};

        sort(water.begin(), water.end());

        vector<int> wStart(m);

        vector<long long> prefMinDur(m);
        vector<long long> suffMinFinish(m);

        for (int i = 0; i < m; i++)
            wStart[i] = water[i].first;

        prefMinDur[0] = water[0].second;
        for (int i = 1; i < m; i++)
            prefMinDur[i] =
                min(prefMinDur[i - 1], (long long)water[i].second);

        suffMinFinish[m - 1] =
            (long long)water[m - 1].first + water[m - 1].second;

        for (int i = m - 2; i >= 0; i--)
            suffMinFinish[i] =
                min(suffMinFinish[i + 1],
                    (long long)water[i].first + water[i].second);

        auto bestWaterAfter = [&](long long t) {
            long long res = LLONG_MAX;

            int pos = upper_bound(wStart.begin(), wStart.end(), t)
                      - wStart.begin();

            if (pos > 0)
                res = min(res, t + prefMinDur[pos - 1]);

            if (pos < m)
                res = min(res, suffMinFinish[pos]);

            return res;
        };

        
        vector<pair<int,int>> land(n);
        for (int i = 0; i < n; i++)
            land[i] = {landStartTime[i], landDuration[i]};

        sort(land.begin(), land.end());

        vector<int> lStart(n);
        vector<long long> prefMinLandDur(n);
        vector<long long> suffMinLandFinish(n);

        for (int i = 0; i < n; i++)
            lStart[i] = land[i].first;

        prefMinLandDur[0] = land[0].second;
        for (int i = 1; i < n; i++)
            prefMinLandDur[i] =
                min(prefMinLandDur[i - 1], (long long)land[i].second);

        suffMinLandFinish[n - 1] =
            (long long)land[n - 1].first + land[n - 1].second;

        for (int i = n - 2; i >= 0; i--)
            suffMinLandFinish[i] =
                min(suffMinLandFinish[i + 1],
                    (long long)land[i].first + land[i].second);

        auto bestLandAfter = [&](long long t) {
            long long res = LLONG_MAX;

            int pos = upper_bound(lStart.begin(), lStart.end(), t)
                      - lStart.begin();

            if (pos > 0)
                res = min(res, t + prefMinLandDur[pos - 1]);

            if (pos < n)
                res = min(res, suffMinLandFinish[pos]);

            return res;
        };

        long long ans = LLONG_MAX;

        
        for (int i = 0; i < n; i++) {
            long long finishLand =
                (long long)landStartTime[i] + landDuration[i];

            ans = min(ans, bestWaterAfter(finishLand));
        }

        
        for (int j = 0; j < m; j++) {
            long long finishWater =
                (long long)waterStartTime[j] + waterDuration[j];

            ans = min(ans, bestLandAfter(finishWater));
        }

        return (int)ans;
    }
};