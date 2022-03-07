#include "mat.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;

    string ariel::mat(int rows, int colums, char ch1, char ch2) {
        if (rows < 0 || colums < 0) {
            throw std::invalid_argument("not a valid input");
        }
        if (rows * colums % 2 == 0) {
            throw std::invalid_argument("Mat size is always odd");
        }
        string ans;
        int k = 0;
        bool a = false;
        int p = 0;
        for (int i = 0; i < colums; i++) {
            char sign = ch1;
            k = i;
            if (colums % 2 == 0) {
                if (k >= colums / 2) {
                    k = colums - i - 1;
                    p = k;
                    a = true;
                }
            } else {
                if (k > colums / 2) {
                    k = colums - i - 1;
                    p = k;
                    a = true;
                }
            }
            for (int j = 0; j <= rows; j++) {
                if (j == rows) {
                    ans += "\n";
                } else {
                    if (!a && j >= rows - i && j != rows) {
                        if (sign == ch1) {
                            sign = ch2;
                        } else {
                            sign = ch1;
                        }
                        ans += sign;
                    } else {
                        if (a && j > rows - p - 1 && j != rows) {
                            if (sign == ch1) {
                                sign = ch2;
                            } else {
                                sign = ch1;
                            }
                            ans += sign;
                        } else {
                            if (k == 0) {
                                ans += sign;
                            } else {
                                ans += sign;
                                if (sign == ch1) {
                                    sign = ch2;
                                } else {
                                    sign = ch1;
                                }
                                k--;
                            }

                        }
                    }
                }
            }
        }
        return ans;
    }

