/**
 * Filename:htmlcxx.h
 *
 *
 */
#include <string>
//#include "lib/htmlcxx/html/ParserDom.h"

using namespace std;

class Html
{
public:
    Html();
    ~Html();

    int GetContentUrl(string& url);
};
