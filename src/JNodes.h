// JsonSirup C++ JSON Library - JSON Nodes Header

#ifndef __JSON_SIRUP_JNODES_H
#define __JSON_SIRUP_JNODES_H
#pragma once

#include <JsonSirup/Forwards.h>
#include <JsonSirup/JValue.h>


namespace JsonSirup
{

///////////////////////////////////////////////////////////////////////////////
//
// JSON Node
// - Abstract base class of all node types
//

class JNode
{
public:

    virtual ~JNode() {}


    /// Properties ///

    virtual JTokenType Type() const = 0;

    virtual bool IsConvertibleToInt32()  const { return false; }
    virtual bool IsConvertibleToUint32() const { return false; }
    virtual bool IsConvertibleToString() const { return false; }


    /// Accessors ///

    virtual std::string AsString() const = 0;
};


///////////////////////////////////////////////////////////////////////////////
//
// JSON Null Node
//

class JNullNode : public JNode
{
public:

    /// Properties ///    

    JTokenType Type() const override { return JTOKEN_NULL; }


    /// Accessors ///

    std::string AsString() const override;
};


///////////////////////////////////////////////////////////////////////////////
//
// JSON Boolean
//

class JBoolNode : public JNode
{
public:

    explicit JBoolNode( bool value )
        : m_value( value )
    {}


    /// Properties ///

    JTokenType Type() const override { return JTOKEN_BOOL; }

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

class JNumberNode : public JNode
{
public:

    explicit JNumberNode( double value )
        : m_value( value )
    {}


    /// Properties ///

    JTokenType Type() const override { return JTOKEN_NUMBER; }

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

class JStringNode : public JNode
{
public:

    explicit JStringNode( const std::string& value )
        : m_value( value )
    {}

    explicit JStringNode( std::string&& value )
        : m_value( std::move( value ))
    {}


    /// Properties ///

    JTokenType Type() const override { return JTOKEN_STRING; }

    bool IsConvertibleToString() const override { return true; }


    /// Accessors ///

    std::string AsString() const override { return m_value; }


private:

    std::string m_value;
};


///////////////////////////////////////////////////////////////////////////////

} // namespace JsonSirup

#endif // __JSON_SIRUP_JNODES_H
