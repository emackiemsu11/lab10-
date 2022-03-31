#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int Censor (std::string & str, const std::string & trigger, const std::string & replace) {
    int strLen = trigger.size();
    
    int countr = 0;
    std::string lowStr = str;
    std::transform(lowStr.begin(), lowStr.end(), lowStr.begin(), ::tolower);

    std::string::size_type pattern_location = lowStr.find(trigger);

    while (pattern_location != std::string::npos) {
        lowStr.replace(pattern_location, strLen, replace);
        str.replace(pattern_location, strLen, replace);
        countr++;
        pattern_location = lowStr.find(trigger);
    }

    return countr;
}