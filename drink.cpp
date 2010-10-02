#include <iostream>
#include <vector>
#include <string>

#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.hpp"

using namespace std;
using namespace cgicc;     // Or reference as cgicc::Cgicc formData; below in object instantiation.

string ZERO = "0";
string ONE = "1";

template <size_t N>
void show_coffee(const string (&coffee)[N])
{
        cout << "<select>" << endl;
        for (size_t i = 0; i < N; ++i) {
                cout << "<option value=" << i << ">" << coffee[i] << "</option>" << endl;
        }
        cout << "</select>" << endl;
}

int main(int argc, char **argv)
{
    try {
       Cgicc formData;

       // Send HTTP header: Content-type: text/html
       cout << HTTPHTMLHeader() << endl;

       // Print: <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0//EN" "http://www.w3.org/TR/REC-html40/strict.dtd">
       cout << HTMLDoctype(HTMLDoctype::eStrict) << endl;

       // Print: <html lang="en" dir="LTR">
//       cout << html().set("lang", "EN").set("dir", "LTR") << endl;

       // Set up the HTML document
       cout << html() << head();
	cout << "<meta http-equiv=\"content-type\" content=\"text/html; charset=UTF-8\">";
#if 0
	cout << title("Cgicc example") << head() << endl;
       cout << body().set("bgcolor","#cccccc").set("text","#000000").set("link","#0000ff").set("vlink","#000080") << endl;

       cout << h1("幹This is a demonstration of the GNU CgiCC library") << endl;

       form_iterator fvalue1 = formData.getElement("value1");
       if( !fvalue1->isEmpty() && fvalue1 != (*formData).end()) {
          cout << "Value1: " << **fvalue1 << endl;
       }
       else
          cout << "No text entered for value1" << endl;

       cout << p();
#endif
	form_iterator temperature = formData.getElement("temp");
	if( !temperature->isEmpty() && temperature != (*formData).end()) {
		if (**temperature == ZERO)
			show_coffee(cold_coffee);
		else
			show_coffee(hot_coffee);
	}
       cout << body() << html();
    }
    catch(exception& e) {
       // handle any errors here.
       cout << "ERROR!!" << endl;
    }
    return 0;   // To avoid Apache errors.
}

