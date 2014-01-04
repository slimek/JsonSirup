// JsonSirup C++ JSON Library - JSON Value Header

#ifndef __JSON_SIRUP_JSON_VALUE_H
#define __JSON_SIRUP_JSON_VALUE_H
#pragma once

#include <JsonSirup/Forwards.h>
#include <memory>
#include <string>


namespace JsonSirup
{

/** \brief Type of the value held by a JsonValue object.
 */
enum ValueType : int
{
    VALUE_NULL    = 0,  ///< 'null' value
    VALUE_BOOLEAN = 1,  ///< bool value
    VALUE_NUMBER  = 2,  ///< number value in double type
    VALUE_STRING  = 3,  ///< UTF-8 string value
    VALUE_ARRAY   = 4,  ///< array value (ordered list)
    VALUE_OBJECT  = 5,  ///< object value (collection of name/value pairs)
};


/** \brief Represents a <a HREF="http://www.json.org">JSON</a> value.
 */
class JsonValue
{
public:

    JsonValue();
    JsonValue( bool value );
    JsonValue( int32_t value );
    JsonValue( uint32_t value );
    JsonValue( double value );
    JsonValue( const char* value );
    JsonValue( const std::string& value );
    JsonValue( std::string&& value );

    JsonValue( const JsonValue& other );
    JsonValue( JsonValue&& other );
    virtual ~JsonValue();

    JsonValue& operator=( const JsonValue& other );
    JsonValue& operator=( JsonValue&& other );


    /// Properties ///

    ValueType Type() const;

    bool IsConvertibleToString() const;


    /// Accessors ///

    std::string AsString() const;


private:

    std::shared_ptr< JsonNode > m_node;
};

} // namespace JsonSirup

#endif // __JSON_SIRUP_JSON_VALUE_H
