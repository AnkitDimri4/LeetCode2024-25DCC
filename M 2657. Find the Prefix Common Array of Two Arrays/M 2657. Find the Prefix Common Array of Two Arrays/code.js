const findThePrefixCommonArray = function(A, B) {
    let n = A.length;
    let seen = new Set();
    let C = Array(n).fill(0);
    let commonCount = 0;
    for (let i = 0; i < n; i++) {
        if (seen.has(A[i])) commonCount++;
        else seen.add(A[i]);
        if (seen.has(B[i])) commonCount++;
        else seen.add(B[i]);
        C[i] = commonCount;
    }
    return C;
};

// Example input
const A = [1, 3, 2, 4];
const B = [3, 1, 2, 4];
const result = findThePrefixCommonArray(A, B);
console.log(result);