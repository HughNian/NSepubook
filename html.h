/**
 * Filename:htmlcxx.h
 *
 *
 */
#include <string>
#include "ParserDom.h"

using namespace std;

class Html
{
public:
    Html();
    ~Html();

    int GetContentUrl(string& url);
};
