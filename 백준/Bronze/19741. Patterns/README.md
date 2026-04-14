# [Bronze I] Patterns - 19741 

[문제 링크](https://www.acmicpc.net/problem/19741) 

### 성능 요약

메모리: 14928 KB, 시간: 128 ms

### 분류

수학, 브루트포스 알고리즘, 정수론, 소수 판정

### 제출 일자

2026년 4월 14일 18:10:52

### 문제 설명

<p>Inspired by the Ulam spiral, which unravels strange patterns of prime numbers' distribution, Petya decided to come up with his own analog.</p>

<p>Petya writes down integers from $1$ to $n^2$ into square table of size $n\times n$ starting from the upper left corner. Numbers from $1$ to $n$ go into the first row, numbers from $n + 1$ to $2n$  --- into the second row, and so on.</p>

<p>Then he colors cells which contain the number with no more than $k$ different divisors. After that, Petya studies the resulting picture in hope of finding some patterns. For example, if $n = 7$, $k = 3$, Petya will get the following picture:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/5571537d-b76c-4f1a-a0c4-3db58d756d13/-/preview/" style="width: 203px; height: 200px;"></p>

<p>Help Petya, print the picture which he will get after coloring, representing colored cells with asterisks <<<code>*</code>>>, and non-colored cells with dots <<<code>.</code>>>.</p>

### 입력 

 <p>Input contains two integers $n$ and $k$ ($1 \le n \le 40$, $1 \le k \le n^2$).</p>

### 출력 

 <p>Output $n$ lines, each one containing $n$ characters. If the $j$-th cell of $i$-th row of Petya's table is colored, then $j$-th character of $i$-th line should be equal to <<<code>*</code>>>, and <<<code>.</code>>> otherwise.</p>

