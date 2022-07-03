#include <iostream>
#include <string>
#include <fstream>
#include <cpr/cpr.h>

/*class Request {
public:
    virtual void command () const;
    virtual ~Request() {}
};

class Get : virtual public Request {
public:
    void command () const override {
        cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/get"));
        std::cout << r.text << std::endl;
    }
};

class Post : virtual public Request {
public:
    void command () const override {
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
    void command () const override {
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
    void command () const override {
        cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/delete"));
        std::cout << r.text << std::endl;
    }
};

class Patch : virtual public Request {
public:
    void command () const override {
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
        delete request;
    }
    else if (str == "Patch") {
        Request* request = new Patch();
        request->command();
        delete request;
    }
}*/

int main()
{
    std::string command;
    while (command != "exit")
    {
        std::cout << "HTTP Request Type:";
        std::cin >> command;
        std::string url = "https://httpbin.org/";
        url += command;
        cpr::Response r;
        if (command == "get") {
            r = cpr::Get(cpr::Url(url));
        } else if (command == "post") {
            r = cpr::Post(cpr::Url(url));
        } else if (command == "patch") {
            r = cpr::Patch(cpr::Url(url));
        } else if (command == "delete") {
            r = cpr::Delete(cpr::Url(url));
        }
        std::cout << r.text << std::endl;
    }
}