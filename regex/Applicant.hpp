#pragma once

#include <string>

using std::string;

class Applicant {
    public:
        void setName(string name) { mName = name; }
        void setEmail(string email) { mEmail = email; }
        void setPhone(string phone) { mPhone = phone; }
        void setAddress(string address) { mAddress = address; }
        void setPostalCode(string postalCode) { mPostalCode = postalCode; }

        void print();

    private:
        string mName;
        string mEmail;
        string mPhone;
        string mAddress;
        string mPostalCode;
};
