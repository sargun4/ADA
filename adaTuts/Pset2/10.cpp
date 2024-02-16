// You and your eight-year-old nephew Elmo decide to play a simple card game. At the be-
// ginning of the game, the cards are dealt face up in a long row. Each card is worth a dierent

// number of points. After all the cards are dealt, you and Elmo take turns removing either the
// leftmost or rightmost card from the row, until all the cards are gone. At each turn, you can
// decide which of the two cards to take. The winner of the game is the player that has collected
// the most points when the game ends. Having never taken an algorithms class, Elmo follows
// the obvious greedy strategy—when it’s his turn, Elmo always takes the card with the higher
// point value. Your task is to find a strategy that will beat Elmo whenever possible. (It might
// seem mean to beat up on a little kid like this, but Elmo absolutely hates it when grown-ups
// let him win.)

#include <iostream>
#include <vector>

using namespace std;

// Function to compute the optimal strategy for the card game
int optimalStrategy(const vector<int>& cards) {
    int n = cards.size();
    
    // Create a 2D vector to store the optimal scores for subgames
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Fill the dp table using the recurrence relation
    for (int gap = 0; gap < n; ++gap) {
        for (int i = 0, j = gap; j < n; ++i, ++j) {
            // The player has two choices: either choose the left card or the right card
            int chooseLeft = (i + 2 <= j) ? dp[i + 2][j] : 0;
            int chooseRight = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;

            dp[i][j] = max(cards[i] + min(chooseLeft, dp[i + 1][j]),
                           cards[j] + min(chooseRight, dp[i][j - 1]));
        }
    }

    // The final result is stored in dp[0][n-1]
    return dp[0][n - 1];
}

int main() {
    // Example usage
    vector<int> cards = {4, 5, 8, 2};

    // Call the function to compute the optimal strategy
    int result = optimalStrategy(cards);

    // Output the result
    cout << "Maximum points you can collect to beat Elmo: " << result << endl;

    return 0;
}
