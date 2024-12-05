bool isReachable(int a, int b, int c, int d) {
    // Base case: if (c, d) equals (a, b), return true
    if (c == a && d == b) {
        return true;
    }
    // If either c or d is less than a or b respectively, return false
    if (c < a || d < b) {
        return false;
    }
    // (a,b) -> (a+b,b) or (a,b+a) is equal to
    // (a,b) <- (a-b,b) or (a,b-a)
    return isReachable(a, b, c - d, d) || isReachable(a, b, c, d - c);
}

string isPossible(int a, int b, int c, int d) {
    return isReachable(a, b, c, d) ? "Yes" : "No";
}