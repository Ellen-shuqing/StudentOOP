//
//  test_pointers.cpp
//  OOPsummer
//
//  Created by Shuqing Li on 5/31/19.
//  Copyright © 2019 Shuqing Li. All rights reserved.
//

#include <cassert>
#include "../my_code/pointers.h"

using namespace std;

int main() {
    int n = 0;
    inc_by_value(n);
    assert(n == 0);
    inc_with_pointer(&n);
    assert(n == 1);
    inc_with_reference(n);
    assert(n == 2);
    return 0;
}
