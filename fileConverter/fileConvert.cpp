/*
* fileConvert.cpp
*
*  Created on: Jun 25, 2018
*      Author: ping
*/
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <cstdlib>
#include <string.h>
using namespace std;
int main(int argc, char *argv[]){
    const char s[2] = " ";
	ifstream fp;
	ofstream outFP;
	fp.open(argv[1],std::ios::in);
	string b = ".p";
	b =string(argv[1])+ b;
	if(!fp.is_open()){
		perror("read file fails");
		exit(EXIT_FAILURE);
	}
	outFP.open(b.c_str(),std:: ios::out);
	if(!outFP.is_open()){
		perror("write file fails");
				exit(EXIT_FAILURE);
	}
	// strat read
	string buff;
	char head;
	int numCs;
	getline(fp,buff);
	// Get the p line
	while(!fp.eof()){
		//cout<<buff<<endl;
		//todo:parseLine
		if(buff.empty()) break;
		head =buff.at(0);
		if(head == 'p'){
			char* str = strdup(buff.c_str());
	    	strtok(str, s);
			strtok(NULL, s);
			numCs = atoi(strtok(NULL, s));
			outFP<< numCs << ' '<< strtok(NULL, s)<< endl;
			break;
		}
	  getline(fp,buff);
	}
	// Get the clause
	int line = 0;
	while(!fp.eof() && line < numCs){
		getline(fp,buff);
		if(buff.empty()) break;
		char* str = strdup(buff.c_str());
		int lit;
		bool flag;
		char* token = strtok(str, s);
		 while(token != NULL){
			flag = false;
			if(*token== '-'){
				lit = -atoi(token);
				outFP<<lit << ' ';
				token = strtok(NULL, s);
				continue;
			}
			if(*token == '0'){
				outFP<<endl;
				flag = true;
				line++;
				break;
			}
			if(flag) break;
			lit = atoi(token);
			outFP<<lit << ' ';
			token = strtok(NULL, s);
		 }
	}

	outFP.close();
	fp.close();

};

