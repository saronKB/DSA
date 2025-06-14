/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee> idToEmployeeMap;

        for (Employee* empPtr : employees) {
            if (empPtr) {
                idToEmployeeMap[empPtr->id] = *empPtr;
            }
        }

        int totalImportance = 0;
        stack<int> s;
        s.push(id);

        while (!s.empty()) {
            int currentId = s.top();
            s.pop();

            const Employee& currentEmployee = idToEmployeeMap.at(currentId);
            totalImportance += currentEmployee.importance;

            for (int subId : currentEmployee.subordinates) {
                s.push(subId);
            }
        }

        return totalImportance;
    }
};