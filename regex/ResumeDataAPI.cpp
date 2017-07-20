#include "ResumeDataAPI.hpp"

vector<vector<string>> resumeDataAPI() {
    vector<string> applicant1 = {
        "Matt Miller",
        "themiller@email.com",
        "123 Fake Street",
        "T7G 9H5",
        "416-867-5309" };

    vector<string> applicant2 = {
        "John Doe",
        "doeboy@isp.com",
        "124 Real Street",
        "14168629642" };

    vector<string> applicant3 = {
        "Jane Doe",
        "janedoe@conglomerate.com",
        "124 Real Street",
        "416-853-9872" };

    vector<string> applicant4 {
        "1-416-842-9524",
        "1 Yonge Street",
        "B5D 5L3",
        "dan@email.ca",
        "Dan O'Grady" };

    vector<string> applicant5 {
        "Joe-Smith Johnson",
        "workemail@isp.de",
        "4165246331",
        "1 Bloor Street East",
        "N6H 3U9" };

    vector<vector<string>> applicants;
    applicants.push_back(applicant1);
    applicants.push_back(applicant2);
    applicants.push_back(applicant3);
    applicants.push_back(applicant4);
    applicants.push_back(applicant5);

    return applicants;
}
