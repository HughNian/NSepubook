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
    //string contenturls[16];
    ifstream htmlfile;
    int status;
    //assert(htmlfile.open("index.html", ios::in) > 0);
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
		cout<<"输入正则表达式"<<endl;
		char regexStr[1024] = {0};
		scanf("%s", &regexStr);
		printf("regexStr is %s\n", regexStr);
		matchContent(regexStr);
    	cout<<"index.html 文件已经存在"<<endl;
    }
    return 0;
}

int Html::matchContent(const char* regexStr)
{	
	ifstream file;
	fstream txt;
	int length,s,i;
	regex_t oRegex;
	int errorCode = 0;
	char errorMsg[1024] = {0};
	size_t errorMsgLen = 0;
	regmatch_t* match;
	char value[1024] = {0}; 
	
	/*
	file.open("index.html");
	s = file.is_open();
	if(!s) cout<<"file is not exists"<<endl;
	length = file.tellg();
	char* buffer = new char[length];
	file.read(buffer, length);
	file.close();
	*/
	
	const char* buffer = "http://www.baidu.com";
	printf("method's regexStr %s\n", regexStr);
	int count_temp = 0;
	if((errorCode = regcomp(&oRegex, regexStr, 0)) == 0){
		if((errorCode = regexec(&oRegex, buffer, 0, match, 0)) == 0){
			cout<<"match is"<<match<<endl;
			for(i = match[0].rm_so; i < match[0].rm_eo; ++i){
				printf("%c", buffer[i]);
				sprintf(&value[count_temp ++], "%c", buffer[i]);
			}
			printf("%s", value);
			regfree(&oRegex);
		}
	}
	
	FILE *fp;

	if((fp = fopen("epub.txt", "a")) != NULL) {
		fputs(value, fp);
		rewind(fp);
	}
	fclose(fp);
	return 0;
}

Html::Html(){}

Html::~Html(){}
