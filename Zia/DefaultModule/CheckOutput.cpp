#include "CheckOutput.h"

bool	zia::module::CheckOutput::checkStatusCode(const zia::api::DataTree& tree, zia::module::CheckOutput::StatusCode code = zia::module::CheckOutput::ALL)
{
	if (tree["Status-Line"].has("Status-Code"))
	{
		std::cout << "Status-Line Existant !!!" << std::endl;
		return true;
	}
	return false;
}