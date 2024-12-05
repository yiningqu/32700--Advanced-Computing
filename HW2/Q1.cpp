//
//int countPalindromes(string s) {
//    int n = s.size();
//    // A 2D vector to store results of subproblems: dp[i][j] will be 'true' if the string from index i to j is a palindrome.
//    vector<vector<bool>> dp(n, vector<bool>(n, false));
//
//    int count = 0;
//
//    // Every single character is a palindrome
//    for (int i = 0; i < n; ++i) {
//        dp[i][i] = true;
//        count++;
//    }
//
//    // Check for a palindrome of length 2
//    for (int i = 0; i < n - 1; ++i) {
//        if (s[i] == s[i + 1]) {
//            dp[i][i + 1] = true;
//            count++;
//        }
//    }
//
//    // Check for palindromes of length greater than 2
//    for (int len = 3; len <= n; ++len) {
//        for (int i = 0; i < n - len + 1; ++i) { // i is the starting index
//            int j = i + len - 1; // j is the ending index
//            // If the substring from i to j is a palindrome
//            if (s[i] == s[j] && dp[i + 1][j - 1]) {
//                dp[i][j] = true;
//                count++;
//            }
//        }
//    }
//
//    return count;
//}
//
