# A Collection of LeetCode Problems

Here is a list of LeetCode problems I would recommend practicing
if you haven't brushed up on algorithmic questions for long.

They can turbocharge your coding ability in a short period of time
before a tech interview.

Please also check out my past Medium stories on some of the interesting questions:
[Cracking LeetCode Problems](https://devinz1993.medium.com/list/cracking-leetcode-problems-9b8fe1f4ebfa).

---

* [400. Nth Digit](https://leetcode.com/problems/nth-digit)
* [440. K-th Smallest in Lexicographical Order](https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/)
* [60. Permutation Sequence](https://leetcode.com/problems/permutation-sequence/)
* [31. Next Permutation](https://leetcode.com/problems/next-permutation/)
* [54. Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)
* [68. Text Justification](https://leetcode.com/problems/text-justification/)
  - Corner case: the last line and lines that only accommodate one word.
* [166. Fraction to Recurring Decimal \
](https://leetcode.com/problems/fraction-to-recurring-decimal/)
  - Detect a cycle.
* [466. Count the Repetitions \
](https://leetcode.com/problems/count-the-repetitions/)
  - For each start position in s<sub>2</sub>, how many characters of s<sub>2</sub> (wrapping around) can we match by scanning s<sub>1</sub> from start to end.
* [2122. Recover the Original Array](https://leetcode.com/problems/recover-the-original-array/)
* [43. Multiply Strings](https://leetcode.com/problems/multiply-strings/)
* [57. Insert Intervals](https://leetcode.com/problems/insert-interval/)
* [158. Read N Characters Given read4 II — Call Multiple Times \
](https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/)
  - Implement a buffered reader.
* [722. Remove Comments](https://leetcode.com/problems/remove-comments/)
* [148. Sort List \
](https://leetcode.com/problems/sort-list/)
  - Merge sort, using fast and slow pointers to locate the middle of the list. 
* [25. Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)
* [708. Insert into a Sorted Circular Linked List \
](https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/)
  - Corner case: all values in the circular list are the same.
* [287. Find the Duplicate Number \
](https://leetcode.com/problems/find-the-duplicate-number/)
  - Detect the cycle in a linked list.
* [341. Flatten Nested List Iterator \
](https://leetcode.com/problems/flatten-nested-list-iterator/)
  - Maintain a stack (of list iterators) for traversing the leaves of a tree.
* [654. Maximum Binary Tree](https://leetcode.com/problems/maximum-binary-tree/)
* [117. Populating Next Right Pointers in Each Node II \
](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/)
  - Level-order traversal of a binary tree.
* [863. All Nodes Distance K in Binary Tree \
](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)
  - First need to find the path from the root to a given node.
  - Then enumerate common ancestors.
* [1382. Balance a Binary Search Tree \
](https://leetcode.com/problems/balance-a-binary-search-tree/)
  - O(n) time to convert a BST to a linked list (LC 426)
  - O(n) time to convert a linked list to a balanced BST (LC 109)
* [272. Closest Binary Search Tree Value II \
](https://leetcode.com/problems/closest-binary-search-tree-value-ii/)
  - Next greater element in a binary search tree.
* [353. Design Snake Game](https://leetcode.com/problems/design-snake-game/)
* [588. Design In-Memory File System](https://leetcode.com/problems/design-in-memory-file-system/)
* [381. Insert Delete GetRandom O(1) — Duplicates allowed \
](https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/)
  - Vector + hash index.
* [432. All O(1) Data Structure \
](https://leetcode.com/problems/all-oone-data-structure/)
  - Linked list + hash index
* [460. LFU Cache \
](https://leetcode.com/problems/lfu-cache/)
  - Linked list + hash index
* [895. Maximum Frequency Stack \
](https://leetcode.com/problems/maximum-frequency-stack/)
  - Stack + hash-based counter.
* [394. Decode String \
](https://leetcode.com/problems/decode-string/)
  - Do not use recursion; use a stack instead.
* [891. Sum of Subsequence Widths \
](https://leetcode.com/problems/sum-of-subsequence-widths/)
  - The original order doesn’t matter.
* [902. Numbers At Most N Given Digit Set \
](https://leetcode.com/problems/numbers-at-most-n-given-digit-set/)
  - Digit DP.
* [600. Non-negative Integers without Consecutive Ones \
](https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/)
  - Digit DP.
* [2031. Count Subarrays With More Ones Than Zeros \
](https://leetcode.com/problems/count-subarrays-with-more-ones-than-zeros/)
  - Requirement: O(n) time.
* [47. Permutations II \
](https://leetcode.com/problems/permutations-ii/)
  - Backtrack. Try not using recursion.
* [37. Sudoku Solver \
](https://leetcode.com/problems/sudoku-solver/)
  - Backtrack. Try not using recursion.
* [140. Word Break II \
](https://leetcode.com/problems/word-break-ii/)
  - Backtrack + trie.
* [425. Word Squares \
](https://leetcode.com/problems/word-squares/)
  - Backtrack + trie.
* [282. Expression Add Operators \
](https://leetcode.com/problems/expression-add-operators/)
  - Backtrack, maintaining the partial result of an infix expression as you go.
* [301. Remove Invalid Parentheses](https://leetcode.com/problems/remove-invalid-parentheses/)
* [780. Reaching Points \
](https://leetcode.com/problems/reaching-points/)
  - Search backwards from (tx, ty) to (sx, sy).
* [1553. Minimum Number of Days to Eat N Oranges \
](https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/)
  - Backward BFS.
* [403. Frog Jump](https://leetcode.com/problems/frog-jump/)
* [329. Longest Increasing Path in a Matrix \
](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/)
  - DFS + memoization.
* [212. Word Search II \
](https://leetcode.com/problems/word-search-ii/)
  - DFS + trie.
* [980. Unique Paths III \
](https://leetcode.com/problems/unique-paths-iii/)
  - DFS + bitmask.
* [489. Robot Room Cleaner](https://leetcode.com/problems/robot-room-cleaner/)
* [126. Word Ladder II](https://leetcode.com/problems/word-ladder-ii/)
* [499. The Maze III](https://leetcode.com/problems/the-maze-iii/)
* [815. Bus Routes](https://leetcode.com/problems/bus-routes/)
* [2092. Find All People With Secret](https://leetcode.com/problems/find-all-people-with-secret/)
* [691. Stickers to Spell Word \
](https://leetcode.com/problems/stickers-to-spell-word/)
  - BFS, clamping the occurrence of each character.
* [854. K-Similar Strings \
](https://leetcode.com/problems/k-similar-strings/)
  - Pruning idea: consider a permutation as independent cycles and for each cycle choose only one transposition to start from.
* [1136. Parallel Courses \
](https://leetcode.com/problems/parallel-courses/)
  - Topological sort + DP. Try not using recursion.
* [332. Reconstruct Itinerary \
](https://leetcode.com/problems/reconstruct-itinerary/)
  - Eulerian path. Try not using recursion.
* [505. The Maze II \
](https://leetcode.com/problems/the-maze-ii/)
  - Dijkstra’s algorithm
* [1928. Minimum Cost to Reach Destination in Time \
](https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/)
  - No need to use Dijkstra. Use DP and exploit the sparsity of the graph.
* [310. Minimum Height Trees \
](https://leetcode.com/problems/minimum-height-trees)
  - Find the centroid of a tree.
* [2440. Create Components With Same Value](https://leetcode.com/problems/create-components-with-same-value)
  - Split a tree into equal sums.
* [407. Trapping Rain Water II](https://leetcode.com/problems/trapping-rain-water-ii/)
* [834. Sum of Distances in Tree \
](https://leetcode.com/problems/sum-of-distances-in-tree/)
  - DP on a tree.
* [805. Split Array with Same Average \
](https://leetcode.com/problems/split-array-with-same-average/)
  - Bitmask + cut in half.
* [548. Split Array with Equal Sum \
](https://leetcode.com/problems/split-array-with-equal-sum/)
  - Cut in half.
* [1125. Smallest Sufficient Team \
](https://leetcode.com/problems/smallest-sufficient-team/)
  - Knapsack + bitmask.
* [698. Partition to K Equal Sum Subsets \
](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/)
  - DP + bitmask.
* [943. Find the Shortest Superstring \
](https://leetcode.com/problems/find-the-shortest-superstring/)
  - DP + bitmask
* [1723. Find Minimum Time to Finish All Jobs \
](https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/)
  - DP + subset enumeration.
* [1494. Parallel Courses II \
](https://leetcode.com/problems/parallel-courses-ii/)
  - DP+ subset enumeration.
* [2172. Maximum AND Sum of Array \
](https://leetcode.com/problems/maximum-and-sum-of-array/)
  - Memoization with state compression.
* [1659. Maximize Grid Happiness \
](https://leetcode.com/problems/maximize-grid-happiness/)
  - Memoization with state compression.
* [81. Search in Rotated Sorted Array II \
](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)
  - Binary search.
* [4. Median of Two Sorted Arrays \
](https://leetcode.com/problems/median-of-two-sorted-arrays/)
  - Divide and conquer. Take heed of the base case.
* [410. Split Array Largest Sum \
](https://leetcode.com/problems/split-array-largest-sum/)
  - Binary search.
* [644. Maximum Average Subarray II \
](https://leetcode.com/problems/maximum-average-subarray-ii/)
  - Binary search, checking the running sum instead of the average.
* [878. Nth Magical Number \
](https://leetcode.com/problems/nth-magical-number/)
  - Binary search.
* [483. Smallest Good Base \
](https://leetcode.com/problems/smallest-good-base/)
  - Binary search.
* [2333. Minimum Sum of Squared Difference \
](https://leetcode.com/problems/minimum-sum-of-squared-difference/)
  - Binary search.
* [1574. Shortest Subarray to be Removed to Make Array Sorted \
](https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/)
  - Two pointers.
* [581. Shortest Unsorted Continuous Subarray \
](https://leetcode.com/problems/shortest-unsorted-continuous-subarray/)
  - O(n) time, O(1) space.
* [1793. Maximum Score of a Good Subarray \
](https://leetcode.com/problems/maximum-score-of-a-good-subarray/)
  - Two pointers.
* [1498. Number of Subsequences That Satisfy the Given Sum Condition \
](https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/)
  - Two pointers.
* [378. Kth Smallest Element in a Sorted Matrix \
](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)
  - Binary search + two pointers.
* [786. K-th Smallest Prime Fraction \
](https://leetcode.com/problems/k-th-smallest-prime-fraction/)
  - Binary search + two pointers.
* [2040. Kth Smallest Product of Two Sorted Arrays \
](https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/)
  - Binary search + two pointers.
* [30. Substring with Concatenation of All Words \
](https://leetcode.com/problems/substring-with-concatenation-of-all-words/)
  - Sliding window.
* [992. Subarrays with K Different Integers \
](https://leetcode.com/problems/subarrays-with-k-different-integers/)
  - Sliding window.
* [324. Wiggle Sort II \
](https://leetcode.com/problems/wiggle-sort-ii/)
  - O(n) time, three-way partition (q-sort).
* [1471. The k Strongest Values in an Array \
](https://leetcode.com/problems/the-k-strongest-values-in-an-array/)
  - O(n) time, three-way partition.
* [164. Maximum Gap \
](https://leetcode.com/problems/maximum-gap/)
  - Radix sort.
* [84. Largest Rectangle in Histogram \
](https://leetcode.com/problems/largest-rectangle-in-histogram/)
  - Monotonic stack.
* [1950. Maximum of Minimum Values in All Subarrays \
](https://leetcode.com/problems/maximum-of-minimum-values-in-all-subarrays/)
  - Monotonic stack.
* [1130. Minimum Cost Tree From Leaf Values \
](https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/)
  - Surprisingly, this can be done in O(n) time using the monotonic stack.
* [962. Maximum Width Ramp \
](https://leetcode.com/problems/maximum-width-ramp/)
  - O(n) time, monotonic stack + two pointers.
* [456. 132 Pattern \
](https://leetcode.com/problems/132-pattern/)
  - O(n) time, monotonic stack.
* [316. Remove Duplicate Letters \
](https://leetcode.com/problems/remove-duplicate-letters/)
  - O(n) time, monotonic stack.
* [2030. Smallest K-Length Subsequence With Occurrences of a Letter \
](https://leetcode.com/problems/smallest-k-length-subsequence-with-occurrences-of-a-letter/)
  - O(n) time, monotonic stack.
* [2289. Steps to Make Array Non-decreasing \
](https://leetcode.com/problems/steps-to-make-array-non-decreasing/)
  - O(n) time, monotonic stack.
* [321. Create Maximum Number \
](https://leetcode.com/problems/create-maximum-number/)
  - Monotonic stack.
* [239. Sliding Window Maximum \
](https://leetcode.com/problems/sliding-window-maximum/)
  - O(n) time, monotonic queue.
* [862. Shortest Subarray with Sum at Least K \
](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/)
  - O(n) time, monotonic queue.
* [1499. Max Value of Equation \
](https://leetcode.com/problems/max-value-of-equation/)
  - Sliding window + monotonic queue.
* [1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit \
](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)
  - Sliding window + monotonic queue.
* [1687. Delivering Boxes from Storage to Ports \
](https://leetcode.com/problems/delivering-boxes-from-storage-to-ports/)
  - DP + monotonic queue.
* [1834. Single-Threaded CPU](https://leetcode.com/problems/single-threaded-cpu/)
* [1353. Maximum Number of Events That Can Be Attended](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/)
* [1882. Process Tasks Using Servers](https://leetcode.com/problems/process-tasks-using-servers/)
* [358. Rearrange String k Distance Apart](https://leetcode.com/problems/rearrange-string-k-distance-apart/)
* [659. Split Array into Consecutive Subsequences](https://leetcode.com/problems/split-array-into-consecutive-subsequences/)
* [1717. Maximum Score From Removing Substrings](https://leetcode.com/problems/maximum-score-from-removing-substrings/)
* [502. IPO](https://leetcode.com/problems/ipo/)
* [1665. Minimum Initial Energy to Finish Tasks](https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/)
* [1326. Minimum Number of Taps to Open to Water a Garden](https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/)
* [630. Course Schedule III](https://leetcode.com/problems/course-schedule-iii/)
* [857. Minimum Cost to Hire K Workers](https://leetcode.com/problems/minimum-cost-to-hire-k-workers/)
* [757. Set Intersection Size At Least Two](https://leetcode.com/problems/set-intersection-size-at-least-two/)
* [1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree \
](https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/)
  - Kruskal’s algorithm.
* [313. Super Ugly Number \
](https://leetcode.com/problems/super-ugly-number/)
  - Priority queue.
* [2386. Find the K-Sum of an Array](https://leetcode.com/problems/find-the-k-sum-of-an-array/)
  - Enumerate k smallest subset sums.
* [373. Find K Pairs with Smallest Sums \
](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/)
  - K-way merge.
* [1508. Range Sum of Sorted Subarray Sums \
](https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/)
  - K-way merge.
* [1675. Minimize Deviation in Array \
](https://leetcode.com/problems/minimize-deviation-in-array/)
  - K-way merge.
* [768. Max Chunks To Make Sorted II](https://leetcode.com/problems/max-chunks-to-make-sorted-ii/)
* [149. Max Points on a Line \
](https://leetcode.com/problems/max-points-on-a-line/)
  - Normalize and hash a line.
* [711. Number of Distinct Islands II \
](https://leetcode.com/problems/number-of-distinct-islands-ii/)
  - Normalize and hash an island.
* [1316. Distinct Echo Substrings \
](https://leetcode.com/problems/distinct-echo-substrings/)
  - Rolling hash.
* [715. Range Module \
](https://leetcode.com/problems/range-module/)
  - Maintain a tree map for disjoint intervals.
* [699. Falling Squares \
](https://leetcode.com/problems/falling-squares/)
  - Tree map.
* [391. Perfect Rectangle \
](https://leetcode.com/problems/perfect-rectangle/)
  - Tree map.
* [363. Max Sum of Rectangle No Larger Than K \
](https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/)
  - DP + tree map.
* [218. The Skyline Problem \
](https://leetcode.com/problems/the-skyline-problem/)
  - Line sweep.
* [480. Sliding Window Median \
](https://leetcode.com/problems/sliding-window-median/)
  - Use two std::multisets.
* [1825. Finding MK Average \
](https://leetcode.com/problems/finding-mk-average/)
  - std::deque + std::multiset
* [1703. Minimum Adjacent Swaps for K Consecutive Ones \
](https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/)
  - Running sum of distances to the sliding window median.
* [2448. Minimum Cost to Make Array Equal](https://leetcode.com/problems/minimum-cost-to-make-array-equal/)
  - Weighted median.
* [1554. Strings Differ by One Character \
](https://leetcode.com/problems/strings-differ-by-one-character/)
  - Trie or rolling hash.
* [1803. Count Pairs With XOR in a Range \
](https://leetcode.com/problems/count-pairs-with-xor-in-a-range/)
  - Trie.
* [745. Prefix and Suffix Search \
](https://leetcode.com/problems/prefix-and-suffix-search/)
  - Trie.
* [803. Bricks Falling When Hit \
](https://leetcode.com/problems/bricks-falling-when-hit/)
  - Disjoint set.
* [947. Most Stones Removed with Same Row or Column \
](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/)
  - Disjoint set.
* [1632. Rank Transform of a Matrix \
](https://leetcode.com/problems/rank-transform-of-a-matrix/)
  - Disjoint set + topological sort.
* [1998. GCD Sort of an Array \
](https://leetcode.com/problems/gcd-sort-of-an-array/)
  - Disjoint set + sieve of Eratosthenes.
* [308. Range Sum Query 2D — Mutable \
](https://leetcode.com/problems/range-sum-query-2d-mutable/)
  - Use this to test your binary indexed tree or segment tree.
* [327. Count of Range Sum \
](https://leetcode.com/problems/count-of-range-sum/)
  - Binary indexed tree or merge sort.
* [2179. Count Good Triplets in an Array \
](https://leetcode.com/problems/count-good-triplets-in-an-array/)
  - Binary indexed tree.
* [1649. Create Sorted Array through Instructions \
](https://leetcode.com/problems/create-sorted-array-through-instructions/)
  - Binary indexed tree.
* [1505. Minimum Possible Integer After at Most K Adjacent Swaps On Digits \
](https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/)
  - Binary indexed tree.
* [1674. Minimum Moves to Make Array Complementary \
](https://leetcode.com/problems/minimum-moves-to-make-array-complementary/)
  - Difference array.
* [798. Smallest Rotation with Highest Score \
](https://leetcode.com/problems/smallest-rotation-with-highest-score/)
  - Difference array.
* [220. Contains Duplicate III \
](https://leetcode.com/problems/contains-duplicate-iii/)
  - O(n) time, bucketing.
* [1714. Sum Of Special Evenly-Spaced Elements In Array \
](https://leetcode.com/problems/sum-of-special-evenly-spaced-elements-in-array/)
  - Sqrt decomposition.
* [214. Shortest Palindrome \
](https://leetcode.com/problems/shortest-palindrome/)
  - Use this to test your KMP implementation.
* [735. Asteroid Collision \
](https://leetcode.com/problems/asteroid-collision/)
  - Stack.
* [331. Verify Preorder Serialization of a Binary Tree \
](https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/)
  - One pass using a stack.
* [255. Verify Preorder Sequence in Binary Search Tree \
](https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/)
  - One pass using a stack.
* [889. Construct Binary Tree from Preorder and Postorder Traversal \
](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/)
  - One pass using a stack.
* [1008. Construct Binary Search Tree from Preorder Traversal \
](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/)
  - One pass using a stack.
* [772. Basic Calculator III \
](https://leetcode.com/problems/basic-calculator-iii/)
  - Try not using recursion.
* [1096. Brace Expansion II \
](https://leetcode.com/problems/brace-expansion-ii/)
  - A variant of the calculator question.
* [1597. Build Binary Expression Tree From Infix Expression \
](https://leetcode.com/problems/build-binary-expression-tree-from-infix-expression/)
  - Try not using recursion.
* [1896. Minimum Cost to Change the Final Value of Expression \
](https://leetcode.com/problems/minimum-cost-to-change-the-final-value-of-expression/)
  - Try not using recursion.
* [956. Tallest Billboard \
](https://leetcode.com/problems/tallest-billboard/)
  - Knapsack.
* [2143. Choose Numbers From Two Arrays in Range \
](https://leetcode.com/problems/choose-numbers-from-two-arrays-in-range/)
  - Knapsack.
* [1787. Make the XOR of All Segments Equal to Zero \
](https://leetcode.com/problems/make-the-xor-of-all-segments-equal-to-zero/)
  - Knapsack.
* [879. Profitable Schemes](https://leetcode.com/problems/profitable-schemes/)
* [1883. Minimum Skips to Arrive at Meeting On Time](https://leetcode.com/problems/minimum-skips-to-arrive-at-meeting-on-time/)
* [1191. K-Concatenation Maximum Sum](https://leetcode.com/problems/k-concatenation-maximum-sum/)
* [188. Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/)
* [727. Minimum Window Subsequence](https://leetcode.com/problems/minimum-window-subsequence/)
* [265. Paint House II](https://leetcode.com/problems/paint-house-ii/)
* [1937. Maximum Number of Points with Cost](https://leetcode.com/problems/maximum-number-of-points-with-cost/)
* [1388. Pizza With 3n Slices \
](https://leetcode.com/problems/pizza-with-3n-slices/)
  - This reduces to LC 213.
* [174. Dungeon Game](https://leetcode.com/problems/dungeon-game/)
* [656. Coin Path \
](https://leetcode.com/problems/coin-path/)
  - Lexicographically smallest path.
* [741. Cherry Pickup](https://leetcode.com/problems/cherry-pickup/)
* [32. Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/)
* [1997. First Day Where You Have Been in All the Rooms](https://leetcode.com/problems/first-day-where-you-have-been-in-all-the-rooms/)
* [964. Least Operators to Express Number](https://leetcode.com/problems/least-operators-to-express-number/)
* [552. Student Attendance Record II](https://leetcode.com/problems/student-attendance-record-ii/)
* [903. Valid Permutations for DI Sequence](https://leetcode.com/problems/valid-permutations-for-di-sequence/)
* [629. K Inverse Pairs Array](https://leetcode.com/problems/k-inverse-pairs-array/)
* [920. Number of Music Playlists](https://leetcode.com/problems/number-of-music-playlists/)
* [940. Distinct Subsequences II](https://leetcode.com/problems/distinct-subsequences-ii/)
* [730. Count Different Palindromic Subsequences](https://leetcode.com/problems/count-different-palindromic-subsequences/)
* [639. Decode Ways II](https://leetcode.com/problems/decode-ways-ii/)
* [2478. Number of Beautiful Partitions](https://leetcode.com/problems/number-of-beautiful-partitions/)
  - DP + sliding window.
* [1478. Allocate Mailboxes \
](https://leetcode.com/problems/allocate-mailboxes/)
  - The “Word Break” pattern.
* [1147. Longest Chunked Palindrome Decomposition](https://leetcode.com/problems/longest-chunked-palindrome-decomposition/)
* [354. Russian Doll Envelopes \
](https://leetcode.com/problems/russian-doll-envelopes/)
  - Longest increasing subsequence.
* [1713. Minimum Operations to Make a Subsequence \
](https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/)
  - Longest increasing subsequence.
* [2111. Minimum Operations to Make the Array K-Increasing \
](https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/)
  - Longest increasing subsequence.
* [10. Regular Expression Matching \
](https://leetcode.com/problems/regular-expression-matching/)
  - Longest common subsequence.
* [1092. Shortest Common Supersequence \
](https://leetcode.com/problems/shortest-common-supersequence/)
  - Longest common subsequence.
* [2430. Maximum Deletions on a String](https://leetcode.com/problems/maximum-deletions-on-a-string/)
  - Longest common subsequence.
* [471. Encode String with Shortest Length](https://leetcode.com/problems/encode-string-with-shortest-length/)
* [1216. Valid Palindrome III](https://leetcode.com/problems/valid-palindrome-iii/)
* [1246. Palindrome Removal](https://leetcode.com/problems/palindrome-removal/)
* [312. Burst Balloons](https://leetcode.com/problems/burst-balloons/)
* [664. Strange Printer](https://leetcode.com/problems/strange-printer/)
* [546. Remove Boxes](https://leetcode.com/problems/remove-boxes/)
* [1000. Minimum Cost to Merge Stones](https://leetcode.com/problems/minimum-cost-to-merge-stones/)
* [1531. String Compression II](https://leetcode.com/problems/string-compression-ii/)
* [887. Super Egg Drop \
](https://leetcode.com/problems/super-egg-drop/)
  - This can be done in O(k * n) time.
* [1140. Stone Game \
](https://leetcode.com/problems/stone-game-ii/)
  - Minimax.
* [913. Cat and Mouse \
](https://leetcode.com/problems/cat-and-mouse/)
  - Minimax, taking account of a draw.
* [843. Guess the Word \
](https://leetcode.com/problems/guess-the-word/)
  - An interesting interactive problem.
* [1538. Guess the Majority in a Hidden Array \
](https://leetcode.com/problems/guess-the-majority-in-a-hidden-array/)
  - Logical reasoning.
* [921. Minimum Add to Make Parentheses Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)
* [2116. Check if a Parentheses String Can Be Valid](https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/)
* [1247. Minimum Swaps to Make Strings Equal](https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/)
* [777. Swap Adjacent in LR String](https://leetcode.com/problems/swap-adjacent-in-lr-string/)
* [1702. Maximum Binary String After Change](https://leetcode.com/problems/maximum-binary-string-after-change/)
* [1820. Maximum Number of Accepted Invitations \
](https://leetcode.com/problems/maximum-number-of-accepted-invitations/)
  - Maximum flow.
* [1782. Count Pairs Of Nodes \
](https://leetcode.com/problems/count-pairs-of-nodes/)
  - Take advantage of the sparsity of the graph.
* [229. Majority Element II \
](https://leetcode.com/problems/majority-element-ii/)
  - Boyer-Moore majority vote algorithm.
* [1131. Maximum of Absolute Value Expression](https://leetcode.com/problems/maximum-of-absolute-value-expression/)
* [1401. Circle and Rectangle Overlapping](https://leetcode.com/problems/circle-and-rectangle-overlapping/)
* [1735. Count Ways to Make Array With Product \
](https://leetcode.com/problems/count-ways-to-make-array-with-product/)
  - Sieve of Eratosthenes + combinations with repetitions.
* [2183. Count Array Pairs Divisible by K](https://leetcode.com/problems/count-array-pairs-divisible-by-k/)
* [1819. Number of Different Subsequences GCDs](https://leetcode.com/problems/number-of-different-subsequences-gcds/)
* [1622. Fancy Sequence \
](https://leetcode.com/problems/fancy-sequence/)
  - Modular multiplicative inverse.
  
## License

    Copyright 2022 Devin Zuo

    Creative Commons Zero v1.0 Universal

    https://creativecommons.org/publicdomain/zero/1.0/
