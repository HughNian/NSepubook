/******
 * NSepubook
 *
 * @author: hughnian <hugh.nian@163.com>
 *
 *
 ******/
#include <iostream>
#include <string>
#include "html.h"

using namespace std;

int main(void)
{
	cout<<"####### 请输入需要采集的网址 ######\n";
    string url;
    cin>>url;

    Html H;
    H.getContentUrl(url);

    return 0;
}
