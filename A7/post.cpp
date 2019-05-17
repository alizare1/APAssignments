#include "post.h"

using namespace std;

Post::Post(Network* _network)
    :Request(_network) {
    functionMap[SIGNUP] =
        [this](Args args){ signup(args); };
    functionMap[LOGIN] = 
        [this](Args args){ login(args); };
    functionMap[FILMS] =
        [this](Args args){ newFilm(args); };
    functionMap[MONEY] =
        [this](Args args){ doMoneyCommand(args); };
    functionMap[RELPIES] =
        [this](Args args){ replyToComment(args); };
    functionMap[FOLLOWERS] = 
        [this](Args args){ followUser(args); };
    functionMap[BUY] =
        [this](Args args){ buyFilm(args); };
    functionMap[RATE] =
        [this](Args args){ rateFilm(args); };
    functionMap[COMMENTS] =
        [this](Args args){ commentOnFilm(args); };
}

void Post::signup(Args& args) {
    SignupArgs signupArgs = getSignupArgs(args);
    network->signup(signupArgs) ;
}

void Post::login(Args& args) {
    LoginArgs loginArgs = getLoginArgs(args);
    network->login(loginArgs);
}

void Post::newFilm(Args& args) {
    NewFilmArgs newFilmArgs = getNewFilmArgs(args);
    network->addNewFilm(newFilmArgs);
}

void Post::doMoneyCommand(Args& args) {
    if (args.size() == 0)
        network->withdrawMoney();
    else {
        if(!mapHasKey(args, AMOUNT))
            throw BadRequest();
        if (isNumber(args[AMOUNT])) 
            network->addMoney(stoi(args[AMOUNT]));
        else
            throw BadRequest();
    }
}

void Post::replyToComment(Args& args) {
    ReplyArgs replyArgs = getReplyArgs(args);
    network->replyToComment(replyArgs);
}

void Post::followUser(Args& args) {
    if (!mapHasKey(args, USER_ID))
        throw BadRequest();
    isNumber(args[USER_ID]) ? network->follow(stoi(args[USER_ID])) : throw BadRequest();
}

void Post::buyFilm(Args& args) {
    if (!mapHasKey(args, FILM_ID))
        throw BadRequest();
    isNumber(args[FILM_ID]) ? network->buyFilm(stoi(args[FILM_ID])) : throw BadRequest();
}

void Post::rateFilm(Args& args) {
    RateArgs rateArgs = getRateArgs(args);
    network->rateFilm(rateArgs) ;
}

void Post::commentOnFilm(Args& args) {
    CommentArgs commentArgs = getCommentArgs(args);
    network->commentOnFilm(commentArgs) ;
}

SignupArgs Post::getSignupArgs(Args& args) {
    SignupArgs signupArgs;
    try {
        signupArgs.username = args.at(USERNAME);
        signupArgs.password = hashString(args.at(PASSWORD));
        isEmailValid(args.at(EMAIL)) ? 
            signupArgs.email = args.at(EMAIL) : throw BadRequest();
        isNumber(args.at(AGE)) ?
            signupArgs.age = stoi(args.at(AGE)) : throw BadRequest();
        if (mapHasKey(args, PUBLISHER)) {
            if (args.at(PUBLISHER) == TRUE)
                signupArgs.publisher = true;
            else if(args.at(PUBLISHER) == FALSE)
                signupArgs.publisher = false;
            else 
                throw BadRequest();
        }
        else 
            signupArgs.publisher = false;
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

ReplyArgs Post::getReplyArgs(Args& args) {
    ReplyArgs replyArgs;
    try {
        replyArgs.content = args.at(CONTENT);
        isNumber(args.at(FILM_ID)) ?
            replyArgs.filmId = stoi(args.at(FILM_ID)) : throw BadRequest();
        isNumber(args.at(COMMENT_ID)) ?
            replyArgs.commentId = stoi(args.at(COMMENT_ID)) : throw BadRequest(); 
    }
    catch (exception& e) {
        throw BadRequest();
    }
    return replyArgs;
}

RateArgs Post::getRateArgs(Args& args) {
    RateArgs rateArgs;
    try {
        isNumber(args.at(SCORE)) ?
            rateArgs.score = stoi(args.at(SCORE)) : throw BadRequest();
        isNumber(args.at(FILM_ID)) ?
            rateArgs.filmId = stoi(args.at(FILM_ID)) : throw BadRequest();
    }
    catch(exception &e) {
        throw BadRequest();
    }
    return rateArgs;
}

CommentArgs Post::getCommentArgs(Args& args) {
    CommentArgs commentArgs;
    try {
        commentArgs.content = args.at(CONTENT);
        isNumber(args.at(FILM_ID)) ?
            commentArgs.filmId = stoi(args.at(FILM_ID)) : throw BadRequest();
    }
    catch (exception& e) {
        throw BadRequest();
    }
    return commentArgs;
}