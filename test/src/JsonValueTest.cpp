// JsonSirup Test - JValue Test

#include <JsonSirup/JValue.h>
#include <UnitTest++/UnitTest++.h>
#include <cstdint>


using namespace JsonSirup;

SUITE( JsonValueSuite )
{

TEST( JsonScalarValueTypeTest )
{
    JValue jnull;
    CHECK( JTOKEN_NULL == jnull.Type() );

    JValue jtrue( true );
    CHECK( JTOKEN_BOOL == jtrue.Type() );


    /// Integers ///

    JValue jzero( 0 );
    CHECK( JTOKEN_NUMBER == jzero.Type() );

    JValue jintMin( INT32_MIN );
    CHECK( JTOKEN_NUMBER == jintMin.Type() );

    JValue juintMax( UINT32_MAX );
    CHECK( JTOKEN_NUMBER == juintMax.Type() );

    JValue ji16( static_cast< int16_t >( 42 ));
    CHECK( JTOKEN_NUMBER == ji16.Type() );

    JValue ju16( static_cast< uint16_t >( 42 ));
    CHECK( JTOKEN_NUMBER == ju16.Type() );

    // REMARKS:
    //   int64 / uint64 can't be converted to double implicitly.
    //
    // JValue ji64( static_cast< int64_t >( 42 ));
    // JValue ju64( static_cast< uint64_t >( 42 ));


    /// Floatings ///

    JValue jfloat( 3.1416f );
    CHECK( JTOKEN_NUMBER == jfloat.Type() );

    JValue jdouble( 6.022e23 );
    CHECK( JTOKEN_NUMBER == jdouble.Type() );


    /// Strings ///

    JValue jhello( "Hello" );
    CHECK( JTOKEN_STRING == jhello.Type() );

    const char* world = "World";
    JValue jworld( world );
    CHECK( JTOKEN_STRING == jworld.Type() );

    const std::string alice = "Alice";
    JValue jalice( alice );
    CHECK( JTOKEN_STRING == jalice.Type() );

    JValue jrabbit( std::string( "Rabbit" ));  // move construction
    CHECK( JTOKEN_STRING == jrabbit.Type() );
}


TEST( JsonValueCopyMoveTest )
{
    JValue jalice( "Alice" );

    JValue jcopy( jalice );
    CHECK( JTOKEN_STRING == jcopy.Type() );
    CHECK( "Alice" == jcopy.AsString() );

    JValue jmove( std::move( jalice ));
    CHECK( JTOKEN_STRING == jmove.Type() );
    CHECK( "Alice" == jmove.AsString() );

    // Then jalice becomes an invalid object. Don't use it again!

}


TEST( JsonValueAsStringTest )
{
    /// Null - Can't be string ///

    JValue jnull;

    CHECK_THROW( jnull.AsString(), std::logic_error );


    /// Boolean ///

    JValue jtrue( true );
    JValue jfalse( false );

    CHECK( "true"  == jtrue.AsString() );
    CHECK( "false" == jfalse.AsString() );


    /// Number - Integers ///

    JValue jzero( 0 );
    JValue jneg1( -1 );
    JValue jansw( 42 );

    CHECK( "0" == jzero.AsString() );
    CHECK( "-1" == jneg1.AsString() );
    CHECK( "42" == jansw.AsString() );


    /// Number - Floatings ///

    JValue jpi( 3.14 );
    JValue jmolar( 6.022e23 );

    const auto s = jmolar.AsString();

    CHECK( "3.14" == jpi.AsString() );
    CHECK( "6.022e+023" == jmolar.AsString() );


    /// Strings ///

    JValue jempty( "" );
    JValue jalice( "Alice" );

    CHECK( "" == jempty.AsString() );
    CHECK( "Alice" == jalice.AsString() );
}


TEST( JsonObjectTest )
{
    
}


} // SUITE( JsonValueSuite )
