##解题思路

题目要求求出和目标最近的三数的和，和threesum问题一样，只是比threesum更简单，不用列举所有可能，不用去重。

所以这里思路很简单，给出三个指针，遍历排序数组，求出所有可能情况。求和目标最近的和即三数和与目标数的差的绝对值最小，当差的绝对值为0时，直接返回。

至于遍历的技巧和twosum两头往中间走的思路是一致的，只是多了一个指针从左往右扫。
