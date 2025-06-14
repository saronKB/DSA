class Solution {
public:
    void exploreProvinces(int startingCity, int totalCities, vector<vector<int>>& connections, vector<bool>& citiesVisited) {
        stack<int> citiesToVisitStack;
        citiesToVisitStack.push(startingCity);
        citiesVisited[startingCity] = true;

        while (citiesToVisitStack.empty() == false) {
            int currentCity = citiesToVisitStack.top();
            citiesToVisitStack.pop();

            for (int otherCity = 0; otherCity < totalCities; ++otherCity) {
                if (connections[currentCity][otherCity] == 1 && citiesVisited[otherCity] == false) {
                    citiesVisited[otherCity] = true;
                    citiesToVisitStack.push(otherCity);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int numberOfCities = isConnected.size();
        vector<bool> hasBeenVisited(numberOfCities, false);
        int howManyProvinces = 0;

        for (int i = 0; i < numberOfCities; ++i) {
            if (hasBeenVisited[i] == false) {
                howManyProvinces++;
                exploreProvinces(i, numberOfCities, isConnected, hasBeenVisited);
            }
        }
        return howManyProvinces;
    }
};