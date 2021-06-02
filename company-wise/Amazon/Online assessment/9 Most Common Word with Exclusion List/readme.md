Ref
https://algo.monster/problems/most_common_word
https://leetcode.com/problems/most-common-word/discuss/1239563/C%2B%2B-Simple-Solution
https://leetcode.com/problems/most-common-word

----------------------------------------------------------------------------------------------------------------------------------

Find the most frequently used word, which is not listed in ignored_keywords, within a paragraph. A paragraph is a single line of words that may contain punctuation marks, mixed with uppercase and lowercase letters. The word comparison should not be case sensitive, and the output word is expected to be in lowercase.

Examples
Example 1:
Input:
paragraph = "If this book was written today in the midst of the slew of dystopian novels that come out, it may not have stood out. But, this book was way ahead of its time." ignored_keywords = ["of", "was", "the"]

Output: "book"
Explanation:
"of" appears three times and "was", "the" appear twice, but they are in the ignored_keywords list. The next most common word is "book", which appears twice.

Constraints
There is always at least one word in the paragraph and at least one word in the list of excluded keywords. The most common keyword frequency count that is not in ignored_keywords will always be unique. Keywords in the exclusion list only consist of lowercase alphabetical characters.