#include <iostream>

#include "form.h"
#include "union.h"
#include "rectangle.h"
#include "segment.h"
#include "point.h"

using namespace std;

int main()
{
    const int TAILLE = 2;

    Point tL (-1, 1);
    Point bR (1, -1);
    Rectangle * r = new Rectangle("r", tL, bR);

    Segment * s = new Segment("s", bR, tL);

    //cout << s->GetInformation() << endl;
    //cout << r->GetInformation() << endl;

    Form * test[TAILLE];
    test[0] = r;
    test[1] = s;
    for (int i = 0; i < TAILLE; i++)
    {
       // cout << test[i]->GetInformation() << endl;
    }

    Union u ("u", test, 2);
    cout << u.GetInformation() << endl;

    return 0;
}
