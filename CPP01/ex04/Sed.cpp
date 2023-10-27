#include "Sed.hpp"

Sed::Sed() {}

Sed::~Sed() {}

int  Sed::replace(std::string filename,std::string s1, std::string s2)
{
	std::ifstream Ofile;
	std::string line;
	std::size_t pos;

    Ofile.open(filename.c_str());
	if (!Ofile.is_open() || !Ofile.good())
	{
		std::cout << "Error! Failed to open the file." << std::endl;
		Ofile.close();
        return (1);
	}
	std::ofstream Nfile((filename + ".replace").c_str(), std::ios::trunc);
	if (!Nfile.good())
	{
		std::cout << "Error! Invalid file." << std::endl;
		Ofile.close();
		Nfile.close();
        return (1);
	}
	if (s1.length() > 0 && s2.length() > 0)
	{
		while (std::getline(Ofile, line))
		{
			pos = 0;
			while ((pos = line.find(s1, pos)) != std::string::npos)
			{
				line.erase(pos, s1.length());
				line.insert(pos, s2);
				pos = pos + s2.length();
			}
			Nfile << line << '\n';
		}
	}
	else
	{
		std::cout << "Error! String is empty." << std::endl;
		Ofile.close();
		Nfile.close();
		return (1);
	}
	Ofile.close();
	Nfile.close();
	return (0);
}