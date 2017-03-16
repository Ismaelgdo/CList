
// TestList.cpp

#include <cstdlib>
#include <iostream>
#include "List.h"

using namespace std;

int main(int argc, char *argv[])
{
	List l;
	int i;
	size_t p, cap;
	int val;
	char c; //choice of operation
	
	while(1)
	{
    try
    {
  		cout << "List = " << l << endl;
  		cout << "Select an operation: " << endl;
  		cout << "(a)ppend (i)nsert i(n)dex (p)op (r)emove re(s)ize (e)xtend (q)uit: " << endl;
  		cin >> c;
  		
  		if (c == 'a')
  		{
  			cout << "Enter a value: ";
  			cin >> val;
  			l.append(val);
  		}
		
  		if (c == 'i')
  		{
  			cout << "Enter a value: ";
  			cin >> val;
  			cout << "Enter a position: ";
  			cin >> p;
  			l.insert(p, val);
  		}
  		if (c == 'n')
  		{
  			cout << "Enter a value: ";
  			cin >> val;
  			cout << val << " has index " << l.index(val) << endl;
  		}
  		if (c == 'p')
  		{
  			cout << "Enter a position: ";
  			cin >> p;
  			l.pop(p);
  		}
  		if (c == 'r')
  		{
  			cout << "Enter a value: ";
  			cin >> val;
  			l.remove(val);
  		}
  		if (c == 's')
  		{
  			cout << "Enter a new capacity: ";
  			cin >> cap;
  			l.resize(cap);
  		}

  		if (c == 'e')
  		{
  			List l2;
  			cout << "Enter a new list: ";
  			cin >> l2;
  			cout << "This is l2: " <<l2<<endl;
  			//l += l2;
  			l.extend(l2);
  		}
		
  		if (c == 'q')
  			break;
     }
     catch (out_of_range &listException)
     {
       cout << listException.what() << endl;
     }  
	}
	
  system("PAUSE");
  return EXIT_SUCCESS;
}
