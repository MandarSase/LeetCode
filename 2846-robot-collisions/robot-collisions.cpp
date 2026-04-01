struct Robot {
    int index;
    int position;
    int health;
    char direction;
};

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths,
                                      string directions) {
        int n = positions.size();
        vector<Robot> robots;
        robots.reserve(n);

        
        for (int i = 0; i < n; ++i) {
            robots.push_back({i, positions[i], healths[i], directions[i]});
        }

        
        sort(robots.begin(), robots.end(),
             [](const Robot& a, const Robot& b) {
                 return a.position < b.position;
             });

        vector<Robot> st;  
        st.reserve(n);

        for (auto& robot : robots) {
            if (robot.direction == 'R') {
                st.push_back(robot);
                continue;
            }

            
            while (!st.empty() && st.back().direction == 'R' && robot.health > 0) {
                Robot& top = st.back();

                if (top.health == robot.health) {
                    st.pop_back();
                    robot.health = 0;
                } 
                else if (top.health < robot.health) {
                    st.pop_back();
                    robot.health--;
                } 
                else {
                    top.health--;
                    robot.health = 0;
                }
            }

            if (robot.health > 0) {
                st.push_back(robot);
            }
        }

        
        sort(st.begin(), st.end(),
             [](const Robot& a, const Robot& b) {
                 return a.index < b.index;
             });

        vector<int> result;
        result.reserve(st.size());

        for (const auto& r : st) {
            result.push_back(r.health);
        }

        return result;
    }
};