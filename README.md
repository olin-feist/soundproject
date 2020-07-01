# soundproject

## Description

Code to parse csv file by specific time intervals, drag and drop file into terminal or type file path then specify time interval to parse by. Outputs CSV sorted by boat ID and time.

## Compiling

#### To compile:
##### Windows
+ For windows click shortcut or run executable
##### Mac
+ Navigate to file directory in terminal and enter the src file(/..../soundproject/src/)

+ Then type:

<b>g++ -O2 -std=c++17 SoundParseUser.cpp -o SoundParseUser</b>

+ then run the executable 

#### options:

+ Changing the -O2 flag to -O3 will increase speed but will require much more memory
+ The -std=c++17 flag is only need on Mac and certain g++ compiler version

# Running

#### User Input:
+ Interval: the interval the code will parse by
+ "Close to time interval": how close and entry must be in order to be saved, must be less than or equal to 60 seconds

#### Output:

+ Text will be outputed to terminal after each stage is complete
+ Time is outputed when done in minutes,seconds
+ Displays number of entries in CSV File
+ Writes to CSV file sorted by boat and time

## Runtime/Output
###### Run on 2017_01_zone10, 30 million records

| Interval (min)|Variance(sec)| #of records   |
| ------------- |-------------|:-------------:| 
| 5             |5            |5.6 million    |
| 10            |5            |2.8 million    | 
| 15            |5            |1.9 million    |

##### with -O2 Flag:
##### specs: intel i7 8 cores 2.8 ghz, 16gb ram

| Interval (min)|Variance(sec)|Runtime (min,sec)|
| ------------- |-------------|:-------------:  |  
| 5             |5            |3:47             |
| 10            |5            |2:23             | 
| 15            |5            |1:54             |
