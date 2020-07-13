library(Rcpp)

#import c++ code
sourceCpp("parseCsv.cpp")

#call c++ method to parse CSV file
#parsefile([filepath],[interval],[variance])
parsefile("C:/Users/olin/Desktop/AIS_ASCII_by_UTM_Month/2017_v2/AIS_2017_01_Zone10.csv",10,30)