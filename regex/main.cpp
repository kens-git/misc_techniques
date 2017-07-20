#include <iostream>
#include <fstream>
#include <regex>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::regex;
using std::regex_match;

#include "Applicant.hpp"
#include "ResumeDataAPI.hpp"

void printApplicantData(vector<vector<string>> applicants);
void printSortedData(vector<Applicant> applicants);
vector<Applicant> sortApplicantData(vector<vector<string>> applicants);

int main() {
    vector<vector<string>> applicantData = resumeDataAPI();

    printApplicantData(applicantData);

    printSortedData(sortApplicantData(applicantData));

    return 0;
}

void printApplicantData(vector<vector<string>> applicants) {
    for (vector<string> vecStr : applicants) {
        for (string str : vecStr) {
            cout << str << endl;
        }
        cout << endl;
    }

    cout << "//////////////////////////////////////////////////////////////////////////" << endl << endl;
}

void printSortedData(vector<Applicant> applicants) {
    for (Applicant app : applicants) {
        app.print();
        cout << endl;
    }
}

vector<Applicant> sortApplicantData(vector<vector<string>> applicants) {
    // We're not checking for correctness, just that the data matches a regex (or fails, if not)

    // GCC (4.9.2) doesn't seem to like \s, so the space is literally a space
    regex nameRegex(R"([a-zA-Z \'\-]+)");
    regex emailRegex(R"(^.+@\w+.[a-zA-Z]+$)");
    regex phoneRegex(R"(^[\d|-]+$)");
    regex addressRegex(R"(^[\d]+[\w \-#']+$)");
    regex postalRegex(R"(^[a-zA-Z]\d[a-zA-Z] ?\d[a-zA-z]\d$)");

    vector<Applicant> sortedApplicants;

    for (vector<string> applicant : applicants) {
        Applicant applicantData;
        while (applicant.size()) {
            string data = applicant.back();
            if (regex_match(data, nameRegex)) {
                //cout << "Matched name: " << data << endl;
                applicantData.setName(data);
            }
            else if (regex_match(data, emailRegex)) {
                //cout << "Matched email: " << data << endl;
                applicantData.setEmail(data);
            }
            else if (regex_match(data, phoneRegex)) {
                //cout << "Matched phone: " << data << endl;
                applicantData.setPhone(data);
            }
            else if (regex_match(data, addressRegex)) {
                //cout << "Matched address: " << data << endl;
                applicantData.setAddress(data);
            }
            else if (regex_match(data, postalRegex)) {
                //cout << "Matched postal: " << data << endl;
                applicantData.setPostalCode(data);
            }
            else {
                cout << "Could not match: " << data << endl;
            }
            applicant.pop_back();
        }
        sortedApplicants.push_back(applicantData);
    }

    return sortedApplicants;
}
