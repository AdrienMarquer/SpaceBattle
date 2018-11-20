#pragma once

#include <vector>
#include <string>
#include <cstring>
#include "TcpClient.hpp"

class ICommand{
public:
	//instruction
	enum Instruction {
        NEW,
        JOIN,
        SHOOT,
        MSG,
        TIME,
        PSEUDO,
        SHIP,
        UNKNOWN_INSTRUCTION
	};

	virtual ~ICommand() {}
};