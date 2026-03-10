# [Gold IV] Savrsen - 12112 

[문제 링크](https://www.acmicpc.net/problem/12112) 

### 성능 요약

메모리: 80208 KB, 시간: 1208 ms

### 분류

수학, 정수론

### 제출 일자

2026년 3월 4일 17:50:14

### 문제 설명

<p>A number is perfect if it is equal to the sum of its divisors, the ones that are smaller than it. For example, number 28 is perfect because 28 = 1 + 2 + 4 + 7 + 14.</p>

<p>Motivated by this definition, we introduce the metric of imperfection of number N, denoted with f(N), as the absolute difference between N and the sum of its divisors less than N. It follows that perfect numbers’ imperfection score is 0, and the rest of natural numbers have a higher imperfection score. For example:</p>

<ul>
	<li>f(6) = |6 - 1 - 2 - 3| = 0,</li>
	<li>f(11) = |11 - 1| = 10,</li>
	<li>f(24) = |24 - 1 - 2 - 3 - 4 - 6 - 8 - 12| = |-12| = 12.</li>
</ul>

<p>Write a programme that, for positive integers A and B, calculates the sum of imperfections of all numbers between A and B: f(A) + f(A + 1) + ... + f(B).</p>

### 입력 

 <p>The first line of input contains the positive integers A and B (1 ≤ A ≤ B ≤ 10<sup>7</sup> ).</p>

### 출력 

 <p>The first and only line of output must contain the required sum.</p>

