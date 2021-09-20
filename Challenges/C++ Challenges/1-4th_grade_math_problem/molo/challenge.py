import sys
import itertools

for p in itertools.permutations([1, 2, 3, 4, 5, 6, 7, 8, 9]):
    """
    In order to cut down on the numbers to check (almost a billion numbers),
    Only iterate through the permutations, where there are only 9!

    Then, as we loop through each number, check its divisibility.
    We iteratively make the number larger. For example, we first
    check divisibility of the first number, then the second number
    we can take the previous, multiply by ten and add the next.

    If we never break out of the for loop, we move to the else
    statement and announce that we found the answer.
    """

    check = 0
    for idx, val in enumerate(p):
        check = (check * 10) + val

        if check % (idx + 1) != 0:
            break
    else:
        print("Found! %d" % check)
        sys.exit()
