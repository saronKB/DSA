class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set visited_rooms = set<int>();
        stack<int> rooms_stack;

        visited_rooms.insert(0);
        rooms_stack.push(0);

        for (int i : rooms[0]) {
            rooms_stack.push(i);
        }
        while (!rooms_stack.empty()) {
            int current_room = rooms_stack.top();
            rooms_stack.pop();

            if (visited_rooms.find(current_room) == visited_rooms.end()) {
                visited_rooms.insert(current_room);

                for (int i : rooms[current_room]) {
                    rooms_stack.push(i);
                }
            }
        }
        return visited_rooms.size() == rooms.size();
    }
};