#pragma once

#include "Message.hpp"

struct Item : public Message {
	unsigned long id_; 
	Message * msg_;
};
