/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:32:25 by sashin            #+#    #+#             */
/*   Updated: 2022/01/18 11:32:25 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "usage: ./program [filename] [src_string] [dest_string]\n";
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (filename.empty() || s1.empty() || s2.empty())
	{
		std::cerr << "Arguments are NOT empty.\n";
		return 1;
	}

	std::fstream fs;
	std::ostringstream oss;
	std::string fileStr;

	fs.open(filename.c_str());
	if (!fs.is_open())
	{
		std::cerr << "No such file in this directory: " << filename << std::endl;
		return 1;
	}
	oss << fs.rdbuf();
	fs.close();
	fileStr = oss.str();
	std::size_t findPt = fileStr.find(s1);
	while(findPt != std::string::npos)
	{
		std::string first = fileStr.substr(0, findPt);
		std::string last = fileStr.substr(findPt + s1.length());
		fileStr = first + s2 + last;
		findPt = fileStr.find(s1);
	}
	std::string replaceFilename = filename + ".replace";
	fs.open(replaceFilename.c_str(), std::fstream::out);
	fs << fileStr;
	fs.close();
	return 0;
}
