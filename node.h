#pragma once

#include <iostream>
#include <memory>
#include "date.h"
#include "database.h"

using namespace std;

enum class Comparison
{
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual
};

enum class LogicalOperation
{
	Or,
	And
};

class Node
{
public:
	Node();

	virtual bool Evaluate(const Date &date, const string &event) const = 0;
};

class DateComparisonNode : public Node
{
public:
	DateComparisonNode(const Comparison &cmp, const Date &date);

	bool Evaluate(const Date &date, const string &event) const override;

private:
	const Comparison cmp_;
	const Date date_;
};

class EmptyNode : public Node
{
public:
	EmptyNode();
	bool Evaluate(const Date &date, const string &event) const override;
};

class EventComparisonNode : public Node
{
public:
	EventComparisonNode(const Comparison &cmp, const string &event);
	bool Evaluate(const Date &date, const string &event) const override;

private:
	const Comparison cmp_;
	const string event_;
};

class LogicalOperationNode : public Node
{
public:
	LogicalOperationNode(const LogicalOperation &logical_op, const shared_ptr<Node> &left, const shared_ptr<Node> &right);

	bool Evaluate(const Date &date, const string &event) const override;

private:
	const LogicalOperation logical_operation;
	shared_ptr<Node> _left, _right;
};
