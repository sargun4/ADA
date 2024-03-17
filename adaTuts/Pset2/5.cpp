// 5. After graduating from Sham-Poobanana University, you decide to interview for a position
// at the Wall Street bank Long Live Boole. The managing director of the bank, Eloob Egroeg,
// poses a ’solve-or-die’ problems to each new employee, which they must solve within hours.
// Those who fail to solve the problem are fired immediately! Entering the bank for the first
// time, you notice that the employee offices are organized in a straight row, with a large T or F
// (i.e. T or F in the upper case) printed on the door of each office. Furthermore, between each
// adjacent pair of offices, there is a board marked by one of the symbols ∧, ∨, ⊕ . When you ask
// about these arcane symbols, Eloob confirms that T and F represent the boolean values TRUE
// and FALSE respectively. And the symbols on the boards represent the standard boolean
// operators AND, OR, XOR. He also explains that these letters and symbols describe whether
// certain combinations of employees can work together successfully. At the start of any new
// project, Eloob hierarchically clusters his employees by adding parentheses to the sequence
// of symbols, to obtain an unambiguous boolean expression. The project is successful if this
// parenthesized boolean expression evaluates to T.
// For example, if the bank has three employees, and the sequence of symbols on and between
// their doors is T ∧ F ⊕ T, there is exactly one successful parenthesization scheme: (T ∧ (F ⊕
// T)). However, if the list of door symbols is F ∧ T ⊕ F, there is no way to add parentheses to
// make the project successful.
// Eloob finally poses your solve-or-die interview question: Describe an algorithm to decide
// whether a given sequence of symbols can be parenthesized so that the resulting boolean
// expression evaluates to T . Your input is an array S[0, 1, . . . , 2n], where S[k] ∈ {T, F} when k
// is even, and S[k] ∈ {∨, ∧, ⊕} when k is odd.
#include <iostream>
#include <vector>

using namespace std;

bool isValidParenthesization(const vector<char>& symbols) {
    int n = symbols.size() / 2;  // Number of employees

    // Create a 2D table to store subproblem results
    vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(2, false)));

    // Initialize base cases
    for (int i = 0; i < n; i++) {
        if (symbols[2 * i] == 'T') {
            dp[i][i][true] = true;
        } else if (symbols[2 * i] == 'F') {
            dp[i][i][false] = true;
        }
    }

    // Perform dynamic programming to fill the table
    for (int len = 1; len < n; len++) {
        for (int i = 0; i < n - len; i++) {
            int j = i + len;

            for (int k = i; k < j; k++) {
                char op = symbols[2 * k + 1];

                if (op == '&') {
                    dp[i][j][true] = dp[i][j][true] || (dp[i][k][true] && dp[k + 1][j][true]);
                    dp[i][j][false] = dp[i][j][false] || (dp[i][k][false] || dp[k + 1][j][false]);
                } else if (op == '|') {
                    dp[i][j][true] = dp[i][j][true] || (dp[i][k][true] || dp[k + 1][j][true]);
                    dp[i][j][false] = dp[i][j][false] || (dp[i][k][false] && dp[k + 1][j][false]);
                } else if (op == '^') {
                    dp[i][j][true] = dp[i][j][true] || (dp[i][k][true] && dp[k + 1][j][false])
                        || (dp[i][k][false] && dp[k + 1][j][true]);
                    dp[i][j][false] = dp[i][j][false] || (dp[i][k][true] && dp[k + 1][j][true])
                        || (dp[i][k][false] && dp[k + 1][j][false]);
                }
            }
        }
    }

    // The whole expression evaluates to TRUE if there exists a valid parenthesization
    return dp[0][n - 1][true];
}

int main() {
    // Example usage
    vector<char> symbols = {'T', '&', 'F', '^', 'T'};
    if (isValidParenthesization(symbols)) {
        cout << "There exists a valid parenthesization.\n";
    } else {
        cout << "No valid parenthesization exists.\n";
    }

    return 0;
}
