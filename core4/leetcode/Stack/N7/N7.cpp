class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = position.size();

        // Store each car as:
        // {position, time needed to reach target}
        vector<pair<int, double>> cars;


        // Calculate arrival time for every car
        for (int i = 0; i < n; i++) {

            // Time = distance / speed
            double time = (double)(target - position[i]) / speed[i];

            // Store position and arrival time
            cars.push_back({position[i], time});
        }


        // Sort cars from closest to target to farthest
        // Example:
        // target = 12
        // positions: 10,8,5,3,0
        sort(cars.rbegin(), cars.rend());


        int fleets = 0;

        // Time of the fleet directly ahead
        double fleet_time = 0;


        // Process cars from front to back
        for(auto& car : cars) {

            int pos = car.first;
            double Time = car.second;


            // If this car takes longer than the fleet ahead,
            // it cannot catch up -> new fleet
            if(Time > fleet_time) {

                fleets++;

                // This becomes the new fleet in front
                fleet_time = Time;
            }

            // Otherwise:
            // Time <= fleet_time
            // The car catches the fleet ahead
            else {

                cout << "Car at position "
                     << pos
                     << " joins fleet\n";
            }
        }


        return fleets;
    }
};
