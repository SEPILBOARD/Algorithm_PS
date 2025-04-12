# [Platinum V] Pebbles - 4496 

[문제 링크](https://www.acmicpc.net/problem/4496) 

### 성능 요약

메모리: 4000 KB, 시간: 672 ms

### 분류

비트마스킹, 다이나믹 프로그래밍, 비트필드를 이용한 다이나믹 프로그래밍, 문자열

### 제출 일자

2025년 4월 13일 02:41:43

### 문제 설명

<p>You’re given an unlimited number of pebbles to distribute across an N x N game board (N drawn from [3, 15]), where each square on the board contains some positive point value between 10 and 99, inclusive. A 6 x 6 board might look like this:</p>

<table class="table table-bordered" style="width:30%">
	<tbody>
		<tr>
			<td>33</td>
			<td>74</td>
			<td>26</td>
			<td>55</td>
			<td>79</td>
			<td>54</td>
		</tr>
		<tr>
			<td>67</td>
			<td>56</td>
			<td>91</td>
			<td>72</td>
			<td>44</td>
			<td>32</td>
		</tr>
		<tr>
			<td>44</td>
			<td>64</td>
			<td>22</td>
			<td>91</td>
			<td>29</td>
			<td>61</td>
		</tr>
		<tr>
			<td>61</td>
			<td>32</td>
			<td>76</td>
			<td>50</td>
			<td>50</td>
			<td>32</td>
		</tr>
		<tr>
			<td>81</td>
			<td>65</td>
			<td>56</td>
			<td>38</td>
			<td>96</td>
			<td>36</td>
		</tr>
		<tr>
			<td>38</td>
			<td>78</td>
			<td>50</td>
			<td>92</td>
			<td>90</td>
			<td>75</td>
		</tr>
	</tbody>
</table>

<p>The player distributes pebbles across the board so that:</p>

<ul>
	<li>At most one pebble resides in any given square.</li>
	<li>No two pebbles are placed on adjacent squares. Two squares are considered adjacent if</li>
</ul>

<p>they are horizontal, vertical, or even diagonal neighbors. There’s no board wrap, so 44 and 61 of row three aren’t neighbors. Neither are 33 and 75 nor 55 and 92.</p>

<p>The goal is to maximize the number of points claimed by your placement of pebbles.</p>

<p>Write a program that reads in a sequence of boards from an input file and prints to stdout the maximum number of points attainable by an optimal pebble placement for each. </p>

### 입력 

 <p>Each board is expressed as a series of lines, where each line is a space-delimited series of numbers. A blank line marks the end of each board (including the last one)</p>

### 출력 

 <p>Your program would print the maximum number of points one can get by optimally distributing pebbles while respecting the two rules, which would be this (each output should be printed on a single line and followed with a newline):</p>

