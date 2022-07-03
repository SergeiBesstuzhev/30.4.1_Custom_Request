#include <iostream>
#include <string>
#include <cpr/cpr.h>

class Request {
public:
    virtual void command () const;
    virtual ~Request() {}
};

class Get : virtual public Request {
public:
    void command () const {
        cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/get"));
        std::cout << r.text << std::endl;
    }
};

class Post : virtual public Request {
public:
    void command () const {
        std::cout << "Enter name and city: ";
        std::string name, city;
        std::cin >> name >> city;
        cpr::Response r = cpr::Post(cpr::Url("http://httpbin.org/post"),
                                    cpr::Payload{{"name", name.c_str()}, {"city", city.c_str()}});
        std::cout << r.text << std::endl;
    }
};

class Put : virtual public Request {
public:
    void command () const {
        std::cout << "Enter name and city: ";
        std::string name, city;
        std::cin >> name >> city;
        cpr::Response r = cpr::Put(cpr::Url("http://httpbin.org/put"),
                                   cpr::Payload{{"name", name.c_str()}, {"city", city.c_str()}});
        std::cout << r.text << std::endl;
    }
};

class Delete : virtual public Request {
public:
    void command () const {
        cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/delete"));
        std::cout << r.text << std::endl;
    }
};

class Patch : virtual public Request {
public:
    void command () const {
        cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/patch"));
        std::cout << r.text << std::endl;
    }
};

void act (std::string str) {
    if (str == "Get") {
        Request* request = new Get();
        request->command();
    }
    else if (str == "Post") {
        Request* request = new Post();
        request->command();
    }
    else if (str == "Put") {
        Request* request = new Put();
        request->command();
    }
    else if (str == "Delete") {
        Request* request = new Delete();
        request->command();
    }
    else if (str == "Patch") {
        Request* request = new Request();
        request->command();
    }
}

int main() {
    std::string command;

    while (command != "exit") {
        std::cin >> command;
        act(command);
    }
}