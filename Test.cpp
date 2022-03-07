#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

string nospaces(string input) {
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}


TEST_CASE("Good input") {
            CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n@-------@\n@-@@@@@-@\n@-@---@-@\n@-@@@@@-@\n@-------@\n@@@@@@@@@"));
            CHECK(nospaces(mat(1,1,'#','#'))==nospaces("#\n"));
            CHECK(nospaces(mat(3,3,'#','#'))==nospaces("#########\n"));
            CHECK(nospaces(mat(1,3,'#','#'))==nospaces("###\n"));
            CHECK(nospaces(mat(3,1,'#','#'))==nospaces("###\n"));
    }
    TEST_CASE("negative input") {
    CHECK_THROWS(mat(10, -1, '$', '%'));
    CHECK_THROWS(mat(-1, -1, '$', '%'));
    CHECK_THROWS(mat(-12, -1, '$', '%'));
    CHECK_THROWS(mat(-1, -12, '$', '%'));
    CHECK_THROWS(mat(-12, -12, '$', '%'));

        }

    TEST_CASE("even input") {
    CHECK_THROWS(mat(10, 's', '$', '%'));
    CHECK_THROWS(mat(3, 4, '$', '%'));
    CHECK_THROWS(mat(0, 4, '$', '%'));
    CHECK_THROWS(mat(1, 0, '$', '%'));
    CHECK_THROWS(mat(1, 0, '$', '%'));
    CHECK_THROWS(mat(0, 0, '$', '%'));
    CHECK_THROWS(mat(3, 2, '$', '%'));
    CHECK_THROWS(mat(10, 1, '$', '%'));
    CHECK_THROWS(mat(10, 1, '$', '%'));
    CHECK_THROWS(mat(2, 2, '$', '%'));

}