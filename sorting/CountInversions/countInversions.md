```cpp
#include <iostream>
#include <vector>

using namespace std;

pair<long long, vector<int>> CountSplitInversion(vector<int>& X, vector<int>& Y) {
    long long ctr = 0;
    vector<int> merged;
    int i = 0, j = 0;
    while (i < X.size() && j < Y.size()) {
        if (X[i] <= Y[j]) {
            merged.push_back(X[i]);
            i++;
        } else {
            merged.push_back(Y[j]);
            ctr += X.size() - i;
            j++;
        }
    }

    while (i < X.size()) {
        merged.push_back(X[i]);
        i++;
    }

    while (j < Y.size()) {
        merged.push_back(Y[j]);
        j++;
    }

    return {ctr, merged};
}

pair<long long, vector<int>> CountInversion(vector<int>& A) {
    int n = A.size();
    if (n == 1) {
        return {0, A};
    }
    int mid = n / 2;
    vector<int> Aleft(A.begin(), A.begin() + mid);
    vector<int> Aright(A.begin() + mid, A.end());
    auto [bleft, AleftSorted] = CountInversion(Aleft);
    auto [bright, ArightSorted] = CountInversion(Aright);
    auto [bsplit, Amerged] = CountSplitInversion(AleftSorted, ArightSorted);
    return {bleft + bright + bsplit, Amerged};
}

int main() {
    vector<int> A = {3, 1, 2, 4, 6, 5}; 
    auto [inversionCount, sortedArray] = CountInversion(A); 
    cout << "Number of inversions: " << inversionCount << endl;
    cout << "Sorted Array: ";
    for (int num : sortedArray) {
        cout << num << " ";
    }
    cout << endl; 
    return 0;
}

```
Count-Inversion(A)
    if |A| = 1 then
        Return (0, A);
    else
        Aleft = first ⌊|A|/2⌋ elements of A;
        Aright = the remaining ⌈|A|/2⌉ elements of A;
        
        (bleft, Aleft) = Count-Inversion(Aleft);
        (bright, Aright) = Count-Inversion(Aright);
        
        (bsplit, A) = Count-Split-Inversion(Aleft, Aright);
        
        Return (bleft + bright + bsplit, and the sorted array A);
    end
end

Count-Split-Inversion(X, Y)
    Initialize i = 1, j = 1, k = 1, ctr = 0;
    Initialize an output array A of size |X| + |Y|;
    
    while i ≤ |X| and j ≤ |Y| do
        if X[i] ≤ Y[j] then
            A[k] = X[i]; i = i + 1; k = k + 1;
        else
            A[k] = Y[j]; ctr = ctr + (|X| - i + 1); j = j + 1; k = k + 1;
        end
    end
    
    if i > |X| then
        Append the remaining elements of Y into A;
    else
        Append the remaining elements of X into A;
    
    return (ctr, A);
end
