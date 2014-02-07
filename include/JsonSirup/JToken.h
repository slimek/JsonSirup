// JsonSirup C++ JSON Library - JSON Token Header

#ifndef __JSON_SIRUP_JTOKEN_H
#define __JSON_SIRUP_JTOKEN_H
#pragma once

#include <JsonSirup/Forwards.h>
#include <memory>


namespace JsonSirup
{

enum JTokenType : int
{
    JTOKEN_NULL     = 0,  ///< 'null' value
    JTOKEN_BOOL     = 1,  ///< bool value
    JTOKEN_NUMBER   = 2,  ///< number value in double type
    JTOKEN_STRING   = 3,  ///< UTF-8 string value
    JTOKEN_ARRAY    = 4,  ///< array value (ordered list)
    JTOKEN_OBJECT   = 5,  ///< object value (collection of name/value pairs)
};


class JToken
{
public:

    JToken();
    virtual ~JToken();


    /// Properties ///

    JTokenType Type() const;


protected:

    JToken( std::shared_ptr< JNode > node );

    std::shared_ptr< JNode > m_node;
};

} // namespace JsonSirup

#endif // __JSON_SIRUP_JTOKEN_H
