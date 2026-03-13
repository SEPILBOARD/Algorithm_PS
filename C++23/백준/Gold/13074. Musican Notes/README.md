# [Gold IV] Musican Notes - 13074 

[문제 링크](https://www.acmicpc.net/problem/13074) 

### 성능 요약

메모리: 2160 KB, 시간: 0 ms

### 분류

조합론, 다이나믹 프로그래밍, 수학

### 제출 일자

2026년 3월 13일 14:04:14

### 문제 설명

<p>We want to create a musical score consisting of a succession of notes. There are only two choices for the pitch of each note: each note has either a low sound or a high sound. There are also only two choices for the duration of each note: each note is either short or long. Each short note takes 1 second, and each long note takes 2 seconds. We have the following constraints:</p>

<p style="margin-left: 40px;">a) The total duration of the musical score should be a given integer <span style="line-height:1.6em">n.</span><br>
<span style="line-height:1.6em">b) The number of low short notes should be the same as the number of high short notes.</span><br>
<span style="line-height:1.6em">c) The number of low long notes should be the same as the number of high long notes.</span><br>
<span style="line-height:1.6em">d) There should be at least as many long notes as there are short notes.</span><br>
<span style="line-height:1.6em">e) Low and high notes must alternate.</span><br>
<span style="line-height:1.6em">f) The first note should be low.</span></p>

<p>Given an even integer n, we want to know the number of possible music scores satisfying the above. For example, with n = 6, there are 4 possibilities:</p>

<p>2211, 2112, 1221, 1122</p>

<p>(Each note is represented by its duration, and the high notes are shown in bold.)</p>

<p>With n = 8, there is only 1 possibility: 2222</p>

### 입력 

 <p>The first line of the input includes the number of test cases t, 1 ≤ t ≤ 10000. On each next line, a test case is specified by giving the even integer n, 2 ≤ n ≤ 100.</p>

<p> </p>

### 출력 

 <p>For each test case, print one line containing the answer to the question.</p>

