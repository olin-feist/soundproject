# soundproject

## Description

Code to parse csv file by specific time intervals, drag and drop file into terminal or type file path then specify time interval to parse by. Outputs CSV sorted by boat ID and time.

## Compiling

#### To compile:
+ Navigate to file directory in terminal and enter the src file(/..../soundproject/src/)

+ Then type:

<b>g++ -O2 -std=c++17 SoundParseUser.cpp -o SoundParseUser</b>

+ then run the executable 

#### options:

+ Changing the -O2 flag to -O3 will increase speed but will require much more memory
+ The -std=c++17 flag is only need on Mac and certain g++ compiler version

## Runtime/Output

| Interval      | #of records   |
| ------------- |:-------------:| 
| 5             | 5.6 million   |
| 10            | 2.5 million   | 
| 15            | 2.2 million   |

##### with -O2 Flag:

| Interval      | Runtime       |
| ------------- |:-------------:| 
| 5             | 3.2 minutes   |
| 10            | 2.2 minutes   | 
| 15            | 2   minutes   |
