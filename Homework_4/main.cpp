#include <iostream>
#include "CTable.h"

using namespace std;
void i_CTable_template_test()
{
    CTable<int> c_tab_int;
    CTable<double*> c_tab_double_point;

    c_tab_int.bSetLength(10);
    c_tab_int.bSetElement(1, 22);
    int i_val = *(c_tab_int.ptGetElement(1));
    cout << "c_tab_int_point = " << *c_tab_int.ptGetElement(1) << endl;


    double d_my_doub = 5.0;
    c_tab_double_point.bSetLength(2);
    c_tab_double_point.bSetElement(1, &d_my_doub);
    double d_val = **(c_tab_double_point.ptGetElement(1));
    cout << "c_tab_double_point = " << **c_tab_double_point.ptGetElement(1) << endl;

    /*CString s_type;
    s_type = c_tab_int.sGetKnownType();
    cout << "s_type = (int)" << s_type << endl;
    s_type = c_tab_double_point.sGetKnownType();
    cout << "s_type = (double)" << s_type << endl;*/

}

int main() {
    i_CTable_template_test();
    return 0;
}
