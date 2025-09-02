# [Platinum IV] Snowball - 20985 

[문제 링크](https://www.acmicpc.net/problem/20985) 

### 성능 요약

메모리: 8664 KB, 시간: 84 ms

### 분류

이분 탐색, 누적 합

### 제출 일자

2025년 9월 2일 14:26:41

### 문제 설명

<p>The JOI plain is a wide plain spreading from west to east. We can consider the JOI plain as a number line. A spot on the JOI plain is denoted by a coordinate. The positive direction of the number line corresponds to the east direction. Now winter comes in the JOI plain. There are N snowballs on it, numbered from 1 to N from the west to the east. In the beginning, the coordinate of the snowball i (1 ≤ i ≤ N) is an integer X<sub>i</sub>.</p>

<p>Strong wind blows in the JOI plain in winter. You have observation data of wind for Q days. On the j-th day (1 ≤ j ≤ Q), the wind is described by an integer W<sub>j</sub>. If W<sub>j</sub> is negative, then the wind blows to the west direction. If W<sub>j</sub> is not negative, then the wind blows to the east direction. The strength of the wind is |W<sub>j</sub>|.</p>

<p>When wind blows, a snowball is moved to the same direction as the wind, and its length of move is equal to the strength of the wind. In other words, if there is a snowball in the coordinate x in the beginning of the j-th day (1 ≤ j ≤ Q), then the snowball is moved from the coordinate x to the coordinate x + W<sub>j</sub>. At the end of the j-th day, the coordinate of the snowball becomes x + W<sub>j</sub>. Note that, in each day, the snowballs are moved at the same time, and their speeds are the same.</p>

<p>Initially, the JOI plain is covered with snow. If a snowball is moved on an interval covered with snow, then the snowball accumulates the snow, the weight of the snowball is increased, and the snow on the interval disappears. In other words, for an integer a, assume that the interval from a to a + 1 is covered with snow. If a snowball is moved on this interval, then the weight of the snowball is increased by 1, and the snow on the interval from a to a + 1 disappears. However, if a snowball is moved on an interval without snow, the weight of the snowball remains the same.</p>

<p>Initially, the weight of every snowball is 0. It did not snow on the Q days of observation data.</p>

<p>You want to know the weight of each snowball at the end of the Q-th day.</p>

<p>Write a program which, given the initial position of each snowball and observation data of wind for Q days, calculates the weight of each snowball at the end of the Q-th day</p>

### 입력 

 <p>Read the following data from the standard input. Given values are all integers.</p>

<pre>N Q
X<sub>1</sub> · · · X<sub>N</sub>
W<sub>1</sub>
.
.
.
W<sub>Q</sub></pre>

### 출력 

 <p>Write N lines to the standard output. The i-th line (1 ≤ i ≤ N) should contain the weight of the snowball i at the end of the Q-th day.</p>

