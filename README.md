# soundproject
## Description:
This Repostitory contains c++ code that is desighned to run in R and run on its own.

### Table of Contents:
* <b>[R packages](#R-packages)</b>
   * <b>[ParseCSV](#ParseCSV)</b>
* <b>[C++ Scripts](#Cpp-Scripts)</b>
   * <b>[SoundParseUser](#SoundParseUser)</b>

---
# R packages
#### C++ packages linked to R through Rcpp library

## ParseCSV
### Description:
Creates a method in R that parses CSV file by time interval and variance

### To Use:
1. add Rcpp library
2. use sourceCpp and include file path to "ParseCSV.cpp"
3. then you can call the cpp method parsefile() by passing the CSV filepath the time interval to parse and 
the variance (How many seconds off an entry can be from a given interval)

``` R
library(Rcpp)
sourceCpp("/.../parseCsv.cpp")
parsefile([filepath],[interval],[variance])
```


---

# Cpp Scripts

#### Standalone C++ code that is not currently compatible with R but will preform tasks much faster
## SoundParseUser
### Description

Code to parse csv file by specific time intervals, drag and drop file into terminal or type file path then specify time interval to parse by. Outputs CSV sorted by boat ID and time.

### Compiling

#### To compile:
##### Windows
+ For windows click shortcut or run executable
##### Mac
+ Navigate to file directory in terminal and enter the src file(/..../soundproject/src/)

+ Then type:

<b>g++ -O2 -std=c++17 SoundParseUser.cpp -o SoundParseUser</b>
###### On certain mac compilers(xcode 9.2) you must use these compiler options:
   ###### g++ -O2 -std=c++1z SoundParseUser.cpp -o SoundParseUser

+ then run the executable 

#### options:

+ Changing the -O2 flag to -O3 will increase speed but will require much more memory
+ The -std=c++17 flag is only need on Mac and certain g++ compiler version

### Running

#### User Input:
+ Interval: the interval the code will parse by
+ "Close to time interval": how close and entry must be in order to be saved, must be less than or equal to 60 seconds

#### Output:

+ Text will be outputed to terminal after each stage is complete
+ Time is outputed when done in minutes,seconds
+ Displays number of entries in CSV File
+ Writes to CSV file sorted by boat and time

## Runtime/Output
###### Run on 2017_01_zone10, 32 million records

| Interval (min)|Variance(sec)| #of records   |
| ------------- |-------------|:-------------:| 
| 5             |30           |5.5 million    |
| 10            |30           |2.6 million    | 
| 15            |30           |1.9 million    |

##### with -O2 Flag:
##### specs: intel i7 8 cores 2.8 ghz, 16gb ram

| Interval (min)|Variance(sec)|Runtime (min,sec)|
| ------------- |-------------|:-------------:  |  
| 5             |30           |3:23             |
| 10            |30           |2:09             | 
| 15            |30           |1:45             |
