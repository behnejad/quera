#include <iostream>
#include <memory>
#include <optional>
#include <set>

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


int main21()
{
    shared_ptr<cop> a(new cop());
    optional<cop> b;
    set<int> p;
    cout << __cplusplus << endl
         << __cpp_lib_enable_shared_from_this << endl;
    return 0;
}
