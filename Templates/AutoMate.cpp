/**
 * 
 * Author: withtahmid
 * Created: 16-07-22 23:59
 * Updated: 09-08-22 02:52
 * Updated: 30-08-22 20:40
 * Updated: 23-10-22 03:45
 * Updated: 14-12-22 03:17
 * 
 * */
#include<bits/stdc++.h>
#include<ctime>
#include <sys/stat.h>
#include<unistd.h> 
#include <fstream>
using namespace std;
string dateNtime = " * Created: ";
string path = "SYNC/";
string random_filename;
int numOfFile;
string random_name = "";
void generate_date()
{
	time_t rawtime;
  	struct tm * timeinfo;
  	char buffer[80], rand[50];
 	time (&rawtime);
  	timeinfo = localtime(&rawtime);
  	strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
  	strftime(rand,sizeof(buffer),"%d-%m-%Y-%H-%M-%S",timeinfo);
  	string str(buffer);
  	string randd(rand);
  	random_name = randd;
  	dateNtime += str;
}

bool generate_path()
{
	char c;
	char type;
	string folderName;
	cin >> c;
	if(c == 'C' || c == 'c')
	{	cin>> type >> folderName >> numOfFile;
		path += "Codeforces/div";
		path += type;
		path += "/";
		path += folderName;
		path += '/';
	}
	else if(c == 'A' || c == 'a')
	{
		cin>> type >> folderName >> numOfFile;
		path += "Atcoder/";
		type == 'b' || type == 'B' ? path +=  "Beginner" : path +=  "Regular" ;
		path += "/";
		path += folderName;
		path += '/';
	}
	else if(c == 'r' || c == 'R')
	{
		cin >> random_filename;
		path += "Random/";
		numOfFile = 1;
		return false;
	}
	else
	{
		path = "no-path";
	}
	return true;
}



bool create_files()
{	
	bool yes = true;

	if(!mkdir(path.c_str(), 0777))
	{
		for(int i = 0; i < numOfFile; i++)
		{
			string fileName = path;
		    fileName += 'A' + i;
		    fileName += ".cpp";
			string line;
		    ifstream ini_file{
		        "Template.cpp"
		    };
		    
		    ofstream out_file{ fileName};
		    if (ini_file and out_file) {
		  
		        while (getline(ini_file, line)) {
		        	while(line.size() and line[line.size()-1] == 13){
		        		line.pop_back();
		        	}
		        	if(line == " * Created: dd-mm-yy hh:mm")
		        		line = dateNtime;
		            out_file << line << "\n";
		        }
		    }
		    else {
		       cout<< "Cannot create file: "<<i<<endl;
		    	return false;
		    }
		    ini_file.close();
		    out_file.close();
		   	string command ="subl "; 
			command += fileName;
			system(command.c_str());
		}
	}
	else
	{
		cout<<"Some error occoured\n";
		return false;
	}
	return true;
}
bool create_random_file()
{	
	if(random_filename == "xx"){
		random_filename = random_name;
	}
	string fileName = path;
	fileName += random_filename;
    fileName += ".cpp";
	string line;
    ifstream ini_file{
        "Template.cpp"
    };
    
    ofstream out_file{fileName};
    if (ini_file && out_file) {
  
        while (getline(ini_file, line)) {
        	while(line.size() and line[line.size()-1] == 13){
        		line.pop_back();
        	}
        	if(line == " * Created: dd-mm-yy hh:mm"){
        		line = dateNtime;
        	}
            out_file << line << "\n";
        }
    }
    else {
       cout<< "Cannot create file"<<endl;
    	return false;
    }
    ini_file.close();
    out_file.close();
    path += random_filename;
    path += ".cpp";
	return true;
}
void create_io_files()
{
	string fileName = path;
	fileName += "input.txt";
	ofstream input(fileName);
	input.close();
	fileName = path;
	fileName += "output.txt";
	ofstream output(fileName);
	output.close();
}
void open_files_in_sublime_text()
{
	string command ="subl "; 
	command += path;
	system(command.c_str());
}
int main()
{
	generate_date();
	bool status =  generate_path();
	if(path != "no-path" && numOfFile > 0)
	{
		if(status)
		{
			if(create_files())
			{
				cout << endl << "cd "<<path<<endl;
			}
			else{
				cout << "Couldn't create file\n";	
			}
		}
		else
		{
			if(create_random_file())
			{
				open_files_in_sublime_text();
				cout << endl << "cd "<<path<<endl;
			}
			else{
				cout << "Couldn't create file\n";	
			}
		}
	}

	else{
		cout << "Invalid Path or File number\n";
	}
}