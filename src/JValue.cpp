// JsonSirup C++ JSON Library - JSON Value Implementation

#include <JsonSirup/JValue.h>

#include "JNodes.h"
#include <cassert>
#include <sstream>
#include <stdexcept>


namespace JsonSirup
{

//
// Contents
//
//   < Tokens >
//   JToken
//   JValue
//
//   < Nodes >
//   JNullNode
//   JBoolNode
//   JNumberNode
//

///////////////////////////////////////////////////////////////////////////////
//
// JSON Token
//

JToken::JToken() : m_node( std::make_shared< JNullNode >() ) {}

JToken::JToken( std::shared_ptr< JNode > node ) : m_node( node ) {}

JToken::~JToken() {}


///////////////////////////////////////////////////////////////////////////////
//
// JSON Value
//

JValue::JValue() : JToken( std::make_shared< JNullNode >() ) {}

JValue::JValue( bool value ) : JToken( std::make_shared< JBoolNode >( value )) {}

JValue::JValue( int32_t value ) : JToken( std::make_shared< JNumberNode >( value )) {}

JValue::JValue( uint32_t value ) : JToken( std::make_shared< JNumberNode >( value )) {}

JValue::JValue( double value ) : JToken( std::make_shared< JNumberNode >( value )) {}

JValue::JValue( const char* value )
{
    assert( value );
    m_node = std::make_shared< JStringNode >( value );
}

JValue::JValue( const std::string& value ) : JToken( std::make_shared< JStringNode >( value )) {}

JValue::JValue( std::string&& value ) : JToken( std::make_shared< JStringNode >( std::move( value ))) {}


//
// Copy / Move
//

JValue::JValue( const JValue& other ) : JToken( other.m_node ) {}

JValue::JValue( JValue&& other ) : JToken( std::move( other.m_node )) {}

JValue::~JValue()
{
}


//
// Properties
//

JTokenType JToken::Type() const { return m_node->Type(); }

bool JValue::IsConvertibleToString() const { return m_node->IsConvertibleToString(); }


//
// Accessors
//

std::string JValue::AsString() const
{
    return m_node->AsString();
}


///////////////////////////////////////////////////////////////////////////////
//
// JSON Null
//

//
// Accessors
//

std::string JNullNode::AsString() const
{
    throw std::logic_error( "JSON null can't be converted to string" );
}


///////////////////////////////////////////////////////////////////////////////
//
// JSON Boolean
//

//
// Accessors
//

std::string JBoolNode::AsString() const
{
    return m_value ? "true" : "false";
}


///////////////////////////////////////////////////////////////////////////////
//
// JSON Number
//

//
// Properties
//

bool JNumberNode::IsConvertibleToInt32() const
{
    return INT32_MIN <= m_value && m_value <= INT32_MAX;
}


bool JNumberNode::IsConvertibleToUint32() const
{
    return 0 <= m_value && m_value <= UINT32_MAX;
}



//
// Accessors
//

std::string JNumberNode::AsString() const
{
    std::ostringstream stream;
    stream << m_value;    
    return stream.str();
}


///////////////////////////////////////////////////////////////////////////////

} // namespace JsonSirup
