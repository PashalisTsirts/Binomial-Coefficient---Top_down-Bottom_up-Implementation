 The value of C(n, k) can be recursively calculated using the formula for Binomial Coefficients.  
 
 C(n, k) = C(n-1, k-1) + C(n-1, k)
 C(n, 0) = C(n, n) = 1
 
 The simple recursive implementation recalculates the same subproblems.
 This can be avoided by using dynamic programming: Top_down & Bottom_up  Implementation
