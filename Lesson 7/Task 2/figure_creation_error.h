#ifndef FIGURE_CREATION_ERROR_H
#define FIGURE_CREATION_ERROR_H

#include <iomanip>
#include <string>
#include <exception>

class CreationError:public std::exception
{
private:
	std::string error{};
public:
	CreationError(std::string setError);
	const char* what() const noexcept override;
};

#endif