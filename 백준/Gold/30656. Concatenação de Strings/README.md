# [Gold II] Concatenação de Strings - 30656 

[문제 링크](https://www.acmicpc.net/problem/30656) 

### 성능 요약

메모리: 13900 KB, 시간: 168 ms

### 분류

KMP, 문자열

### 제출 일자

2025년 8월 1일 16:22:48

### 문제 설명

<p>Seja s uma string. Denotamos por s<sup>n</sup> a concatenação de n cópias de s. Por exemplo, se s = “eri” e n = 3, temos s<sup>3</sup> = “erierieri”.</p>

<p>Dadas strings r e s, sua tarefa é determinar se existem inteiros m e n tais que r<sup>m</sup> = s<sup>n</sup>.</p>

### 입력 

 <p>Cada linha da entrada conterá duas strings, separadas por um espaço, compostas apenas por letras minúsculas. Cada uma das strings terá pelo menos 1 e no máximo 1.000.000 caracteres. A última linha da entrada será composta por duas strings “#’ separadas por espaço. Esta linha não deve ser processada.</p>

### 출력 

 <p>Para cada linha da entrada, você deve gerar uma linha de saída contendo os menores inteiros m e n separados por espaço caso tais inteiros existam, e “NAO”, em caso contrário.</p>

