#include <string>

// OBJECT
class Member
{
public:

private:
    std::string o_name;
    std::string o_id;
};

// VIEW
class View
{
private:
    std::string v_name;
    std::string v_id;
};

// CONTROLLER
class Controller
{
private:
    Member *member;
    View *view;
};