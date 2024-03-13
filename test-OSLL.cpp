#include "OSLL.h"

#include <stdlib.h>
#include <iostream>
using namespace std;

static const int NUMS_PER_LINE = 14;


int main( )
{
    const int N = 10;
    // int * a = new int[10];
    OSLL<int> lst;
    
    cout << "testing display(), isEmpty(), get_Size(), insert(), remove(), \n";
    lst.display();
    cout << endl;
    
    cout << "Is the Linked List empty: " << ((lst.isEmpty()) ? "yes": "no") << "\n";

    cout << "this is the size: " << lst.get_size() << endl;
    cout << "adding 15 items\n";
    for( int i = 0 ; i < 15 ; i++)
    {
        lst.insert(21-i);
        // a[ i ] = j ;
    }
    lst.display();
    cout << "\n" ;
    cout << "this is the size: " << lst.get_size() << endl;
    cout << "Is the Linked List empty: " << ((lst.isEmpty()) ? "yes": "no") << "\n";

    cout << endl;
    cout << "removing 4 and 14\n";
    cout << "removing 4: " <<  ((lst.remove(4)) ? "yes": "no") << "\n";
    cout << "removing 14: " <<  ((lst.remove(14)) ? "yes": "no") << "\n";
    lst.display();
    cout << "\n";

    cout << endl;
    cout << "inserting 5 and 15\n";
    cout << "inserting 5: " <<  ((lst.insert(5)) ? "yes": "no") << "\n";
    cout << "insertiing 15: " <<  ((lst.insert(15)) ? "yes": "no") << "\n";
    lst.display();
    cout << "\n" ;

    cout << endl;
    cout << "removing 8 and 18\n";
    cout << "removing 8: " <<  ((lst.remove(8)) ? "yes": "no") << "\n";
    cout << "removing 18: " <<  ((lst.remove(18)) ? "yes": "no") << "\n";
    lst.display();
    cout << "\n" ;

    cout << endl;
    cout << "inserting 2 and 25\n";
    cout << "inserting 2: " <<  ((lst.insert(2)) ? "yes": "no") << "\n";
    cout << "inserting 25: " <<  ((lst.insert(25)) ? "yes": "no") << "\n";
    lst.display();
    cout << "\n" ;

    cout << endl;
    cout << "testing find()\n";
    cout << "finding 1: " <<  ((lst.find(1)) ? "yes": "no") << "\n" ;
    cout << "finding 2: " <<  ((lst.find(2)) ? "yes": "no") << "\n" ;
    cout << "finding 4: " <<  ((lst.find(4)) ? "yes": "no") << "\n" ;
    cout << "finding 5: " <<  ((lst.find(5)) ? "yes": "no") << "\n" ;
    cout << "finding 8: " <<  ((lst.find(8)) ? "yes": "no") << "\n" ;
    cout << "finding 11: " <<  ((lst.find(11)) ? "yes": "no") << "\n" ;
    cout << "finding 14: " <<  ((lst.find(14)) ? "yes": "no") << "\n" ;
    cout << "finding 15: " <<  ((lst.find(15)) ? "yes": "no") << "\n" ;
    cout << "finding 18: " <<  ((lst.find(18)) ? "yes": "no") << "\n" ;
    cout << "finding 25: " <<  ((lst.find(25)) ? "yes": "no") << "\n" ;
    cout << "finding 28: " <<  ((lst.find(28)) ? "yes": "no") << "\n" ;

    cout << endl;
    cout << "testing getMax(), and getMin()\n";
    cout << " max: " << lst.getMax(); 
    cout << "\n" ;
    cout << " min: " << lst.getMin(); 
    cout << "\n" ;

    cout << endl;
    cout << "making and deleting the list\n" ; 
    OSLL<int> * lst2 = new OSLL<int> ;
    lst2->insert(2);
    lst2->insert(25);
    lst2->display();
    delete lst2 ; 
    cout << "\n" ;

    cout << endl;
    cout << "making a character list\n" ; 
    OSLL<char> * lst3 = new OSLL<char> ;
    lst3->insert('c');
    lst3->insert('a');
    lst3->insert('d');
    lst3->insert('b');
    lst3->display();
    delete lst3 ; 
    cout << "\n" ;
    cout << "\n" ;
    cout << "done\n";

    return 0;
}
