class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; i <= n; i++) {
            int square = i * i;
            if (square > n) {
                break;
            }
            squares.push_back(square);
        }

        vector<int> counts(n + 1, 10001);
        counts[0] = 0;

        for (int i = 0; i < squares.size(); i++) {
            for (int j = squares[i]; j <= n; j++) {
                counts[j] = min(counts[j], counts[j - squares[i]] + 1);
            }
        }
        return counts[n];
    }
};
