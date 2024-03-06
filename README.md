# A Collection of LeetCode Problems

Here is a list of LeetCode problems I would recommend practicing
if you haven't brushed up on algorithmic questions for long.

They can turbocharge your coding ability in a short period of time
before a tech interview.

Please also check out my past Medium stories on some of the interesting questions:
[Cracking LeetCode Problems](https://devinz1993.medium.com/list/cracking-leetcode-problems-9b8fe1f4ebfa).

---

* [400. Nth Digit](https://leetcode.com/problems/nth-digit) [(C++)](src/400.cc)
* [440. K-th Smallest in Lexicographical Order](https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/) [(C++)](src/440.cc)
* [60. Permutation Sequence](https://leetcode.com/problems/permutation-sequence/) [(C++)](src/60.cc)
* [31. Next Permutation](https://leetcode.com/problems/next-permutation/) [(C++)](src/31.cc)
* [54. Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) [(C++)](src/54.cc)
* [68. Text Justification](https://leetcode.com/problems/text-justification/) [(C++)](src/68.cc)
  - Corner case: the last line and lines that only accommodate one word.
* [166. Fraction to Recurring Decimal](https://leetcode.com/problems/fraction-to-recurring-decimal/) [(C++)](src/166.cc)
  - Detect a cycle.
* [466. Count the Repetitions](https://leetcode.com/problems/count-the-repetitions/) [(C++)](src/466.cc)
  - For each start position in s<sub>2</sub>, how many characters of s<sub>2</sub> (wrapping around) can we match by scanning s<sub>1</sub> from start to end.
* [2122. Recover the Original Array](https://leetcode.com/problems/recover-the-original-array/) [(C++)](src/2122.cc)
* [43. Multiply Strings](https://leetcode.com/problems/multiply-strings/) [(C++)](src/43.cc)
* [57. Insert Intervals](https://leetcode.com/problems/insert-interval/) [(C++)](src/57.cc)
* [158. Read N Characters Given read4 II — Call Multiple Times](https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/) [(C++)](src/158.cc)
  - Implement a buffered reader.
* [722. Remove Comments](https://leetcode.com/problems/remove-comments/) [(C++)](src/722.cc)
* [148. Sort List](https://leetcode.com/problems/sort-list/) [(C++)](src/148.cc)
  - Merge sort, using fast and slow pointers to locate the middle of the list. 
* [25. Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/) [(C++)](src/25.cc)
* [708. Insert into a Sorted Circular Linked List](https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/) [(C++)](src/708.cc)
  - Corner case: all values in the circular list are the same.
* [287. Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/) [(C++)](src/287.cc)
  - Detect the cycle in a linked list.
* [341. Flatten Nested List Iterator](https://leetcode.com/problems/flatten-nested-list-iterator/) [(C++)](src/341.cc)
  - Maintain a stack (of list iterators) for traversing the leaves of a tree.
* [654. Maximum Binary Tree](https://leetcode.com/problems/maximum-binary-tree/) [(C++)](src/654.cc)
* [117. Populating Next Right Pointers in Each Node II](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/) [(C++)](src/117.cc)
  - Level-order traversal of a binary tree.
* [863. All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/) [(C++)](src/863.cc)
  - First need to find the path from the root to a given node.
  - Then enumerate common ancestors.
* [1382. Balance a Binary Search Tree](https://leetcode.com/problems/balance-a-binary-search-tree/) [(C++)](src/1382.cc)
  - O(n) time to convert a BST to a linked list ([LC 426](https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/))
  - O(n) time to convert a linked list to a balanced BST ([LC 109](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/))
* [272. Closest Binary Search Tree Value II](https://leetcode.com/problems/closest-binary-search-tree-value-ii/) [(C++)](src/272.cc)
  - Next greater element in a binary search tree.
* [353. Design Snake Game](https://leetcode.com/problems/design-snake-game/) [(C++)](src/353.cc)
* [588. Design In-Memory File System](https://leetcode.com/problems/design-in-memory-file-system/) [(C++)](src/588.cc)
* [381. Insert Delete GetRandom O(1) — Duplicates allowed](https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/) [(C++)](src/381.cc)
  - Vector + hash index.
* [432. All O(1) Data Structure](https://leetcode.com/problems/all-oone-data-structure/) [(C++)](src/432.cc)
  - Linked list + hash index
* [460. LFU Cache](https://leetcode.com/problems/lfu-cache/) [(C++)](src/460.cc)
  - Linked list + hash index
* [895. Maximum Frequency Stack](https://leetcode.com/problems/maximum-frequency-stack/) [(C++)](src/895.cc)
  - Stack + hash-based counter.
* [394. Decode String](https://leetcode.com/problems/decode-string/) [(C++)](src/394.cc)
  - Do not use recursion; use a stack instead.
* [891. Sum of Subsequence Widths](https://leetcode.com/problems/sum-of-subsequence-widths/) [(C++)](src/891.cc)
  - The original order doesn’t matter.
* [902. Numbers At Most N Given Digit Set](https://leetcode.com/problems/numbers-at-most-n-given-digit-set/) [(C++)](src/902.cc)
  - Digit DP.
* [600. Non-negative Integers without Consecutive Ones](https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/) [(C++)](src/600.cc)
  - Digit DP.
* [2031. Count Subarrays With More Ones Than Zeros](https://leetcode.com/problems/count-subarrays-with-more-ones-than-zeros/) [(C++)](src/2031.cc)
  - Requirement: O(n) time.
* [47. Permutations II](https://leetcode.com/problems/permutations-ii/) [(C++)](src/47.cc)
  - Backtrack. Try not using recursion.
* [37. Sudoku Solver](https://leetcode.com/problems/sudoku-solver/) [(C++)](src/37.cc)
  - Backtrack. Try not using recursion.
* [140. Word Break II](https://leetcode.com/problems/word-break-ii/) [(C++)](src/140.cc)
  - Backtrack + trie.
* [425. Word Squares](https://leetcode.com/problems/word-squares/) [(C++)](src/425.cc)
  - Backtrack + trie.
* [282. Expression Add Operators](https://leetcode.com/problems/expression-add-operators/) [(C++)](src/282.cc)
  - Backtrack, maintaining the partial result of an infix expression as you go.
* [301. Remove Invalid Parentheses](https://leetcode.com/problems/remove-invalid-parentheses/) [(C++)](src/301.cc)
* [780. Reaching Points](https://leetcode.com/problems/reaching-points/) [(C++)](src/780.cc)
  - Search backwards from (tx, ty) to (sx, sy).
* [1553. Minimum Number of Days to Eat N Oranges](https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/) [(C++)](src/1553.cc)
  - Backward BFS.
* [403. Frog Jump](https://leetcode.com/problems/frog-jump/) [(C++)](src/403.cc)
* [329. Longest Increasing Path in a Matrix](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/) [(C++)](src/329.cc)
  - DFS + memoization.
* [212. Word Search II](https://leetcode.com/problems/word-search-ii/) [(C++)](src/212.cc)
  - DFS + trie.
* [980. Unique Paths III](https://leetcode.com/problems/unique-paths-iii/) [(C++)](src/980.cc)
  - DFS + bitmask.
* [489. Robot Room Cleaner](https://leetcode.com/problems/robot-room-cleaner/) [(C++)](src/489.cc)
* [126. Word Ladder II](https://leetcode.com/problems/word-ladder-ii/) [(C++)](src/126.cc)
* [499. The Maze III](https://leetcode.com/problems/the-maze-iii/) [(C++)](src/499.cc)
* [815. Bus Routes](https://leetcode.com/problems/bus-routes/) [(C++)](src/815.cc)
* [2092. Find All People With Secret](https://leetcode.com/problems/find-all-people-with-secret/)
* [691. Stickers to Spell Word](https://leetcode.com/problems/stickers-to-spell-word/) [(C++)](src/691.cc)
  - BFS, clamping the occurrence of each character.
* [854. K-Similar Strings](https://leetcode.com/problems/k-similar-strings/) [(C++)](src/854.cc)
  - Pruning idea: consider a permutation as independent cycles and for each cycle choose only one transposition to start from.
* [2612. Minimum Reverse Operations](https://leetcode.com/problems/minimum-reverse-operations/)
* [1136. Parallel Courses](https://leetcode.com/problems/parallel-courses/) [(C++)](src/1136.cc)
  - Topological sort + DP. Try not using recursion.
* [332. Reconstruct Itinerary](https://leetcode.com/problems/reconstruct-itinerary/) [(C++)](src/332.cc)
  - Eulerian path. Try not using recursion.
* [505. The Maze II](https://leetcode.com/problems/the-maze-ii/) [(C++)](src/505.cc)
  - Dijkstra’s algorithm
* [1197. Minimum Knight Moves](https://leetcode.com/problems/minimum-knight-moves/) [(C++)](src/1197.cc)
  - A* search.
* [1928. Minimum Cost to Reach Destination in Time](https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/) [(C++)](src/1928.cc)
  - No need to use Dijkstra. Use DP and exploit the sparsity of the graph.
* [310. Minimum Height Trees](https://leetcode.com/problems/minimum-height-trees) [(C++)](src/310.cc)
  - Find the centroid of a tree.
* [2440. Create Components With Same Value](https://leetcode.com/problems/create-components-with-same-value) [(C++)](src/2440.cc)
  - Split a tree into equal sums.
* [407. Trapping Rain Water II](https://leetcode.com/problems/trapping-rain-water-ii/) [(C++)](src/407.cc)
* [834. Sum of Distances in Tree](https://leetcode.com/problems/sum-of-distances-in-tree/) [(C++)](src/834.cc)
  - DP on a tree.
* [805. Split Array with Same Average](https://leetcode.com/problems/split-array-with-same-average/) [(C++)](src/805.cc)
  - Bitmask + cut in half.
* [548. Split Array with Equal Sum](https://leetcode.com/problems/split-array-with-equal-sum/) [(C++)](src/548.cc)
  - Cut in half.
* [1125. Smallest Sufficient Team](https://leetcode.com/problems/smallest-sufficient-team/) [(C++)](src/1125.cc)
  - Knapsack + bitmask.
* [698. Partition to K Equal Sum Subsets](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/) [(C++)](src/698.cc)
  - DP + bitmask.
* [943. Find the Shortest Superstring](https://leetcode.com/problems/find-the-shortest-superstring/) [(C++)](src/943.cc)
  - DP + bitmask
* [1723. Find Minimum Time to Finish All Jobs](https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/) [(C++)](src/1723.cc)
  - DP + subset enumeration.
* [1494. Parallel Courses II](https://leetcode.com/problems/parallel-courses-ii/) [(C++)](src/1494.cc)
  - DP+ subset enumeration.
* [2172. Maximum AND Sum of Array](https://leetcode.com/problems/maximum-and-sum-of-array/)
  - Memoization with state compression.
* [1659. Maximize Grid Happiness](https://leetcode.com/problems/maximize-grid-happiness/) [(C++)](src/1659.cc)
  - Memoization with state compression.
* [81. Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/) [(C++)](src/81.cc)
  - Binary search.
* [4. Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) [(C++)](src/4.cc)
  - Divide and conquer. Take heed of the base case.
* [410. Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/) [(C++)](src/410.cc)
  - Binary search.
* [644. Maximum Average Subarray II](https://leetcode.com/problems/maximum-average-subarray-ii/) [(C++)](src/644.cc)
  - Binary search, checking the running sum instead of the average.
* [878. Nth Magical Number](https://leetcode.com/problems/nth-magical-number/) [(C++)](src/878.cc)
  - Binary search.
* [483. Smallest Good Base](https://leetcode.com/problems/smallest-good-base/) [(C++)](src/483.cc)
  - Binary search.
* [1574. Shortest Subarray to be Removed to Make Array Sorted](https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/) [(C++)](src/1574.cc)
  - Two pointers.
* [581. Shortest Unsorted Continuous Subarray](https://leetcode.com/problems/shortest-unsorted-continuous-subarray/) [(C++)](src/581.cc)
  - O(n) time, O(1) space.
* [1793. Maximum Score of a Good Subarray](https://leetcode.com/problems/maximum-score-of-a-good-subarray/) [(C++)](src/1793.cc)
  - Two pointers.
* [1498. Number of Subsequences That Satisfy the Given Sum Condition](https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/) [(C++)](src/1498.cc)
  - Two pointers.
* [378. Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/) [(C++)](src/378.cc)
  - Binary search + two pointers.
* [786. K-th Smallest Prime Fraction](https://leetcode.com/problems/k-th-smallest-prime-fraction/) [(C++)](src/786.cc)
  - Binary search + two pointers.
* [2040. Kth Smallest Product of Two Sorted Arrays](https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/) [(C++)](src/2040.cc)
  - Binary search + two pointers.
* [719. Find K-th Smallest Pair Distance](https://leetcode.com/problems/find-k-th-smallest-pair-distance/) [(C++)](src/719.cc)
  - Binary search + sliding window.
* [30. Substring with Concatenation of All Words](https://leetcode.com/problems/substring-with-concatenation-of-all-words/) [(C++)](src/30.cc)
  - Sliding window.
* [992. Subarrays with K Different Integers](https://leetcode.com/problems/subarrays-with-k-different-integers/) [(C++)](src/992.cc)
  - Sliding window.
* [324. Wiggle Sort II](https://leetcode.com/problems/wiggle-sort-ii/) [(C++)](src/324.cc)
  - O(n) time, three-way partition (q-sort).
* [1471. The k Strongest Values in an Array](https://leetcode.com/problems/the-k-strongest-values-in-an-array/) [(C++)](src/1471.cc)
  - O(n) time, three-way partition.
* [164. Maximum Gap](https://leetcode.com/problems/maximum-gap/) [(C++)](src/164.cc)
  - Radix sort.
* [84. Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/) [(C++)](src/84.cc)
  - Monotonic stack.
* [1950. Maximum of Minimum Values in All Subarrays](https://leetcode.com/problems/maximum-of-minimum-values-in-all-subarrays/) [(C++)](src/1950.cc)
  - Monotonic stack.
* [1130. Minimum Cost Tree From Leaf Values](https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/) [(C++)](src/1130.cc)
  - Surprisingly, this can be done in O(n) time using the monotonic stack.
* [962. Maximum Width Ramp](https://leetcode.com/problems/maximum-width-ramp/) [(C++)](src/962.cc)
  - O(n) time, monotonic stack + two pointers.
* [456. 132 Pattern](https://leetcode.com/problems/132-pattern/) [(C++)](src/456.cc)
  - O(n) time, monotonic stack.
* [316. Remove Duplicate Letters](https://leetcode.com/problems/remove-duplicate-letters/) [(C++)](src/316.cc)
  - O(n) time, monotonic stack.
* [2030. Smallest K-Length Subsequence With Occurrences of a Letter](https://leetcode.com/problems/smallest-k-length-subsequence-with-occurrences-of-a-letter/) [(C++)](src/2030.cc)
  - O(n) time, monotonic stack.
* [2289. Steps to Make Array Non-decreasing](https://leetcode.com/problems/steps-to-make-array-non-decreasing/) [(C++)](src/2289.cc)
  - O(n) time, monotonic stack.
* [321. Create Maximum Number](https://leetcode.com/problems/create-maximum-number/) [(C++)](src/321.cc)
  - Monotonic stack.
* [239. Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/) [(C++)](src/239.cc)
  - O(n) time, monotonic queue.
* [862. Shortest Subarray with Sum at Least K](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/) [(C++)](src/862.cc)
  - O(n) time, monotonic queue.
* [1499. Max Value of Equation](https://leetcode.com/problems/max-value-of-equation/) [(C++)](src/1499.cc)
  - Sliding window + monotonic queue.
* [1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/) [(C++)](src/1438.cc)
  - Sliding window + monotonic queue.
* [1687. Delivering Boxes from Storage to Ports](https://leetcode.com/problems/delivering-boxes-from-storage-to-ports/) [(C++)](src/1687.cc)
  - DP + monotonic queue.
* [1834. Single-Threaded CPU](https://leetcode.com/problems/single-threaded-cpu/) [(C++)](src/1834.cc)
* [1353. Maximum Number of Events That Can Be Attended](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/) [(C++)](src/1353.cc)
* [1882. Process Tasks Using Servers](https://leetcode.com/problems/process-tasks-using-servers/) [(C++)](src/1882.cc)
* [358. Rearrange String k Distance Apart](https://leetcode.com/problems/rearrange-string-k-distance-apart/) [(C++)](src/358.cc)
* [659. Split Array into Consecutive Subsequences](https://leetcode.com/problems/split-array-into-consecutive-subsequences/) [(C++)](src/659.cc)
* [1717. Maximum Score From Removing Substrings](https://leetcode.com/problems/maximum-score-from-removing-substrings/) [(C++)](src/1717.cc)
* [502. IPO](https://leetcode.com/problems/ipo/) [(C++)](src/502.cc)
* [1665. Minimum Initial Energy to Finish Tasks](https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/) [(C++)](src/1665.cc)
* [1326. Minimum Number of Taps to Open to Water a Garden](https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/) [(C++)](src/1326.cc)
* [630. Course Schedule III](https://leetcode.com/problems/course-schedule-iii/) [(C++)](src/630.cc)
* [857. Minimum Cost to Hire K Workers](https://leetcode.com/problems/minimum-cost-to-hire-k-workers/) [(C++)](src/857.cc)
* [757. Set Intersection Size At Least Two](https://leetcode.com/problems/set-intersection-size-at-least-two/) [(C++)](src/757.cc)
* [1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree](https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/) [(C++)](src/1489.cc)
  - Kruskal’s algorithm.
* [313. Super Ugly Number](https://leetcode.com/problems/super-ugly-number/) [(C++)](src/313.cc)
  - Priority queue.
* [2386. Find the K-Sum of an Array](https://leetcode.com/problems/find-the-k-sum-of-an-array/) [(C++)](src/2386.cc)
  - Enumerate k smallest subset sums.
* [373. Find K Pairs with Smallest Sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/) [(C++)](src/373.cc)
  - K-way merge.
* [1508. Range Sum of Sorted Subarray Sums](https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/) [(C++)](src/1508.cc)
  - K-way merge.
* [1675. Minimize Deviation in Array](https://leetcode.com/problems/minimize-deviation-in-array/) [(C++)](src/1675.cc)
  - K-way merge.
* [768. Max Chunks To Make Sorted II](https://leetcode.com/problems/max-chunks-to-make-sorted-ii/) [(C++)](src/768.cc)
* [149. Max Points on a Line](https://leetcode.com/problems/max-points-on-a-line/) [(C++)](src/149.cc)
  - Normalize and hash a line.
* [711. Number of Distinct Islands II](https://leetcode.com/problems/number-of-distinct-islands-ii/) [(C++)](src/711.cc)
  - Normalize and hash an island.
* [1316. Distinct Echo Substrings](https://leetcode.com/problems/distinct-echo-substrings/) [(C++)](src/1316.cc)
  - Rolling hash.
* [715. Range Module](https://leetcode.com/problems/range-module/) [(C++)](src/715.cc)
  - Maintain a tree map for disjoint intervals.
* [699. Falling Squares](https://leetcode.com/problems/falling-squares/) [(C++)](src/699.cc)
  - Tree map.
* [391. Perfect Rectangle](https://leetcode.com/problems/perfect-rectangle/) [(C++)](src/391.cc)
  - Tree map.
* [363. Max Sum of Rectangle No Larger Than K](https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/) [(C++)](src/363.cc)
  - DP + tree map.
* [218. The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/) [(C++)](src/218.cc)
  - Line sweep.
* [480. Sliding Window Median](https://leetcode.com/problems/sliding-window-median/) [(C++)](src/480.cc)
  - Use two std::multisets.
* [1825. Finding MK Average](https://leetcode.com/problems/finding-mk-average/) [(C++)](src/1825.cc)
  - std::deque + std::multiset
* [1703. Minimum Adjacent Swaps for K Consecutive Ones](https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/) [(C++)](src/1703.cc)
  - Running sum of distances to the sliding window median.
* [2448. Minimum Cost to Make Array Equal](https://leetcode.com/problems/minimum-cost-to-make-array-equal/) [(C++)](src/2448.cc)
  - Weighted median.
* [1554. Strings Differ by One Character](https://leetcode.com/problems/strings-differ-by-one-character/) [(C++)](src/1554.cc)
  - Trie or rolling hash.
* [1803. Count Pairs With XOR in a Range](https://leetcode.com/problems/count-pairs-with-xor-in-a-range/) [(C++)](src/1803.cc)
  - Trie.
* [745. Prefix and Suffix Search](https://leetcode.com/problems/prefix-and-suffix-search/) [(C++)](src/745.cc)
  - Trie.
* [3045. Count Prefix and Suffix Pairs II](https://leetcode.com/problems/count-prefix-and-suffix-pairs-ii/) [(C++)](src/3045.cc)
  - Trie.
* [803. Bricks Falling When Hit](https://leetcode.com/problems/bricks-falling-when-hit/) [(C++)](src/803.cc)
  - Disjoint set.
* [947. Most Stones Removed with Same Row or Column](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/) [(C++)](src/947.cc)
  - Disjoint set.
* [1632. Rank Transform of a Matrix](https://leetcode.com/problems/rank-transform-of-a-matrix/) [(C++)](src/1632.cc)
  - Disjoint set + topological sort.
* [1998. GCD Sort of an Array](https://leetcode.com/problems/gcd-sort-of-an-array/) [(C++)](src/1998.cc)
  - Disjoint set + sieve of Eratosthenes.
* [308. Range Sum Query 2D — Mutable](https://leetcode.com/problems/range-sum-query-2d-mutable/) [(C++)](src/308.cc)
  - Use this to test your binary indexed tree.
* [327. Count of Range Sum](https://leetcode.com/problems/count-of-range-sum/) [(C++)](src/327.cc)
  - Binary indexed tree or merge sort.
* [2179. Count Good Triplets in an Array](https://leetcode.com/problems/count-good-triplets-in-an-array/) [(C++)](src/2179.cc)
  - Binary indexed tree.
* [1649. Create Sorted Array through Instructions](https://leetcode.com/problems/create-sorted-array-through-instructions/) [(C++)](src/1649.cc)
  - Binary indexed tree.
* [1505. Minimum Possible Integer After at Most K Adjacent Swaps On Digits](https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/) [(C++)](src/1505.cc)
  - Binary indexed tree.
* [2926. Maximum Balanced Subsequence Sum](https://leetcode.com/problems/maximum-balanced-subsequence-sum/) [(C++)](src/2926.cc)
  - DP + segment tree.
* [1674. Minimum Moves to Make Array Complementary](https://leetcode.com/problems/minimum-moves-to-make-array-complementary/) [(C++)](src/1674.cc)
  - Difference array.
* [798. Smallest Rotation with Highest Score](https://leetcode.com/problems/smallest-rotation-with-highest-score/) [(C++)](src/798.cc)
  - Difference array.
* [220. Contains Duplicate III](https://leetcode.com/problems/contains-duplicate-iii/) [(C++)](src/220.cc)
  - O(n) time, bucketing.
* [1714. Sum Of Special Evenly-Spaced Elements In Array](https://leetcode.com/problems/sum-of-special-evenly-spaced-elements-in-array/) [(C++)](src/1714.cc)
  - Sqrt decomposition.
* [214. Shortest Palindrome](https://leetcode.com/problems/shortest-palindrome/) [(C++)](src/214.cc)
  - Use this to test your KMP implementation.
* [3008. Find Beautiful Indices in the Given Array II](https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-ii/) [(C++)](src/3008.cc)
  - KMP algorithm.
* [735. Asteroid Collision](https://leetcode.com/problems/asteroid-collision/) [(C++)](src/735.cc)
  - Stack.
* [331. Verify Preorder Serialization of a Binary Tree](https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/) [(C++)](src/331.cc)
  - One pass using a stack.
* [255. Verify Preorder Sequence in Binary Search Tree](https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/) [(C++)](src/255.cc)
  - One pass using a stack.
* [889. Construct Binary Tree from Preorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/) [(C++)](src/889.cc)
  - One pass using a stack.
* [1008. Construct Binary Search Tree from Preorder Traversal](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/) [(C++)](src/1008.cc)
  - One pass using a stack.
* [772. Basic Calculator III](https://leetcode.com/problems/basic-calculator-iii/) [(C++)](src/772.cc)
  - Try not using recursion.
* [1096. Brace Expansion II](https://leetcode.com/problems/brace-expansion-ii/) [(C++)](src/1096.cc)
  - A variant of the calculator question.
* [1597. Build Binary Expression Tree From Infix Expression](https://leetcode.com/problems/build-binary-expression-tree-from-infix-expression/) [(C++)](src/1597.cc)
  - Try not using recursion.
* [1896. Minimum Cost to Change the Final Value of Expression](https://leetcode.com/problems/minimum-cost-to-change-the-final-value-of-expression/) [(C++)](src/1896.cc)
  - Try not using recursion.
* [956. Tallest Billboard](https://leetcode.com/problems/tallest-billboard/) [(C++)](src/956.cc)
  - Knapsack.
* [2143. Choose Numbers From Two Arrays in Range](https://leetcode.com/problems/choose-numbers-from-two-arrays-in-range/)
  - Knapsack.
* [1787. Make the XOR of All Segments Equal to Zero](https://leetcode.com/problems/make-the-xor-of-all-segments-equal-to-zero/) [(C++)](src/1787.cc)
  - Knapsack.
* [879. Profitable Schemes](https://leetcode.com/problems/profitable-schemes/) [(C++)](src/879.cc)
* [1883. Minimum Skips to Arrive at Meeting On Time](https://leetcode.com/problems/minimum-skips-to-arrive-at-meeting-on-time/) [(C++)](src/1883.cc)
* [1191. K-Concatenation Maximum Sum](https://leetcode.com/problems/k-concatenation-maximum-sum/) [(C++)](src/1191.cc)
* [188. Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/) [(C++)](src/188.cc)
* [727. Minimum Window Subsequence](https://leetcode.com/problems/minimum-window-subsequence/) [(C++)](src/727.cc)
* [265. Paint House II](https://leetcode.com/problems/paint-house-ii/) [(C++)](src/265.cc)
* [1937. Maximum Number of Points with Cost](https://leetcode.com/problems/maximum-number-of-points-with-cost/) [(C++)](src/1937.cc)
* [1388. Pizza With 3n Slices](https://leetcode.com/problems/pizza-with-3n-slices/) [(C++)](src/1388.cc)
  - This reduces to LC 213.
* [174. Dungeon Game](https://leetcode.com/problems/dungeon-game/) [(C++)](src/174.cc)
* [656. Coin Path](https://leetcode.com/problems/coin-path/) [(C++)](src/656.cc)
  - Lexicographically smallest path.
* [741. Cherry Pickup](https://leetcode.com/problems/cherry-pickup/) [(C++)](src/741.cc)
* [32. Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/) [(C++)](src/32.cc)
* [1997. First Day Where You Have Been in All the Rooms](https://leetcode.com/problems/first-day-where-you-have-been-in-all-the-rooms/) [(C++)](src/1997.cc)
* [964. Least Operators to Express Number](https://leetcode.com/problems/least-operators-to-express-number/) [(C++)](src/964.cc)
* [552. Student Attendance Record II](https://leetcode.com/problems/student-attendance-record-ii/) [(C++)](src/552.cc)
* [903. Valid Permutations for DI Sequence](https://leetcode.com/problems/valid-permutations-for-di-sequence/) [(C++)](src/903.cc)
* [629. K Inverse Pairs Array](https://leetcode.com/problems/k-inverse-pairs-array/) [(C++)](src/629.cc)
* [920. Number of Music Playlists](https://leetcode.com/problems/number-of-music-playlists/) [(C++)](src/920.cc)
* [940. Distinct Subsequences II](https://leetcode.com/problems/distinct-subsequences-ii/) [(C++)](src/940.cc)
* [730. Count Different Palindromic Subsequences](https://leetcode.com/problems/count-different-palindromic-subsequences/) [(C++)](src/730.cc)
* [639. Decode Ways II](https://leetcode.com/problems/decode-ways-ii/) [(C++)](src/639.cc)
* [3003. Maximize the Number of Partitions After Operations](https://leetcode.com/problems/maximize-the-number-of-partitions-after-operations/) [(C++)](src/3003.cc)
* [2478. Number of Beautiful Partitions](https://leetcode.com/problems/number-of-beautiful-partitions/) [(C++)](src/2478.cc)
  - DP + sliding window.
* [1478. Allocate Mailboxes](https://leetcode.com/problems/allocate-mailboxes/) [(C++)](src/1478.cc)
  - The “Word Break” pattern.
* [1147. Longest Chunked Palindrome Decomposition](https://leetcode.com/problems/longest-chunked-palindrome-decomposition/) [(C++)](src/1147.cc)
* [354. Russian Doll Envelopes](https://leetcode.com/problems/russian-doll-envelopes/) [(C++)](src/354.cc)
  - Longest increasing subsequence.
* [1713. Minimum Operations to Make a Subsequence](https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/) [(C++)](src/1713.cc)
  - Longest increasing subsequence.
* [2111. Minimum Operations to Make the Array K-Increasing](https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/)
  - Longest increasing subsequence.
* [10. Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/) [(C++)](src/10.cc)
  - Longest common subsequence.
* [2060. Check if an Original String Exists Given Two Encoded Strings](https://leetcode.com/problems/check-if-an-original-string-exists-given-two-encoded-strings/) [(C++)](src/2060.cc)
  - Memoization.
* [1092. Shortest Common Supersequence](https://leetcode.com/problems/shortest-common-supersequence/) [(C++)](src/1092.cc)
  - Longest common subsequence.
* [2430. Maximum Deletions on a String](https://leetcode.com/problems/maximum-deletions-on-a-string/) [(C++)](src/2430.cc)
  - Longest common subsequence.
* [1216. Valid Palindrome III](https://leetcode.com/problems/valid-palindrome-iii/) [(C++)](src/1216.cc)
  - Longest common subsequence.
* [471. Encode String with Shortest Length](https://leetcode.com/problems/encode-string-with-shortest-length/) [(C++)](src/471.cc)
* [1000. Minimum Cost to Merge Stones](https://leetcode.com/problems/minimum-cost-to-merge-stones/) [(C++)](src/1000.cc)
* [312. Burst Balloons](https://leetcode.com/problems/burst-balloons/) [(C++)](src/312.cc)
* [546. Remove Boxes](https://leetcode.com/problems/remove-boxes/) [(C++)](src/546.cc)
* [664. Strange Printer](https://leetcode.com/problems/strange-printer/) [(C++)](src/664.cc)
* [1246. Palindrome Removal](https://leetcode.com/problems/palindrome-removal/) [(C++)](src/1246.cc)
* [2809. Minimum Time to Make Array Sum At Most x](https://leetcode.com/problems/minimum-time-to-make-array-sum-at-most-x/)
* [1531. String Compression II](https://leetcode.com/problems/string-compression-ii/) [(C++)](src/1531.cc)
* [887. Super Egg Drop](https://leetcode.com/problems/super-egg-drop/) [(C++)](src/887.cc)
  - This can be done in O(k * n) time.
* [1140. Stone Game](https://leetcode.com/problems/stone-game-ii/) [(C++)](src/1140.cc)
  - Minimax.
* [913. Cat and Mouse](https://leetcode.com/problems/cat-and-mouse/) [(C++)](src/913.cc)
  - Minimax, taking account of a draw.
* [843. Guess the Word](https://leetcode.com/problems/guess-the-word/) [(C++)](src/843.cc)
  - An interesting interactive problem.
* [1538. Guess the Majority in a Hidden Array](https://leetcode.com/problems/guess-the-majority-in-a-hidden-array/) [(C++)](src/1538.cc)
  - Logical reasoning.
* [3022. Minimize OR of Remaining Elements Using Operations](https://leetcode.com/problems/minimize-or-of-remaining-elements-using-operations/) [(C++)](src/3022.cc)
  - Bit manipulation.
* [921. Minimum Add to Make Parentheses Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/) [(C++)](src/921.cc)
* [2116. Check if a Parentheses String Can Be Valid](https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/)
* [1247. Minimum Swaps to Make Strings Equal](https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/) [(C++)](src/1247.cc)
* [777. Swap Adjacent in LR String](https://leetcode.com/problems/swap-adjacent-in-lr-string/) [(C++)](src/777.cc)
* [1702. Maximum Binary String After Change](https://leetcode.com/problems/maximum-binary-string-after-change/) [(C++)](src/1702.cc)
* [2561. Rearranging Fruits](https://leetcode.com/problems/rearranging-fruits/)
* [2571. Minimum Operations to Reduce an Integer to 0](https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/) [(C++)](src/2571.cc)
* [2790. Maximum Number of Groups With Increasing Length](https://leetcode.com/problems/maximum-number-of-groups-with-increasing-length/)
  - Greedy
* [2333. Minimum Sum of Squared Difference](https://leetcode.com/problems/minimum-sum-of-squared-difference/) [(C++)](src/2333.cc)
  - Greedy.
* [1820. Maximum Number of Accepted Invitations](https://leetcode.com/problems/maximum-number-of-accepted-invitations/) [(C++)](src/1820.cc)
  - Maximum flow.
* [2836. Maximize Value of Function in a Ball Passing Game](https://leetcode.com/problems/maximize-value-of-function-in-a-ball-passing-game/)
* [1782. Count Pairs Of Nodes](https://leetcode.com/problems/count-pairs-of-nodes/) [(C++)](src/1782.cc)
  - Take advantage of the sparsity of the graph.
* [229. Majority Element II](https://leetcode.com/problems/majority-element-ii/) [(C++)](src/229.cc)
  - Boyer-Moore majority vote algorithm.
* [1131. Maximum of Absolute Value Expression](https://leetcode.com/problems/maximum-of-absolute-value-expression/) [(C++)](src/1131.cc)
* [1735. Count Ways to Make Array With Product](https://leetcode.com/problems/count-ways-to-make-array-with-product/) [(C++)](src/1735.cc)
  - Sieve of Eratosthenes + combinations with repetitions.
* [2584. Split the Array to Make Coprime Products](https://leetcode.com/problems/split-the-array-to-make-coprime-products/)
* [2183. Count Array Pairs Divisible by K](https://leetcode.com/problems/count-array-pairs-divisible-by-k/) [(C++)](src/2183.cc)
* [1819. Number of Different Subsequences GCDs](https://leetcode.com/problems/number-of-different-subsequences-gcds/) [(C++)](src/1819.cc)
* [1622. Fancy Sequence](https://leetcode.com/problems/fancy-sequence/) [(C++)](src/1622.cc)
  - Modular multiplicative inverse.
* [2835. Minimum Operations to Form Subsequence With Target Sum](https://leetcode.com/problems/minimum-operations-to-form-subsequence-with-target-sum/)
* [1401. Circle and Rectangle Overlapping](https://leetcode.com/problems/circle-and-rectangle-overlapping/) [(C++)](src/1401.cc)
  - Geometry
* [587. Erect the Fence](https://leetcode.com/problems/erect-the-fence/) [(C++)](src/587.cc)
  - Graham scan for constructing convex hulls.
* [1117. Building H2O](https://leetcode.com/problems/building-h2o/) [(C++)](src/1117.cc)
  - Concurrency
  
## License

    Copyright 2022-2023 Devin Zuo

    Creative Commons Zero v1.0 Universal

    https://creativecommons.org/publicdomain/zero/1.0/
