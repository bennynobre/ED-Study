#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pos {
    int line, column;
    Pos(int line, int column) : line(line), column(column) {}
};

void show(vector<string>& maze) {
    for(auto elem : maze)
        cout << elem << endl;
}

Pos start(vector<string>& maze) {
    int posColumn = rand() % (maze[0].size() - 2) + 1;
    int posLine = rand() % (maze.size() - 2) + 1; 

    return {posLine, posColumn};
}

bool getPosition(vector<string>& maze, Pos pos) {
    int numLine = maze.size();
    int numColumn = maze[0].size();
    auto [line, column] = pos;
    
    if (line >= numLine - 1 || column >= numColumn - 1 || line < 1 || column < 1) 
        return false;

    return true;
}

vector<Pos> getNeighbor(const Pos& pos) {
    auto [posLine, posColumn] = pos;
    return {{posLine, posColumn - 1}, {posLine + 1, posColumn}, {posLine, posColumn + 1}, {posLine - 1, posColumn}};
}

bool HaveHole(vector<string>& maze, Pos& pos) {
    auto aux = getNeighbor(pos);
    int count = 0;

    if(maze[pos.line][pos.column] == ' ')
        return false;

    for(auto [line, column] : aux) {
        if(line >= int (maze.size()) || column >= int (maze[0].size()) || line < 0 || column < 0)
            continue;

        if(maze[line][column] == '#')
            count++;
    }

    if(count >= 3)
        return true;

    return false;
}

void eraseWall(vector<string>& maze, Pos& pos) {
    auto [line, column] = pos;
    
    if(!getPosition(maze, pos))
        return;
    
    if(HaveHole(maze, pos)) {
        maze[line][column] = ' ';
        auto neighbor = getNeighbor(pos);

        random_shuffle(neighbor.begin(), neighbor.end());

        for(auto elem : neighbor)
            eraseWall(maze, elem);
    } 
}

int main() {
    int numLines {}, numColumns{};

    cout << "Tell the number of lines: ";
    cin >> numLines;

    cout << "Tell the number of columns: ";
    cin >> numColumns;

    vector<string> maze(numLines, string(numColumns, '#'));

    auto init = start(maze);

    eraseWall(maze, init);
    show(maze);

    return 0;
}