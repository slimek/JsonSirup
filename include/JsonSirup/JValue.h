// JsonSirup C++ JSON Library - JSON Value Header

#ifndef __JSON_SIRUP_JVALUE_H
#define __JSON_SIRUP_JVALUE_H
#pragma once

#include <JsonSirup/Forwards.h>
#include <JsonSirup/JToken.h>
#include <string>


namespace JsonSirup
{

class JValue : public JToken
{
public:

    JValue();
    JValue( bool value );
    JValue( int32_t value );
    JValue( uint32_t value );
    JValue( double value );
    JValue( const char* value );
    JValue( const std::string& value );
    JValue( std::string&& value );

    JValue( const JValue& other );
    JValue( JValue&& other );
    virtual ~JValue();

    JValue& operator=( const JValue& other );
    JValue& operator=( JValue&& other );


    /// Properties ///

    bool IsConvertibleToString() const;


    /// Accessors ///

    std::string AsString() const;

};

} // namespace JsonSirup

#endif // __JSON_SIRUP_JVALUE_H
