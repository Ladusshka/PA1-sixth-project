# PA1-sixth-project
The task is to create a program that will solve a logic game - removing tokens.
The game is played by two players A and B. There are between 1 and 100 chips in a row on the table. Each chip has a value written on it, the value is an integer (positive, zero or negative). Players take turns, starting with Player A. The player on the turn may take 1 to 2 chips of his choice. In addition, a player may not take two chips in two consecutive turns (if a player takes two chips in one turn, he must take only one chip in his next turn). Chips may only be taken from the beginning or the end of the row. If a player takes two chips from the same end of the row, the outermost chip must be taken first, and then the chip so accessed. The game ends when one player removes the last chip. The winner is the player who has obtained the greater sum of the values of his chips.

We assume that both players play absolutely efficiently. That is, each player removes chips in such a way as to obtain the highest sum of his chips. The problem is to find the sequence of these efficient moves and determine who wins.

The input to the program is a sequence of integers. These numbers represent the values of the chips as they are next to each other on the table. When taking, we refer to the chips by their index (0 to count-1).
The output of the program is the found sequence of moves of each player. Each move is on a separate line. The moves are always prefixed with the player identification (A or B, alternating) followed by the index of the chip taken (the index can be one or two depending on the number of chips taken) and ending with the value(s) of the chips taken. The last line of the output is information about the chip totals of both players.

If the input is invalid, the program must detect this and display an error message. Display the error message on the standard output (not on the error output). When an error is detected, the program exits. Consider the following as an error:
      An empty token sequence was entered or there were more than 100 tokens,
      the token value is not an integer.
 A demonstration of how the programme works:
Zetons:
100 100 100 100 100 100
A [0]: 100
B [1]: 100
A [2]: 100
B [5], [4]: 100 + 100
A [3]: 100
A: 300, B: 300

Zetons:
3 5 3 6 1
A [0]: 3
B [1], [2]: 5 + 3
A [4], [3]: 1 + 6
A: 10, B: 8

Zetons:
-11 5 3 6 -1
A [4]: -1
B [3], [2]: 6 + 3
A [1]: 5
B [0]: -11
A: 4, B: -2

Zetons:
1 5 3 6 2 1 8 2 3
A [0], [1]: 1 + 5
B [8]: 3
A [2]: 3
B [7], [6]: 2 + 8
A [3], [4]: 6 + 2
B [5]: 1
A: 17, B: 14     


Zetons:
-57 87 -75 117 44 96
A [5]: 96
B [4], [3]: 44 + 117
A [0], [1]: -57 + 87
B [2]: -75
A: 126, B: 86

Zetons:
73 -7 118 86 11 -11 83
A [6]: 83
B [0]: 73
A [1], [2]: -7 + 118
B [3], [4]: 86 + 11
A [5]: -11
A: 183, B: 170

Zetons:
-34 -1 94 111 43 78 -79 13
A [0], [7]: -34 + 13
B [6], [5]: -79 + 78
A [1]: -1
B [2]: 94
A [4], [3]: 43 + 111
A: 132, B: 93

Tokens:
2 62 132 25 71 9 52 44 58 15 58 -65
A [11], [10]: -65 + 58
B [0]: 2
A [1]: 62
B [2]: 132
A [3], [4]: 25 + 71
B [9], [8]: 15 + 58
A [5]: 9
B [6]: 52
A [7]: 44
A: 204, B: 259
Tokens:
140 -63 11 -18 138 -10 0 -74 138 146 43 116 -62
A [0]: 140
B [12], [11]: -62 + 116
A [10]: 43
B [9]: 146
A [8]: 138
B [1]: -63
A [7]: -74
B [2]: 11
A [3], [4]: -18 + 138
B [6]: 0
A [5]: -10
A: 357, B: 148
Tokens:
127 62 -84 138 141 96 101 42 -29 140 44 9 -6 130
A [0], [13]: 127 + 130
B [1]: 62
A [12]: -6
B [11], [10]: 9 + 44
A [9], [8]: 140 + -29
B [7]: 42
A [6]: 101
B [5], [4]: 96 + 141
A [3]: 138
B [2]: -84
A: 601, B: 310

Tokens:
-92 92 80 47 6 60 86 -82 -86 93 75 -69 -24 -81 71
A [14]: 71
B [13], [12]: -81 + -24
A [11]: -69
B [10]: 75
A [9]: 93
B [0], [1]: -92 + 92
A [2]: 80
B [3]: 47
A [8]: -86
B [7], [6]: -82 + 86
A [5], [4]: 60 + 6
A: 155, B: 21
Tokens:
hello
Nespravny vstup.

Tokens:
-92 92 80 47 6 60 86 -82 -86 93 75 -69 -24 -81 71
A [14]: 71
B [13], [12]: -81 + -24
A [11]: -69
B [10]: 75
A [9]: 93
B [0], [1]: -92 + 92
A [2]: 80
B [3]: 47
A [8]: -86
B [7], [6]: -82 + 86
A [5], [4]: 60 + 6
A: 155, B: 21

Tokens:
hello
Nespravny vstup.



      
