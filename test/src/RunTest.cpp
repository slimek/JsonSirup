// JsonSirup Test - Run Test Main Entry

#include <UnitTest++/UnitTest++.h>
#include <iostream>


using namespace std;

///////////////////////////////////////////////////////////////////////////////
//
// Run Test
//

int main( int argc, char* argv[] )
{
    const int result = UnitTest::RunAllTests();
    cin.get();
    return result;
}


///////////////////////////////////////////////////////////////////////////////
