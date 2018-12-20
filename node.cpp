#include "node.h"

Node::Node() {}

bool Node::Evaluate(const Date &date, const string &event) const
{
    return true;
}

DateComparisonNode::DateComparisonNode(const Comparison &cmp, const Date &date)
    : cmp_(cmp), date_(date) {}
bool DateComparisonNode::Evaluate(const Date &date, const string &event) const
{
    switch (cmp_)
    {
    case Comparison::Equal:
    {
        return date == date_;
    }
    case Comparison::NotEqual:
    {
        return !(date == date_);
    }
    case Comparison::GreaterOrEqual:
    {
        return date >= date_;
    }
    case Comparison::LessOrEqual:
    {
        return date <= date_;
    }
    case Comparison::Less:
    {
        return date < date_;
    }
    case Comparison::Greater:
    {
        return date > date_;
    }
    default:
        return false;
    }
}

EmptyNode::EmptyNode() {}
bool EmptyNode::Evaluate(const Date &date, const string &event) const
{
    return true;
}

EventComparisonNode::EventComparisonNode(const Comparison &cmp, const string &event)
    : cmp_(cmp), event_(event) {}
bool EventComparisonNode::Evaluate(const Date &date, const string &event) const
{

    switch (cmp_)
    {
    case Comparison::Equal:
    {
        return event == event_;
    }
    case Comparison::NotEqual:
    {
        return !(event == event_);
    }
    case Comparison::GreaterOrEqual:
    {
        return event >= event_;
    }
    case Comparison::LessOrEqual:
    {
        return event <= event_;
    }
    case Comparison::Less:
    {
        return event < event_;
    }
    case Comparison::Greater:
    {
        return event > event_;
    }
    default:
        return false;
    }
}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation &logical_op, const shared_ptr<Node> &left, const shared_ptr<Node> &right)
    : logical_operation(logical_op), _left(left), _right(right) {}

bool LogicalOperationNode::Evaluate(const Date &date, const string &event) const
{
    switch (logical_operation)
    {
    case LogicalOperation::And:
    {
        return ((_left->Evaluate(date, event) && _right->Evaluate(date, event)));
    }
    case LogicalOperation::Or:
    {
        return ((_left->Evaluate(date, event) || _right->Evaluate(date, event)));
    }
    }
}
