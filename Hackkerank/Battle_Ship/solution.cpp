// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int dfs(vector<string> & board, uint row, uint col) {
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] == '.') return 0;

    int count = 1;
    board[row][col] = '.'; // Visited pixel
    count += dfs(board, row + 1, col);
    count += dfs(board, row - 1, col);
    count += dfs(board, row, col + 1);
    count += dfs(board, row, col - 1);

    return count;
}

vector<int> solution(vector<string> &B) {
    // Implement your solution here
    vector<int> result = {0, 0, 0};
    uint8_t width = B[0].length();
    uint8_t height = B.size();
    for (uint8_t i = 0; i < height; i++) {
        for (uint8_t j = 0; j < width; j++) {
            if (B[i][j] == '#') {
                uint8_t size = dfs(B, i, j);

                if ( size < 1 || size > 3) continue; // Invalid shape

                result[size-1]++;
            }
        }
    }
    return result;
}
