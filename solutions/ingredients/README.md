## Challenge Name

Ingredients Label

## Problem Statement

You are very health-conscious and so always read the labels on food which show the ingredients.
In particular, you care a lot about the percentage of each ingredient.
If a food product has $N$ ingredients with percentages $p[0]$, $p[1]$, ..., $p[N-1]$, then the percentages must be listed so that they follow the following restrictions:

- $p[0] + p[1] + ... + p[N-1] = 100$.
- all $p[i]$ are positive integers.
- $p[i] \geq p[i+1]$ for all $0 \leq i < N-1$. That is, the percentages are listed in non-increasing order.

For example, the following lists of percentages follow all the restrictions:

- 40 30 30
- 100
- 50 30 15 5

The following lists of percentages do not follow all the restrictions:

- 30 70 ($p[0] < p[1]$)
- 60 20 10 (the percentages do not add to 100)

You are looking at the percentages on the back of a packet of biscuits, but to your horror some of the percentages are missing! 
You have decided to come up with values for the missing percentages that follow all the restrictions.

## Input Format

The first line of input contains the integer $N$.

The second line contains $N$ integers: the values of $p[i]$. If $p[i] = -1$, this means that the real value of $p[i]$ is missing.  

## Constraints

For all test cases:

- $1 \le N \le 100$.
- $1 \leq p[i] \leq 100$ or $p[i] = -1$, for all $i$.

## Output Format

Output one line which contains $N$ integers: one way to assign percentages which follow all the rules.
If there are multiple possible answers, you can output any. 

If there is no way to assign percentages which follow all the rules, instead each of the $N$ integers you output should be `-1`.

## Sample Input

input00.txt

input01.txt

## Explanation 1

You can assign 20, 10 and 10 to the missing values to get `50 20 10 10 10` which follows all the restrictions.
There are other possible answers, including `50 20 19 10 1`.
Note that `60 10 10 10 10` would not be a valid answer, because you can not change the known percentages.

## Explanation 2

There is no way to assign values to the missing percentages so that all the rules are followed.