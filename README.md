# hotzenplotz

Compare all words of /usr/share/dict/words to the word 'hotzenplotz'
calculating the Hamming distance and printing the words and the result to
stdout.

Words with different length are ignored.

Example
```
...
hotzenplotz <-> biostatical : 11
hotzenplotz <-> biotechnics : 10
hotzenplotz <-> bipaleolate : 9
hotzenplotz <-> biparasitic : 11
hotzenplotz <-> bipartitely : 11
...
```

Prints a Summary at the end
```
Summary:
    Strings of different length:209873
    Strings of Hamming distance 0:0
    Strings of Hamming distance 1:0
    Strings of Hamming distance 2:0
    Strings of Hamming distance 3:0
    Strings of Hamming distance 4:0
    Strings of Hamming distance 5:0
    Strings of Hamming distance 6:15
    Strings of Hamming distance 7:80
    Strings of Hamming distance 8:653
    Strings of Hamming distance 9:2975
    Strings of Hamming distance 10:9472
```
