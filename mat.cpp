#include "mat.hpp"
#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;

    string ariel::mat(int colums, int rows, char ch1, char ch2)  {

        if(rows<0 || colums<0){
            throw std::invalid_argument("not a valid input");
        }
        if(rows*colums%2==0){
            throw std::invalid_argument ("Mat size is always odd");
        }
        string ans;
        int k =0 ;
        bool a = false;
        int p =0;
        for(int i=0; i<rows; i++) {
            char sign = ch1;
            k = i;
            if (rows % 2 == 0) {
                if (k >= rows / 2) {
                    k = rows - i - 1;
                    p = k;
                    a = true;
                }
            } else {
                if (k > rows / 2) {
                    k = rows - i - 1;
                    p = k;
                    a = true;
                }
            }
            for (int j = 0; j <= colums; j++) {
                if (i < rows - colums / 2 && i > colums / 2 && j != colums) {
                    ans += sign;
                    if (sign == ch1) {
                        sign = ch2;
                    } else {
                        sign = ch1;
                    }
                } else {
                    if (j == colums) {
                        ans += "\n";
                    } else {
                        if (!a && j >= colums - i && j != colums) {
                            if (sign == ch1) {
                                sign = ch2;
                            } else {
                                sign = ch1;
                            }
                            ans += sign;
                        } else {
                            if (a && j > colums - p - 1 && j != colums) {
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
        }
        return ans;
    }




