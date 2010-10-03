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

static inline bool data_valid(const form_iterator &it, const Cgicc &form)
{
	return (!it->isEmpty() && it != (&form).end());
}

int main(int argc, char **argv)
{
    try {
       Cgicc formData;

       // Send HTTP header: Content-type: text/html
       cout << HTTPHTMLHeader() << endl;

       // Print: <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0//EN" "http://www.w3.org/TR/REC-html40/strict.dtd">
       cout << HTMLDoctype(HTMLDoctype::eStrict) << endl;

       // Set up the HTML document
       cout << html() << head();
	cout << "<meta http-equiv=\"content-type\" content=\"text/html; charset=UTF-8\">";

	form_iterator temperature = formData.getElement("temp");
	form_iterator drink = formData.getElement("drink");

	if (data_valid(temperature, formData) && data_valid(drink, formData)) {
/*
		if (**temperature == ZERO)
			show_coffee(cold_coffee);
		else
			show_coffee(hot_coffee);

	}
*/
	cout << "飲料: " << **drink << " 溫度: " << **temperature << endl;
	}
       cout << body() << html();
    }
    catch(exception& e) {
       // handle any errors here.
       cout << "ERROR!!" << endl;
    }
    return 0;   // To avoid Apache errors.
}

