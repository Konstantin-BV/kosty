#pragma once
class Iterator
{
public:
	virtual bool has_next() = 0;
	virtual int next() = 0;
};
