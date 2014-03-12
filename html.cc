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
#include "html.h"

using namespace std;
//using namespace htmlcxx;

int Html::GetContentUrl(string& url)
{
    string contenturls[16];
    ifstream htmlfile;
    int status;
    assert(htmlfile.open("index.html", ios::in) > 0);
    if(htmlfile.open("index.html", ios::in) < 0) {
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
    	cout<<"index.html 文件已经存在"<<endl;
    }
    return 0;
}

Html::Html(){}

Html::~Html(){}
