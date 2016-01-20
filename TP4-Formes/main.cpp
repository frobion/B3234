#include <iostream>
#include <vector>

#include "CommandLineInterface.h"
#include "convexpolygone.h"
#include "point.h"

using namespace std;

int main()
{
    CommandLineInterface cli;
    return cli.waitForCommand();
}
