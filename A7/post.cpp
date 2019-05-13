#include "post.h"

using namespace std;

Post::Post() {
    functionMap[SIGNUP] =
        [this](Args args){ signup(args); };
    functionMap[LOGIN] = 
        [this](Args args){ login(args); };
    functionMap[FILMS] =
        [this](Args args){ newFilm(args); };
    functionMap[MONEY] =
        [this](Args args){ doMoneyCommand(args); };
}

void Post::parseInput(StructedInput& StructedInput) {
    if (functionMap.find(StructedInput.command) != functionMap.end())
        functionMap[StructedInput.command](StructedInput.args);
    else 
        throw NotFound();
}

void Post::signup(Args& args) {
    SignupArgs signupArgs = getSignupArgs(args);
    // network->signup() ;
}

void Post::login(Args& args) {
    LoginArgs loginArgs = getLoginArgs(args);
    // network->login();
}

void Post::newFilm(Args& args) {
    NewFilmArgs newFilmArgs = getNewFilmArgs(args);
    // network->newFilm();
}

void Post::doMoneyCommand(Args& args) {
    if (args.size() == 0)
        ; // network->recieveMoney();
    else {
        if (args.find(AMOUNT) == args.end())
            throw BadRequest();
        if (isNumber(args[AMOUNT])) 
            ;// network->addMoney(stoi(args[AMOUNT]));
        else
            throw BadRequest();
    }
}

SignupArgs Post::getSignupArgs(Args& args) {
    SignupArgs signupArgs;
    try {
        signupArgs.username = args.at(USERNAME);
        signupArgs.password = hashString(args.at(PASSWORD));
        isEmailValid(args.at(EMAIL)) ? 
            signupArgs.email = args.at(EMAIL) : throw BadRequest();
        // signupArgs.email = args.at(EMAIL);
        isNumber(args.at(AGE)) ?
            signupArgs.age = stoi(args.at(AGE)) : throw BadRequest();
        // signupArgs.age = stoi(args.at(AGE));
        if (args.find(PUBLISHER) != args.end())
            if (args.at(PUBLISHER) == TRUE || args.at(PUBLISHER) == FALSE)
                signupArgs.publisher = args.at(PUBLISHER);
            else 
                throw BadRequest();
        else 
            signupArgs.publisher = FALSE;
    }
    catch (exception& e) {
        throw BadRequest();
    }
    return signupArgs;
}

std::string Post::hashString(const std::string& str) {
    const int prime = 1027;
    const int mod = 1e9 + 9;
    long long hashedStr = 0;
    long long primePow = 1;
    for (char c : str) {
        hashedStr = (hashedStr + (c - 'a' + 1) * primePow) % mod;
        primePow = (primePow * prime) % mod;
    }
    return to_string(hashedStr);
}

bool Post::isEmailValid(const std::string email) {
   const std::regex pattern
      ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
   return std::regex_match(email, pattern);
}

LoginArgs Post::getLoginArgs(Args& args) {
    LoginArgs loginArgs;
    try {
        loginArgs.username = args.at(USERNAME);
        loginArgs.password = hashString(args.at(PASSWORD));
    }
    catch (exception& e) {
        throw BadRequest();
    }
    return loginArgs;
}

NewFilmArgs Post::getNewFilmArgs(Args& args) {
    NewFilmArgs newFilmArgs;
    try {
        newFilmArgs.summary = args.at(SUMMARY);
        newFilmArgs.director = args.at(DIRECTOR);
        newFilmArgs.name = args.at(NAME);
        isNumber(args.at(PRICE)) ?
            newFilmArgs.price = stoi(args.at(PRICE)) : throw BadRequest() ;
        isNumber(args.at(YEAR)) ?
            newFilmArgs.year = stoi(args.at(YEAR)) : throw BadRequest() ;
        isNumber(args.at(LENGTH)) ?
            newFilmArgs.length = stoi(args.at(LENGTH)) : throw BadRequest() ;
    }
    catch (exception& e) {
        throw BadRequest() ;
    }
    return newFilmArgs;
}