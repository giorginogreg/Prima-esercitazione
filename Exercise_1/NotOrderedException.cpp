#include <exception>
using namespace std;

class NotOrderedException : public exception
{
private:
public:
    NotOrderedException(/* args */);
    ~NotOrderedException();
    virtual const char *what() const throw()
    {
        return "My exception happened";
    }
};

NotOrderedException::NotOrderedException(/* args */)
{
}

NotOrderedException::~NotOrderedException()
{
}
