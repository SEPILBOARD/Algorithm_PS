# [Gold III] Heracles and the Stables of Augeas - 10207 

[문제 링크](https://www.acmicpc.net/problem/10207) 

### 성능 요약

메모리: 2220 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍, 기하학

### 제출 일자

2026년 3월 4일 14:44:21

### 문제 설명

<p>Let’s return to Heracles and his twelve labors. The fifth of the labors was a lot less glamorous than killing a giant supervenomous serpent. Instead, it involved cleaning, within a single day, the stables of Augeas, which contained over 1000 pieces of cattle and hadn’t been cleaned in 30 years. The task was intended to be both impossible and humiliating.</p>

<p>Rather than cleaning the stables by hand, Heracles decided to divert two nearby rivers through the stables to do the cleaning for him. Did he do so optimally? You surely would have, since you could have solved the optimization problem. In this problem, you will be given the description of several rivers, each as a sequence of points. For each river, you will be given the amount of water it provides. Your goal is to select which rivers to divert to get enough water to the stables, while minimizing the total amount of digging Heracles needs to do.</p>

<p>More specifically, for each river, in principle, Heracles could divert it from its closest point, but it may take multiple rivers to provide all the water that is needed. We will pretend that Heracles can dig a canal from each closest point to the stable separately, and we will ignore that a canal may in the process intersect another river or canal. We will also not let Heracles save work by combining multiple canals into one — instead, he must separately build one canal straight to the stable for each river he intends to use.</p>

### 입력 

 <p>The first line is the number K of input data sets, followed by the K data sets, each of the following form:</p>

<p>The first line contains two integers n, W and two floating point numbers x, y, separated by a space each. 1 ≤ n ≤ 100 is the number of rivers, and 0 ≤ W ≤ 100 is the amount of water Heracles requires. (x, y) is the coordinate where the stables are located.</p>

<p>This is followed by n lines, each describing a river. The first number of line i is an integer 2 ≤ ki ≤ 20, the number of points describing the river. The second number is an integer 1 ≤ wi ≤ 100, the amount of water this river provides. This is followed by 2ki floating point numbers, each giving the coordinates of one point (xj , yj ) of the i-th river, in order. That is, the river flows from (x1, y1) in a straight line to (x2, y2), then from there in a straight line to (x3, y3), and so on.</p>

### 출력 

 <p>For each data set, output “Data Set x:” on a line by itself, where x is its number.</p>

<p>Then, output on a line by itself, the minimum total amount of digging that Heracles has to do to get his W units of water. If even all rivers together don’t provide enough water, output “Impossible” instead. All floating point numbers should be rounded to two decimals.</p>

<p>Each data set should be followed by a blank line.</p>

