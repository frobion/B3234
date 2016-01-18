#include <iostream>

#include "form.h"
#include "union.h"
#include "rectangle.h"
#include "segment.h"
#include "point.h"
#include "test.h"

using namespace std;

int main()
{
    cout << "TestConvexPolygoneIsConstructionPossible" << endl << endl;
    Test::TestConvexPolygoneIsConstructionPossible();

    cout << endl << "TestConstructeurUnion" << endl << endl;
    Test::TestConstructeurUnion();

    cout << endl << "TestConstructeur" << endl << endl;
    Test::TestConstructeur();

    cout << "fin" << endl;
    return 0;
}
