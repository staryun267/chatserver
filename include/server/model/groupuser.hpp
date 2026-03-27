#ifndef GROUPUSER_H
#define GROUPUSER_H

#include "User.hpp"

//群组用户，对了一个role角色信息，其他信息复用User
class GroupUser : public User
{
public:
    void setRole(string role) { this->role = role; }
    string getRole() { return this->role; }
private:
    string role;
};

#endif