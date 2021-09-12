#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

main()
{
   vector<string> VS;
   stack<string> SS;
   VS.push_back("The number is 10");
   VS.push_back("The number is 20");
   VS.push_back("The number is 30");

   SS.push("The number is 10");
   SS.push("The number is 20");
   SS.push("The number is 30");

   cout << "Loop by index:" << endl;
   for(int ii=0; ii < VS.size(); ii++)
   {
      cout << VS[ii] << endl;
   }

   cout << endl << "Vector Constant Iterator:" << endl;
   vector<string>::const_iterator cii;
   for(cii=VS.begin(); cii!=VS.end(); cii++)
   {
      cout << *cii << endl;
   }
   cout << endl << "Stack Iterating" << endl;
   while (!SS.empty())
   {
     cout << "poped from stack:" << SS.top() << '\n';
     SS.pop();
   }
   
   cout << endl << "Reverse Iterator:" << endl;
   vector<string>::reverse_iterator rii;
   for(rii=VS.rbegin(); rii!=VS.rend(); ++rii)
   {
      cout << *rii << endl;
   }

   cout << endl << "Sample Output:" << endl;
   cout << VS.size() << endl;
   cout << VS[2] << endl;
   swap(VS[0], VS[2]);
   cout << VS[2] << endl;
   system("pause");
}
