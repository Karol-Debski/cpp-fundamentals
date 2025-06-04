#include "validation.hpp"
#include <algorithm>
#include <chrono>

std::string getErrorMessage(const ErrorCode code) {
    switch (code) {
    case ErrorCode::Ok:
        return "Ok";
    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        return "Password needs to have at least nine characters";
    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        return "Password needs to have at least one number";
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        return "Password needs to have at least one special character";
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        return "Password needs to have at least one uppercase letter";
    case ErrorCode::PasswordsDoNotMatch:
        return "Passwords do not match";
    default:
        return "";
        break;
    }
}

bool doPasswordsMatch(const std::string& password1, const std::string& password2) {
    return (password1 == password2) ? true : false;
}

ErrorCode checkPasswordRules(const std::string& password) {
    if (password.length() < 9) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }

    bool isNoDigit = std::none_of(password.begin(), password.end(), [](unsigned char c) { return std::isdigit(c); });

    if (isNoDigit) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }

    bool isNoSpecialChars = std::none_of(password.begin(), password.end(), [](unsigned char c) { return !std::isalnum(c); });

    if (isNoSpecialChars) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }

    bool isNoUpperCaseLetters = std::none_of(password.begin(), password.end(), [](unsigned char c) { return std::isupper(c); });

    if (isNoUpperCaseLetters) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }

    return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string& password1, const std::string& password2) {
    bool isMatch = doPasswordsMatch(password1, password2);

    if (isMatch == false) {
        return ErrorCode::PasswordsDoNotMatch;
    }
    return checkPasswordRules(password1);
}