#include <stdio.h>

#define MAXN 128

int main() {
	int n, p[MAXN], is_unknown[MAXN], previous = 100, sum = 0;

	scanf("%d", &n);
    // Set every -1 to as large as it can possibly be,
    // while ensuring the percentages are non-increasing.
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		if (p[i] == -1) {
			p[i] = previous;
			is_unknown[i] = 1;
		} else if (p[i] > previous) {
            // This percentage is more than that to its left.
            for (int i = 0; i < n; i++) printf("%d ", -1);
		    printf("\n");
            return 0;
        }
		previous = p[i];
		sum += p[i];
	}

    // Go from right to left, decreasing percentages where possible,
    // ensuring each percentage is no less than that to its right.
    // Only do this while sum > 100. 
	previous = 1;
	for (int i = n-1; i >= 0; i--) {
		while (is_unknown[i] && sum > 100 && p[i] > previous) {
			p[i]--;
			sum--;
		}
		previous = p[i];
	}

    // If sum is less than 100, we can't increase it any more.
    // If sum is more than 100, we can't decrease it any more.
	if (sum == 100) {
		for (int i = 0; i < n; i++) printf("%d ", p[i]);
		printf("\n");
	} else {
		for (int i = 0; i < n; i++) printf("%d ", -1);
		printf("\n");
	}
}