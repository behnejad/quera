#include <iostream>
#include <memory>
#include <optional>


using namespace std;

class cop
{
public:
    cop()
    {
        cout << "cop ctor" << endl;
    }

    virtual ~cop()
    {
        cout << "cop dtor" << endl;
    }
};


int main1()
{
    shared_ptr<cop> a(new cop());
    optional<cop> b;
    cout << __cplusplus << endl
         << __cpp_lib_enable_shared_from_this << endl;
    return 0;
}
