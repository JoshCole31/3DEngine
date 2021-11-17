#pragma once
#include <string>
namespace jc 
{
	class Resource
	{
	public:
		virtual bool Load(const std::string& filename,void* data =nullptr) = 0;
	};
}