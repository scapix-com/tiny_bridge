#include <string>
#include <scapix/bridge/object.h>

namespace tiny {

class contact : public scapix::bridge::object<contact>
{
public:

    std::string name() { return "Hello from C++"; }

};

} // namespace tiny
