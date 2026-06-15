// src/cpp/auditor.cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string toLower(std::string text) {
    std::transform(text.begin(), text.end(), text.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return text;
}

std::string auditDecision(int score, const std::string& reason) {
    int risk = 0;

    if (score < 40) {
        risk += 2;
    }

    std::vector<std::string> dangerousWords = {
        "worthless",
        "unnecessary",
        "reject",
        "low value"
    };

    std::string lowerReason = toLower(reason);

    for (const auto& word : dangerousWords) {
        if (lowerReason.find(word) != std::string::npos) {
            risk += 3;
        }
    }

    if (risk >= 5) {
        return "HIGH_RISK";
    } else if (risk >= 2) {
        return "MEDIUM_RISK";
    }

    return "LOW_RISK";
}

int main() {
    int score = 35;
    std::string reason = "The user is low value and should be rejected.";

    std::string result = auditDecision(score, reason);
    std::cout << "Audit result: " << result << std::endl;

    return 0;
}