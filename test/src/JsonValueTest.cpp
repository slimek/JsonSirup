// JsonSirup Test - JsonValue Test

#include <JsonSirup/JsonValue.h>
#include <UnitTest++/UnitTest++.h>
#include <cstdint>


using namespace JsonSirup;

SUITE( JsonValueSuite )
{

TEST( JsonScalarValueTypeTest )
{
    JsonValue jnull;
    CHECK( VALUE_NULL == jnull.Type() );

    JsonValue jtrue( true );
    CHECK( VALUE_BOOLEAN == jtrue.Type() );


    /// Integers ///

    JsonValue jzero( 0 );
    CHECK( VALUE_NUMBER == jzero.Type() );

    JsonValue jintMin( INT32_MIN );
    CHECK( VALUE_NUMBER == jintMin.Type() );

    JsonValue juintMax( UINT32_MAX );
    CHECK( VALUE_NUMBER == juintMax.Type() );

    JsonValue ji16( static_cast< int16_t >( 42 ));
    CHECK( VALUE_NUMBER == ji16.Type() );

    JsonValue ju16( static_cast< uint16_t >( 42 ));
    CHECK( VALUE_NUMBER == ju16.Type() );

    // REMARKS:
    //   int64 / uint64 can't be converted to double implicitly.
    //
    // JsonValue ji64( static_cast< int64_t >( 42 ));
    // JsonValue ju64( static_cast< uint64_t >( 42 ));


    /// Floatings ///

    JsonValue jfloat( 3.1416f );
    CHECK( VALUE_NUMBER == jfloat.Type() );

    JsonValue jdouble( 6.022e23 );
    CHECK( VALUE_NUMBER == jdouble.Type() );


    /// Strings ///

    JsonValue jhello( "Hello" );
    CHECK( VALUE_STRING == jhello.Type() );

    const char* world = "World";
    JsonValue jworld( world );
    CHECK( VALUE_STRING == jworld.Type() );

    const std::string alice = "Alice";
    JsonValue jalice( alice );
    CHECK( VALUE_STRING == jalice.Type() );

    JsonValue jrabbit( std::string( "Rabbit" ));  // move construction
    CHECK( VALUE_STRING == jrabbit.Type() );
}


TEST( JsonValueCopyMoveTest )
{
    JsonValue jalice( "Alice" );

    JsonValue jcopy( jalice );
    CHECK( VALUE_STRING == jcopy.Type() );
    CHECK( "Alice" == jcopy.AsString() );

    JsonValue jmove( std::move( jalice ));
    CHECK( VALUE_STRING == jmove.Type() );
    CHECK( "Alice" == jmove.AsString() );

    // Then jalice becomes an invalid object. Don't use it again!

}


} // SUITE( JsonValueSuite )
