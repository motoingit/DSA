#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<string> toolOnes = {
        "", "One", "Two", "Three", "Four",
        "Five", "Six", "Seven", "Eight", "Nine"
    };

    vector<string> toolTeens = {
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };

    vector<string> toolTens = {
        "", "", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

    vector<string> toolSegment = {
        "", "Thousand", "Million", "Billion"
    };

    // Converts a number from 0 to 999 into words.
    string convertBelowThousand(int num) {

        string res;

        // Handle hundreds.
        if (num >= 100) {

            res += toolOnes[num / 100] + " Hundred";

            num %= 100;
        }

        // Handle teens.
        if (num >= 10 && num <= 19) {

            if (!res.empty()) res += " ";

            res += toolTeens[num - 10];
        }

        else {

            // Handle tens.
            if (num >= 20) {

                if (!res.empty()) res += " ";

                res += toolTens[num / 10];

                num %= 10;
            }

            // Handle ones.
            if (num > 0) {

                if (!res.empty()) res += " ";

                res += toolOnes[num];
            }
        }

        return res;
    }

public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        vector<string> groups;

        int segmentFactor = 0;

        while (num > 0) {

            // Extract the last three digits.
            int chunk = num % 1000;

            if (chunk != 0) {

                string part = convertBelowThousand(chunk);

                // Add Thousand, Million or Billion.
                if (segmentFactor > 0) {

                    part += " " + toolSegment[segmentFactor];
                }

                groups.push_back(part);
            }

            // Remove the last three digits.
            num /= 1000;

            segmentFactor++;
        }

        // Reverse the groups into normal order.
        reverse(groups.begin(), groups.end());

        string res;

        for (int i = 0; i < groups.size(); i++) {

            if (!res.empty()) res += " ";

            res += groups[i];
        }

        return res;
    }
};

