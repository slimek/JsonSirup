// JsonSirup C++ JSON Library - JSON Nodes Header

#ifndef __JSON_SIRUP_JSON_NODES_H
#define __JSON_SIRUP_JSON_NODES_H
#pragma once

#include <JsonSirup/Forwards.h>
#include <JsonSirup/JsonValue.h>


namespace JsonSirup
{

///////////////////////////////////////////////////////////////////////////////
//
// JSON Node
// - Abstract base class of all node types
//

class JsonNode
{
public:

    virtual ~JsonNode() {}


    /// Properties ///

    virtual ValueType Type() const = 0;

    virtual bool IsConvertibleToInt32()  const { return false; }
    virtual bool IsConvertibleToUint32() const { return false; }
    virtual bool IsConvertibleToString() const { return false; }


    /// Accessors ///

    virtual std::string AsString() const = 0;
};


///////////////////////////////////////////////////////////////////////////////
//
// JSON Null
//

class JsonNull : public JsonNode
{
public:

    /// Properties ///    

    ValueType Type() const override { return VALUE_NULL; }


    /// Accessors ///

    std::string AsString() const override;
};


///////////////////////////////////////////////////////////////////////////////
//
// JSON Boolean
//

class JsonBoolean : public JsonNode
{
public:

    explicit JsonBoolean( bool value )
        : m_value( value )
    {}


    /// Properties ///

    ValueType Type() const override { return VALUE_BOOLEAN; }

    bool IsConvertibleToInt32()  const override { return true; }
    bool IsConvertibleToUint32() const override { return true; }
    bool IsConvertibleToString() const override { return true; }


    /// Accessors ///

    std::string AsString() const override;


private:

    bool m_value;
};


///////////////////////////////////////////////////////////////////////////////
//
// JSON Number
//

class JsonNumber : public JsonNode
{
public:

    explicit JsonNumber( double value )
        : m_value( value )
    {}


    /// Properties ///

    ValueType Type() const override { return VALUE_NUMBER; }

    bool IsConvertibleToInt32()  const override;
    bool IsConvertibleToUint32() const override;

    bool IsConvertibleToString() const { return true; }


    /// Accessors ///

    std::string AsString() const override;


private:

    double m_value;
};


///////////////////////////////////////////////////////////////////////////////
//
// JSON String
//

class JsonString : public JsonNode
{
public:

    explicit JsonString( const std::string& value )
        : m_value( value )
    {}

    explicit JsonString( std::string&& value )
        : m_value( value )
    {}


    /// Properties ///

    ValueType Type() const override { return VALUE_STRING; }

    bool IsConvertibleToString() const override { return true; }


    /// Accessors ///

    std::string AsString() const override { return m_value; }


private:

    std::string m_value;
};


///////////////////////////////////////////////////////////////////////////////

} // namespace JsonSirup

#endif // __JSON_SIRUP_JSON_NODES_H
