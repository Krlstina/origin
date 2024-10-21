#include "figure_creation_error.h"
#include <iomanip>
#include <string>

CreationError::CreationError(std::string setError) : error{ setError }
{}
const char* CreationError::what() const noexcept { return error.c_str(); }