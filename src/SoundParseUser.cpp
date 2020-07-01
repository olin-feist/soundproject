#include <iostream>
#include <string>
#include<algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

#include <chrono> 

using namespace std;
using namespace std::chrono;

ifstream file;
int interval;

class row{
    public:
    int mmsi;
    string basedatetime;
    float lat; 
    float longitude;
    float sog; 
    float cog;
    int heading;
    string vesselname;
    string imo; 
    string callsign;
    string vesseltype;
    string status;
    string length; 
    string width;
    string draft;
    string cargofile;

    row(int  mmsi1, string basedatetime1,float lat1, float longitude1, float sog1, float cog1,
    int heading1, string vesselname1, string imo1, string callsign1, string vesseltype1, string status1, string length1, string width1,string draft1,string cargofile1){
        mmsi=mmsi1;
        basedatetime=basedatetime1;
        lat=lat1;
        longitude=longitude1;
        sog=sog1;
        cog=cog1;
        heading=heading1;
        vesselname=vesselname1;
        imo=imo1;
        callsign=callsign1;
        vesseltype=vesseltype1;
        status=status1;
        length=length1;
        width=width1;
        draft=draft1;
        cargofile=cargofile1;        
    }

};
//vector of row objects to store tables
vector<row> table;

//compare function to sort by time
bool comparetime(const row& r1, const row& r2){
    int day1=stoi((r1.basedatetime).substr(8,2));
    int day2=stoi((r2.basedatetime).substr(8,2));
    int hour1=stoi((r1.basedatetime).substr(11,2));
    int hour2=stoi((r2.basedatetime).substr(11,2));
    int min1=stoi((r1.basedatetime).substr(14,2));
    int min2=stoi((r2.basedatetime).substr(14,2));
    int sec1=stoi((r1.basedatetime).substr(17,2));
    int sec2=stoi((r2.basedatetime).substr(17,2));

    // All cases when true should be returned 
    if (day1 < day2){ 
        return true; 
    }else if (day1 == day2 && hour1 < hour2){ 
        return true; 
    }else if (day1 == day2 && hour1 == hour2 && min1 < min2){ 
        return true;
    }else if(day1 == day2 && hour1 == hour2 && min1 == min2 && sec1<sec2){
        return true; 
    }
            
            
    return false; 
}

bool findclose(int a){
    int temp=0;
    while(temp<=a+1){
        if(a-temp==-1){
           
            return true;
        }else{
            temp+=interval;
        }

    }
    return false;
}


void parsefile(){
    //code takes user input for file name
    
    inputusrfile:
    string filename;
    cout << "Type your csv file path: ";
    cin >> filename; // get user input from the keyboard
    cout << "Your File is: " << filename<<endl;

    //import csv file to "file"
    ifstream file(filename.c_str());


    
    //skip first line of csv file (Skip Headers)
    string line;
    getline(file, line);

    //test if file was loaded
    if(line.empty()){
        cout<<"file not loaded"<<endl;
        goto inputusrfile;
    }else{
        cout<<"File Loaded..."<<endl;
        cout<<"Running..."<<endl;
    }


    //userinput time interval
    cout << "Time interval to parse: ";
    int tempinter;
    cin >> tempinter; // get user input for interval
    interval=tempinter;
    cout<<endl;
    


    //object to hold row data
    row* temp;


    //vector to hold row data
    vector<string> v;
    
    //auto start = high_resolution_clock::now(); 
    auto start = high_resolution_clock::now(); 

    //loop through csv file
    while (getline(file, line)){
   
        
        //clear vector
        v.clear();

        //get current line value and add it to sting line then convert to string stream
        stringstream ss(line); 

        //convert line into set of strings, store in vector v
        while (ss.good()) { 
            string substr; 
            getline(ss, substr, ','); 
          
            v.push_back(substr); 
        }


        //only add by 5 min itervals and ignore certain statuses
        
        //convert min and seconds to ints
        int tempint=stoi(v[1].substr(14,2));
        int tempint2=stoi(v[1].substr(17,2));



        //filter by type
        if(v[11]!=("at anchor")&&(v[11]!=("moored"))&&(v[11]!=("aground"))){
            
            //5 min interval
            if(tempint%interval==0){
               
                temp=new row(stoi(v[0]),v[1],stof(v[2]),stof(v[3]),stof(v[4]),stof(v[5]),stoi(v[6]),v[7],v[8],v[9],v[10],v[11],v[12],v[13],v[14],v[15]);
                table.push_back(*temp);
            }else if(findclose(tempint)){
                if(tempint2>=57){
                    temp=new row(stoi(v[0]),v[1],stof(v[2]),stof(v[3]),stof(v[4]),stof(v[5]),stoi(v[6]),v[7],v[8],v[9],v[10],v[11],v[12],v[13],v[14],v[15]);
                    table.push_back(*temp);
                    
                }

            }
        }
 
    }

    cout<<"Parsed by "<< interval <<" min intervals"<<endl;

    //sort table by mmsi
    sort(table.begin(), table.end(), [](const row& lhs, const row& rhs) {
      return lhs.mmsi < rhs.mmsi;
    });

    cout<<"sorted by boat id"<<endl;
    //--------------------


    //sort boats by time --------
    int startindex=0;
    int endindex=0;
    int boatid=table[0].mmsi;

    for(int i=0;i<table.size();i++){
        
        if(boatid!=table[i].mmsi||i==table.size()-1){
    

            sort(table.begin()+startindex, table.begin()+endindex, comparetime);
                
            boatid=table[i].mmsi;
            startindex=i;
            endindex=i;
        }else{
            endindex++;
        }
    }
    cout<<"sorted by time"<<endl;
    //-------------------------

    //write to csv file ----------
    ofstream file_stream;                                                  
    file_stream.open ("soundparse.csv");

    for(int i=0;i<table.size();i++){
        row currentrow=table[i];
        file_stream<<currentrow.mmsi<<",";
        file_stream<<currentrow.basedatetime<<",";
        file_stream<<currentrow.lat<<",";
        file_stream<<currentrow.longitude<<",";
        file_stream<<currentrow.sog<<",";
        file_stream<<currentrow.cog<<",";
        file_stream<<currentrow.heading<<",";
        file_stream<<currentrow.vesselname<<",";
        file_stream<<currentrow.imo<<",";
        file_stream<<currentrow.callsign<<",";
        file_stream<<currentrow.vesseltype<<",";
        file_stream<<currentrow.status<<",";
        file_stream<<currentrow.length<<",";
        file_stream<<currentrow.width<<",";
        file_stream<<currentrow.draft<<",";
        file_stream<<currentrow.cargofile<<endl;

        
    }

    file_stream.close();
    //-------------------------

    //get time of run
   auto stop = high_resolution_clock::now(); 
   auto duration = duration_cast<seconds>(stop - start); 
   float time=duration.count()/60;
    cout<<"Done."<<endl;
    cout<<setprecision(2)<<"Elapsed Time: "<<duration.count()/60<<"."<<duration.count()%60<<" minutes" << endl;
    


    
}

int main(){

    parsefile();
}

