#include <iostream>
#include "interval_map.h"

using namespace std;

template<typename K, typename V>
void show(interval_map<K, V>& mp) {
    cout << "\n";
    typename map<K, V>::iterator it = mp.m_map.begin();
    for (int i = 1; it != mp.m_map.end(); it++, i++) {
        cout << i << "]. " << it->first.getVal() << " = " << (int)it->second.getVal() << endl;
    }
}


int main()
{
    //MyKey k1(2);
    //MyKey k2 = k1;
    //k1 = 3;
    //bool res = k1 < k2;

    MyVal v1(2);
    MyVal v2 = v1;
    v1 = 3;
    bool res = v1 == v2;

    interval_map<MyKey, MyVal> imap(1);

    imap.assign(MyKey(5), MyKey(10), 2);
    show(imap);
    imap.assign(6, 7, 2);
    show(imap);

    imap.assign(1, 4, 3);
    show(imap);
    imap.assign(3, 7, 4);
    show(imap);

    //cout << "-------------------------------" << endl;

    //interval_map<int, char> imap2(1);
    //imap2.assign(5, 10, 2);
    //show(imap2);
    //imap2.assign(6, 7, 2);
    //show(imap2);

    //imap2.assign(1, 5, 3);
    //show(imap2);
    //imap2.assign(3, 7, 4);
    //show(imap2);
}
