#ifndef CREATUREEXCEPTION_H
#define CREATUREEXCEPTION_H

using namespace std;

class CreatureException
{
private:
	string msg;
public:
	explicit CreatureException(const string& n_msg = UNKNOWN_ERR) : msg(n_msg) {}
	string what() const { return msg; }
};

#endif