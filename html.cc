/**
 * Filename: html.cc
 *
 * Description:
 *
 * Parse the html
 *
 */
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <sys/types.h>
#include <regex.h>
#include "html.h"

using namespace std;
//using namespace htmlcxx;

int Html::getContentUrl(string& url)
{
    string contenturls[16];
    ifstream htmlfile;
    int status;
    assert(htmlfile.open("index.html", ios::in) > 0);
    int s;
    htmlfile.open("index.html", ios::in);
    s = htmlfile.is_open();
    if(!s) {
    	// method 1.
    	/*
    	string temp = "wget";

    	temp += url;
    	temp += " -q -O index.html";
        */

    	// method 2
    	char temp2[512] = { 0 };

    	sprintf(temp2, "wget %s -q -O index.html", url.c_str());
    	status = system(temp2);
    	cout<<"download file is ok"<<status<<endl;
    } else {
		matchContent();
    	cout<<"index.html 文件已经存在"<<endl;
    }
    return 0;
}

int Html::matchContent(const char* regexStr)
{
	ifstream file;
	int length,s;
	regex_t oRegex;
	int errorCode = 0;
	char errorMsg[1024] = {0};
	size_t errorMsgLen = 0;
	regmatch_t match;

	file.open("index.html");
	s = file.is_open();
	if(!s) count<<"file is not exists"<<endl;
	file.seekg(0, ios::end);
	length = file.tellg();
	file.seekg(0, ios:beg);
	buffer = new char[length];
	file.read(buffer, length);
	file.close();
	
	if((errorCode = regcomp(&oRegex, regexStr, 0)) == 0){
		if((errorCode = regexec(&oRegex, buffer, 0, match, 0)) == 0){
			cout<<"match is"<<match<<endl;
			regfree(&oRegex);
			return 0;
		}
	}
}

Html::Html(){}

Html::~Html(){}
