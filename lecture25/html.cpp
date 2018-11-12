#include <iostream>
#include <stdlib.h>
using namespace std;


int main () {
    
   cout << "Content-type:text/html"<<endl<<endl;
   cout << "<html>"<<endl;
   cout << "<body>"<<endl;
   char *value = getenv("QUERY_STRING");
   cout << "<p>QUERY_STRING: " << value << "</p>" << endl;
   cout << "</body>" << endl;
   cout << "</html>" << endl;
   return 0;
}