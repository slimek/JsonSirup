// JsonSirup C++ JSON Library - JSON Value Implementation

#include <JsonSirup/JsonValue.h>

#include "JsonNodes.h"
#include <cassert>
#include <sstream>
#include <stdexcept>


namespace JsonSirup
{

//
// Contents
//
//   < Values >
//   JsonValue
//
//   < Nodes >
//   JsonNull
//   JsonBoolean
//   JsonNumber
//

///////////////////////////////////////////////////////////////////////////////
//
// JSON Value
//

JsonValue::JsonValue() : m_node( new JsonNull ) {}

JsonValue::JsonValue( bool value ) : m_node( new JsonBoolean( value )) {}

JsonValue::JsonValue( int32_t value ) : m_node( new JsonNumber( value )) {}

JsonValue::JsonValue( uint32_t value ) : m_node( new JsonNumber( value )) {}

JsonValue::JsonValue( double value ) : m_node( new JsonNumber( value )) {}

JsonValue::JsonValue( const char* value )
{
    assert( value );
    m_node = std::make_shared< JsonString >( value );
}

JsonValue::JsonValue( const std::string& value ) : m_node( new JsonString( value )) {}

JsonValue::JsonValue( std::string&& value ) : m_node( new JsonString( value )) {}


//
// Copy / Move
//

JsonValue::JsonValue( const JsonValue& other ) : m_node( other.m_node ) {}

JsonValue::JsonValue( JsonValue&& other ) : m_node( std::move( other.m_node )) {}

JsonValue::~JsonValue()
{
}


//
// Properties
//

ValueType JsonValue::Type() const { return m_node->Type(); }

bool JsonValue::IsConvertibleToString() const { return m_node->IsConvertibleToString(); }


//
// Accessors
//

std::string JsonValue::AsString() const
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

std::string JsonNull::AsString() const
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

std::string JsonBoolean::AsString() const
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

bool JsonNumber::IsConvertibleToInt32() const
{
    return INT32_MIN <= m_value && m_value <= INT32_MAX;
}


bool JsonNumber::IsConvertibleToUint32() const
{
    return 0 <= m_value && m_value <= UINT32_MAX;
}



//
// Accessors
//

std::string JsonNumber::AsString() const
{
    std::ostringstream stream;
    stream << m_value;    
    return stream.str();
}


///////////////////////////////////////////////////////////////////////////////

} // namespace JsonSirup
