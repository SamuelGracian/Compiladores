#pragma once
#include "list"
#include <string>
#include <map>
#include <memory>

enum class NodeType
{
	Variable,
	Operator,
	Literal
};

class Object
{
public:
	Object () = default;
	virtual ~Object() = default;
};

template <typename T>
class TokenVariable : public Object
{
public:
	TokenVariable() = default;

	void SetValue(T& _val) { value = _val; }

	const std::string& GetName() const { return name; }

	const T& GetValue() const{ return value; }

	std::string name;
	T value;
};

class Node
{
public:
	Node() : m_object (nullptr) {}

	~Node()
	{
		delete m_object;

		for (auto child : m_nodeList) delete child;
	}
	Object* m_object;
	std::list<Node*> m_nodeList;

	symbolTable<std::string> m_symbolTable; 
};

template <typename T>
class symbolTable
{
public:
    void Addvariable(const std::string& name, T value)
    {
        m_table[name] = std::make_unique<TokenVariable<T>>(name, value);
    }

    Object* GetVariable(const std::string& name)
    {
        auto var = m_table.find(name);
        if (var != m_table.end())
        {
            return var->second.get();
        }
        return nullptr;
    }

private:
    std::map<std::string, std::unique_ptr<Object>> m_table;
};