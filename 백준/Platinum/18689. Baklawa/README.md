# [Platinum III] Baklawa - 18689 

[문제 링크](https://www.acmicpc.net/problem/18689) 

### 성능 요약

메모리: 2084 KB, 시간: 0 ms

### 분류

게임 이론, 스프라그–그런디 정리

### 제출 일자

2026년 2월 12일 21:30:41

### 문제 설명

<p>Baklawa or baklava, is a sweet middle eastern dessert, mainly made from phyllo dough sheets, walnuts, and sugar syrup cut into small cubic pieces and served in cuboid boxes containing multiple layers.</p>

<p>Alice and Bob love to play what they call the last Baklawa game, The rules are as follows:</p>

<ul>
	<li>They choose a cuboid containing X by Y by Z cells of Baklawa to play with.</li>
	<li>There are N poisonous cells both players know them.</li>
	<li>Alice plays first, and the two players alternate.</li>
	<li>In his/her turn the player has to cut the cuboid into two cuboids at least one of which is safe (doesn’t contain a poisonous cube) and eats the safe part. The game continues with the other part.</li>
	<li>A cut is made by slicing along one of the axis X, Y or Z.</li>
	<li>The person who cannot make a move in his/her turn losses the game.</li>
</ul>

<p>Assuming both players play optimally, you are asked the following question: who wins the game?</p>

### 입력 

 <p>Your program will be tested on one or more test cases. The first line of the input will be a single integer T, the number of test cases (1 ≤ T ≤ 100).</p>

<p>Each test case starts with a line containing four space separated integers:</p>

<ul>
	<li>X: The length of the cuboid (1 ≤ X ≤ 1, 000, 000, 000)</li>
	<li>Y : The width of the cuboid (1 ≤ Y ≤ 1, 000, 000, 000)</li>
	<li>Z: The height of the cuboid (1 ≤ Z ≤ 1, 000, 000, 000)</li>
	<li>N: The number of poisonous cells. (0 ≤ N ≤ 100)</li>
</ul>

<p>Followed by N lines each containing three space separated integers:</p>

<ul>
	<li>x<sub>i</sub>: The x-coordinate of the i-th cube. (1 ≤ x<sub>i</sub> ≤ X)</li>
	<li>y<sub>i</sub>: The y-coordinate of the i-th cube. (1 ≤ y<sub>i</sub> ≤ Y )</li>
	<li>z<sub>i</sub>: The z-coordinate of the i-th cube. (1 ≤ z<sub>i</sub> ≤ Z)</li>
</ul>

### 출력 

 <p>For each test case, print a single line containing ‘Alice’ if Alice wins the game, or ‘Bob’ otherwise.</p>

