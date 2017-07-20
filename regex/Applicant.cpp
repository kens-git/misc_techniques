#include "Applicant.hpp"

#include <iostream>

using std::cout;
using std::endl;

void Applicant::print() {
    if (mName != "") {
        cout << mName << endl;
    }
    if (mEmail != "") {
        cout << mEmail << endl;
    }
    if (mPhone != "") {
        cout << mPhone << endl;
    }
    if (mAddress != "") {
        cout << mAddress << endl;
    }
    if (mPostalCode != "") {
        cout << mPostalCode << endl;
    }
}
