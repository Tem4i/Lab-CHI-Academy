#pragma once
#include<string>
#include<vector>

namespace l1 {

	class Txt
	{
	private:
		std::vector<std::string>data;
		
	public:
		Txt();
		Txt(char*);
		Txt(const Txt& other);
		Txt(Txt&& other)noexcept;
		Txt& operator = (const Txt& other);
		Txt& operator = (Txt&& other)noexcept;
		~Txt();
		size_t size() const;
	};

	
	class FileLoader
	{
	public:
		static void load(char*fileName, std::vector<std::string>&);
	};
}