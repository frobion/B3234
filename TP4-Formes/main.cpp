#include <iostream>

#include "CommandLineInterface.h"

using namespace std;

int main()
{
    CommandLineInterface cli;
    return cli.waitForCommand();
}
